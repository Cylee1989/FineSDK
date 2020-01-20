package com.fine.sdk;

/**
 * Created by Cylee on 2019/4/25.
 */

public interface InterfaceFunc {

    public abstract void initSDK(String str);

    public abstract void login(String str);

    public abstract void pay(String str);

    public abstract void logout(String str);

    public abstract void exit(String str);

    public abstract void enterUserCenter(String str);

    public abstract void showToolBar(String str);

    public abstract void hideToolBar(String str);

}
