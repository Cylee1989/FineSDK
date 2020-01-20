package com.fine.sdk.push.service.udp;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

import org.json.JSONException;
import org.json.JSONObject;

import com.fine.sdk.push.service.db.FinePushRemoteData;
import com.fine.sdk.push.service.tools.FinePushLog;
import com.fine.sdk.push.service.notification.FinePushRemoteNotification;
import com.fine.sdk.push.service.tools.FinePushSharedPreferences;

import android.content.Context;
import android.os.Handler;
import android.os.HandlerThread;
import android.text.TextUtils;

public class UDPClient implements Runnable {

    private static UDPClient instance = new UDPClient();

    public static UDPClient getInstance() {
        return instance;
    }

    private Context mContext;
    private DatagramSocket mClientUDPSocket = null;
    private HandlerThread mSendThread = null;
    private Handler mSendThreadHandler = null;
    private byte readBuffer[] = new byte[2048];
    private int tickTime = 120 * 1000;
    private FinePushRemoteNotification mFinePushRemoteNotification;
    private FinePushRemoteData mRemotePushData = new FinePushRemoteData();

    public void init(Context context, FinePushRemoteNotification finePushRemoteNotification) {
        this.mContext = context;
        this.mFinePushRemoteNotification = finePushRemoteNotification;
        mRemotePushData.read(mContext);
        initThread();
    }

    public void updateRemoteData(FinePushRemoteData udpData) {
        this.mRemotePushData.update(udpData);
        this.mRemotePushData.write(mContext);
        initThread();
    }

    private void initThread() {
        if (!TextUtils.isEmpty(mRemotePushData.getHost()) && mRemotePushData.getPort() > 0) {
            try {
                if (mClientUDPSocket == null) {
                    mClientUDPSocket = new DatagramSocket(mRemotePushData.getPort());
                    new Thread(receiveRunable).start();
                }
                if (mSendThread == null) {
                    mSendThread = new HandlerThread("FinePush-UDP-Thread");
                    mSendThread.start();
                }
                if (mSendThreadHandler == null) {
                    mSendThreadHandler = new Handler(mSendThread.getLooper());
                    mSendThreadHandler.post(this);
                }
            } catch (SocketException e) {
                e.printStackTrace();
            }
        }
    }

    private Runnable receiveRunable = new Runnable() {
        @Override
        public void run() {
            while (mClientUDPSocket != null && !mClientUDPSocket.isClosed()) {
                try {
                    DatagramPacket datagramPacket = new DatagramPacket(readBuffer, readBuffer.length);
                    if (mClientUDPSocket != null)
                        mClientUDPSocket.receive(datagramPacket);

                    int length = datagramPacket.getLength();
                    if (length > 0) {
                        String message = new String(readBuffer, 0, length);
                        FinePushLog.d("UDPClient Receive:" + message);

                        JSONObject json = new JSONObject(message);
                        JSONObject aps = json.optJSONObject("aps");
                        JSONObject ext = json.optJSONObject("ext");
                        if (ext != null) {
                            String receivedID = ext.optString("id");
                            boolean isExist = FinePushSharedPreferences.readBoolean(mContext, receivedID);
                            FinePushLog.d("UDPClient SharedPreferences:" + "[" + receivedID + "]" + isExist);
                            if (!isExist && aps != null) {
                                String alert = aps.optString("alert");
                                String badge = aps.optString("badge");
                                int badgeNumber = 1;
                                if (!TextUtils.isEmpty(badge)) {
                                    badgeNumber = Integer.parseInt(badge);
                                }
                                FinePushSharedPreferences.saveBoolean(mContext, receivedID, true);
                                mFinePushRemoteNotification.show(receivedID, alert, badgeNumber);
                            }
                            sendEvent(receivedID, 1);
                        }
                    }
                } catch (JSONException | IOException e) {
                    e.printStackTrace();
                }
            }
        }
    };

    @Override
    public void run() {
        try {
            if (mClientUDPSocket != null) {
                synchronized (mRemotePushData) {
                    InetAddress address = InetAddress.getByName(mRemotePushData.getHost());
                    String message = mRemotePushData.toString();
                    byte[] sendBuf = message.getBytes();
                    DatagramPacket sendPacket = new DatagramPacket(sendBuf, sendBuf.length, address, mRemotePushData.getPort());
                    mClientUDPSocket.send(sendPacket);
                    FinePushLog.d("UDPClient Send:\n" + message);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        mSendThreadHandler.postDelayed(this, tickTime);
    }

    public void close() {
        if (mClientUDPSocket != null && !mClientUDPSocket.isClosed())
            mClientUDPSocket.close();
        mClientUDPSocket = null;
    }

    public void sendEvent(final String receivedID, final int pushState) {
        new Thread(new Runnable() {

            @Override
            public void run() {
                try {
                    if (mClientUDPSocket != null) {
                        FinePushLog.d("FinePushReceiver SendEvent:" + receivedID + "|" + pushState);
                        synchronized (mRemotePushData) {
                            mRemotePushData.setReceivedID(receivedID);
                            mRemotePushData.setPushState(pushState);
                            InetAddress address = InetAddress.getByName(mRemotePushData.getHost());
                            String message = mRemotePushData.toString();
                            byte[] sendBuf = message.getBytes();
                            DatagramPacket sendPacket = new DatagramPacket(sendBuf, sendBuf.length, address, mRemotePushData.getPort());
                            mClientUDPSocket.send(sendPacket);
                            FinePushLog.d("UDPClient Reply:\n" + message);
                        }
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }).start();
    }

}
