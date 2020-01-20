package com.fine.sdk.activity;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.res.AssetFileDescriptor;
import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Color;
import android.media.MediaPlayer;
import android.os.Build;
import android.os.Bundle;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import android.view.animation.AlphaAnimation;
import android.view.animation.Animation;
import android.widget.ImageView;
import android.widget.LinearLayout;

import com.fine.sdk.tools.FineLog;

import java.io.IOException;
import java.io.InputStream;

/**
 * Created by Cylee on 2019/7/3.
 * <p>
 * 闪屏类
 */
public class FineLogoActivity extends Activity {

    private final String PATH_LOGO = "FineSDK/logo/";
    private WindowManager mWindowManager;
    private WindowManager.LayoutParams mLayoutParams;
    private LinearLayout mLinearLayout_logo, mLinearLayout_video;
    private ImageView imageView_logo;
    private SurfaceView surfaceView_logo;
    private int index = 1;

    @SuppressLint("ClickableViewAccessibility")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        requestWindowFeature(Window.FEATURE_NO_TITLE);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);
        int uiOptions = View.SYSTEM_UI_FLAG_LAYOUT_STABLE | View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION | View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN | View.SYSTEM_UI_FLAG_HIDE_NAVIGATION
                | View.SYSTEM_UI_FLAG_FULLSCREEN;
        if (Build.VERSION.SDK_INT >= 21) {
            uiOptions |= View.SYSTEM_UI_FLAG_IMMERSIVE;
        }
        getWindow().getDecorView().setSystemUiVisibility(uiOptions);

        mLayoutParams = new WindowManager.LayoutParams();
        mLayoutParams.flags = WindowManager.LayoutParams.FLAG_FULLSCREEN;
        mLayoutParams.width = WindowManager.LayoutParams.MATCH_PARENT;
        mLayoutParams.height = WindowManager.LayoutParams.MATCH_PARENT;
        mLayoutParams.systemUiVisibility = uiOptions;

        imageView_logo = new ImageView(this);
        mLinearLayout_logo = new LinearLayout(this);
        mLinearLayout_logo.setBackgroundColor(Color.WHITE);
        mLinearLayout_logo.setVisibility(View.GONE);
        mLinearLayout_logo.addView(imageView_logo, mLayoutParams);

        surfaceView_logo = new SurfaceView(this);
        surfaceView_logo.setZOrderMediaOverlay(true);
        surfaceView_logo.setSystemUiVisibility(uiOptions);

        mLinearLayout_video = new LinearLayout(this);
        mLinearLayout_video.setBackgroundColor(Color.WHITE);
        mLinearLayout_video.addView(surfaceView_logo, mLayoutParams);

        mWindowManager = getWindowManager();
        mWindowManager.addView(mLinearLayout_logo, mLayoutParams);

        showLogoView();
    }

    /**
     * 播放闪屏
     */
    public void showLogoView() {
        mLinearLayout_logo.setVisibility(View.VISIBLE);
        showNextLogoAnimationByPNG();
    }

    /**
     * 闪屏结束回调
     */
    public void logoFinishCallBack() {
        mWindowManager.removeView(mLinearLayout_logo);
        finish();
    }


    /**
     * 播放PNG格式闪屏
     */
    private void showNextLogoAnimationByPNG() {
        Bitmap bitmap;
        AssetManager am = getResources().getAssets();
        try {
            InputStream is = am.open(PATH_LOGO + index + ".png");
            bitmap = BitmapFactory.decodeStream(is);
            is.close();
            setImageView(bitmap, ImageView.ScaleType.FIT_XY);
            index++;
            return;
        } catch (IOException e) {
            FineLog.d("FineLogoActivity", "Not found " + index + ".png");
        }

        try {
            InputStream is = am.open(PATH_LOGO + index + "_1.png");
            bitmap = BitmapFactory.decodeStream(is);
            is.close();
            setImageView(bitmap, ImageView.ScaleType.FIT_XY);
            index++;
            return;
        } catch (IOException e) {
            FineLog.d("FineLogoActivity", "Not found " + index + "_1.png");
        }

        try {
            InputStream is = am.open(PATH_LOGO + index + "_2.png");
            bitmap = BitmapFactory.decodeStream(is);
            is.close();
            setImageView(bitmap, ImageView.ScaleType.FIT_CENTER);
            index++;
        } catch (IOException e) {
            FineLog.d("FineLogoActivity", "Not found " + index + "_2.png");
            showNextLogoAnimationByJGP();
        }
    }

    /**
     * 播放JPG格式闪屏
     */
    private void showNextLogoAnimationByJGP() {
        Bitmap bitmap;
        AssetManager am = getResources().getAssets();
        try {
            InputStream is = am.open(PATH_LOGO + index + ".jpg");
            bitmap = BitmapFactory.decodeStream(is);
            is.close();
            setImageView(bitmap, ImageView.ScaleType.FIT_XY);
            index++;
            return;
        } catch (IOException e) {
            FineLog.d("FineLogoActivity", "Not found " + index + ".jpg");
        }

        try {
            InputStream is = am.open(PATH_LOGO + index + "_1.jpg");
            bitmap = BitmapFactory.decodeStream(is);
            is.close();
            setImageView(bitmap, ImageView.ScaleType.FIT_XY);
            index++;
            return;
        } catch (IOException e) {
            FineLog.d("FineLogoActivity", "Not found " + index + "_1.jpg");
        }

        try {
            InputStream is = am.open(PATH_LOGO + index + "_2.jpg");
            bitmap = BitmapFactory.decodeStream(is);
            is.close();
            setImageView(bitmap, ImageView.ScaleType.FIT_CENTER);
            index++;
        } catch (IOException e) {
            FineLog.d("FineLogoActivity", "Not found " + index + "_2.jpg");
            showNextLogoAnimationByVideo();
        }
    }

    /**
     * 播放MP4格式闪屏
     */
    private void showNextLogoAnimationByVideo() {
        try {
            AssetFileDescriptor fileDescriptor = getAssets().openFd(PATH_LOGO + index + ".mp4");
            mLinearLayout_logo.setVisibility(View.GONE);
            mWindowManager.addView(mLinearLayout_video, mLayoutParams);
            final MediaPlayer videoPlayer = new MediaPlayer();
            SurfaceHolder holder = surfaceView_logo.getHolder();
            holder.addCallback(new SurfaceHolder.Callback() {
                @Override
                public void surfaceDestroyed(SurfaceHolder holder) {
                    holder.removeCallback(this);
                }

                @Override
                public void surfaceCreated(SurfaceHolder holder) {
                    videoPlayer.setDisplay(holder);
                    videoPlayer.prepareAsync();
                }

                @Override
                public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
                }
            });

            videoPlayer.reset();
            videoPlayer.setOnPreparedListener(new MediaPlayer.OnPreparedListener() {
                @Override
                public void onPrepared(MediaPlayer player) {
                    player.start();
                }
            });
            videoPlayer.setOnErrorListener(new MediaPlayer.OnErrorListener() {
                @Override
                public boolean onError(MediaPlayer player, int whatError, int extra) {
                    logoFinishCallBack();
                    return true;
                }
            });

            videoPlayer.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                @Override
                public void onCompletion(MediaPlayer player) {
                    mWindowManager.removeView(mLinearLayout_video);
                    if (player != null) {
                        player.release();
                    }
                    showLogoView();
                }
            });
            videoPlayer.setDataSource(fileDescriptor.getFileDescriptor(), fileDescriptor.getStartOffset(), fileDescriptor.getLength());
            index++;
        } catch (Exception e) {
            FineLog.d("FineLogoActivity", "Not found " + index + ".mp4");
            logoFinishCallBack();
        }
    }


    /**
     * 设置闪屏图片属性
     *
     * @param bitmap 图片对象
     * @param st     图片拉伸类型
     */
    private void setImageView(Bitmap bitmap, ImageView.ScaleType st) {
        if (bitmap != null) {
            int backgroundColor = bitmap.getPixel(0, 0);
            imageView_logo.setImageBitmap(bitmap);
            imageView_logo.setScaleType(st);
            imageView_logo.startAnimation(logoFadeIn());
            mLinearLayout_logo.setBackgroundColor(backgroundColor);
        }
    }

    /**
     * 淡入效果
     *
     * @return Animation
     */
    private Animation logoFadeIn() {
        AlphaAnimation alphaAnimation = new AlphaAnimation(0.0f, 1.0f);
        alphaAnimation.setDuration(900);
        alphaAnimation.setAnimationListener(new Animation.AnimationListener() {

            @Override
            public void onAnimationStart(Animation animation) {
            }

            @Override
            public void onAnimationRepeat(Animation animation) {
            }

            @Override
            public void onAnimationEnd(Animation animation) {
                imageView_logo.startAnimation(logoRetain());
            }
        });

        return alphaAnimation;
    }

    /**
     * 保持效果
     *
     * @return Animation
     */
    private Animation logoRetain() {
        AlphaAnimation alphaAnimation = new AlphaAnimation(1.0f, 1.0f);
        alphaAnimation.setDuration(1200);
        alphaAnimation.setAnimationListener(new Animation.AnimationListener() {

            @Override
            public void onAnimationStart(Animation animation) {
            }

            @Override
            public void onAnimationRepeat(Animation animation) {
            }

            @Override
            public void onAnimationEnd(Animation animation) {
                imageView_logo.startAnimation(logoFadeOut());
            }
        });
        return alphaAnimation;
    }

    /**
     * 淡出效果
     *
     * @return Animation
     */
    private Animation logoFadeOut() {
        AlphaAnimation alphaAnimation = new AlphaAnimation(1.0f, 0.0f);
        alphaAnimation.setDuration(900);
        alphaAnimation.setAnimationListener(new Animation.AnimationListener() {

            @Override
            public void onAnimationStart(Animation animation) {
            }

            @Override
            public void onAnimationRepeat(Animation animation) {
            }

            @Override
            public void onAnimationEnd(Animation animation) {
                showNextLogoAnimationByPNG();
            }
        });
        return alphaAnimation;
    }

}
