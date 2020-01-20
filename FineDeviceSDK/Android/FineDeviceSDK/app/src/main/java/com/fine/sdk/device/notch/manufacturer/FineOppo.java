package com.fine.sdk.device.notch.manufacturer;

import com.fine.sdk.device.info.FineDeviceInfo;

import android.content.pm.PackageManager;
import android.graphics.Point;

public class FineOppo extends FineManufacturerFather {

	@Override
	public boolean isSupportNotch() {
		PackageManager pm = activity.getPackageManager();
		return pm.hasSystemFeature("com.oppo.feature.screen.heteromorphism");
	}

	@Override
	public boolean isHideNotch() {
		Point pReal = FineDeviceInfo.getRealScreenSize(activity);
		Point pShot = FineDeviceInfo.getShotScreenSize(activity);
		int realSize = pReal.x > pReal.y ? pReal.x : pReal.y;
		int shotSize = pShot.x > pShot.y ? pShot.x : pShot.y;
		int statusBarHeigth = FineDeviceInfo.getStatusBarHeight(activity);
		// 设备分辨率-截图分辨率=状态栏，则代表隐藏刘海
		int off = realSize - shotSize;
		if (off == statusBarHeigth || off == statusBarHeigth + 1
				|| off == statusBarHeigth - 1) {
			return true;
		}
		return false;
	}

	@Override
	public int getNotchWidth() {
		if (isSupportNotch()) {
			return 324;
		}
		return 0;
	}

	@Override
	public int getNotchHeigth() {
		if (isSupportNotch()) {
			return 80;
		}
		return 0;
	}

}
