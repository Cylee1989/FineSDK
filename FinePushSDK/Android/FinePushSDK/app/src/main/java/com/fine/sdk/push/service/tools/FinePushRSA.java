package com.fine.sdk.push.service.tools;

import java.io.ByteArrayOutputStream;
import java.security.KeyFactory;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.spec.PKCS8EncodedKeySpec;
import java.security.spec.X509EncodedKeySpec;

import javax.crypto.Cipher;

import android.util.Base64;

public class FinePushRSA {

	/** Java公钥 */
	public static final String PUBLIC_KEY_STR = "MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQCjub9LQakNmyvKrDlMUtoH6BpdB+kE0yGf+tjEc/14XDUWNohT8piTnRnK1ODXyFggQIf/LIbvgueBTIXrlHeJolkjrqzyLzrYwksn0vklPkVvfLZa+nFk3/aJ1yBwSEteqzyOGChrN2NpxELiOi7IXEUtfl+XLzAAz9gs00cX6wIDAQAB";
	/** Java私钥 */
	public static final String PRIVATE_KEY_STR = "MIICdwIBADANBgkqhkiG9w0BAQEFAASCAmEwggJdAgEAAoGBAKO5v0tBqQ2bK8qsOUxS2gfoGl0H6QTTIZ/62MRz/XhcNRY2iFPymJOdGcrU4NfIWCBAh/8shu+C54FMheuUd4miWSOurPIvOtjCSyfS+SU+RW98tlr6cWTf9onXIHBIS16rPI4YKGs3Y2nEQuI6LshcRS1+X5cvMADP2CzTRxfrAgMBAAECgYEAl9bM5NNZH+g3fbepT/JKiCimQn7yiOnxdjeiTtcvTC9fgGFEn24OOF/rKqOwfg4sRIT0Wx+FaJzjbJN2Y5uGG1/4DuyOnxbkYfZ74su1fZOFFFd2LZBgNO7XuyhFg8H8qwndwlSOzgPLFTt+LTNbg5c2MSLLyn0WfLuDT6YyH/ECQQDOedIElvBoAyQgoUIL/AVQczCYHdoDA7JQn13sdJvvykaF+hRE2Rz3S3AdWrjOcO+lskWwr9ak3WODCsK2yLDzAkEAyv7xaNxzo3XJXh3j4AyBdAINX+dLASaV16lhiQJnBHX4ahjQeRSFVhrk3QmcRVrTyUwJlWbyYqrBT/yJlup7KQJAJC48mwlH/zHttroLNMZot/w3W7B/b1/Kc045yyFz4cT0Lq3vt1DEPqE9eCdZkvM/Sy2+AIQPfLw+n8vW6uin+QJAcBrldVSx5CbrYze8ngIqB8gOXNVeHa+SdvyK6eBSxirkWquDjiqgDFJj7BIfpEmpxnRgooqs94J3qdW8ooSyKQJBAImjNKwd//7MMFK+R46TrZqk356l/MMQ2tPKR2BOG3K7j26+7xLsrUK1IndskBAF1H9OrijafDLGbCqHUrNBi8o=";
	/** Go公钥 */
	public static final String PUBLIC_KEY_STR_GO = "MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQDFa7acgR3UwlG8qks6Jx81K1ezLwtqpyp4os0cwfAvJeigSElgrBgE/Gi0Z81qbpBI9C9MifiF7bk9lRfQnmmhSMWhtxkAjxi/ttlQiCYgynW/rH2Fa5mLP2EHkb+aHFQMTcKKiuUt0jtpr/qyM8gXvUwRXjUYWRC6Cnx+RzqgTQIDAQAB";

	/**
	 * RSA最大加密明文大小
	 */
	private static final int MAX_ENCRYPT_BLOCK = 117;

	/**
	 * RSA最大解密密文大小
	 */
	private static final int MAX_DECRYPT_BLOCK = 128;

	/**
	 * 将base64编码后的公钥字符串转成PublicKey实例
	 * 
	 * @param publicKey
	 *            公钥字符串
	 * @throws Exception
	 *             exception
	 */
	private static PublicKey getPublicKey(String publicKey) throws Exception {
		byte[] keyBytes = Base64.decode(publicKey, Base64.DEFAULT);
		X509EncodedKeySpec keySpec = new X509EncodedKeySpec(keyBytes);
		KeyFactory keyFactory = KeyFactory.getInstance("RSA");
		return keyFactory.generatePublic(keySpec);
	}

	/**
	 * 将base64编码后的私钥字符串转成PrivateKey实例
	 * 
	 * @param privateKey
	 *            私钥字符串
	 * @throws Exception
	 *             exception
	 */
	private static PrivateKey getPrivateKey(String privateKey) throws Exception {
		byte[] keyBytes = Base64.decode(privateKey, Base64.DEFAULT);
		PKCS8EncodedKeySpec keySpec = new PKCS8EncodedKeySpec(keyBytes);
		KeyFactory keyFactory = KeyFactory.getInstance("RSA");
		return keyFactory.generatePrivate(keySpec);
	}

	/**
	 * RSA加密
	 * 
	 * @param content
	 *            待加密文本
	 * @param pubKey
	 *            公钥字符串
	 * @return 密文
	 * @throws Exception
	 *             exception
	 */
	public static String encrypt(String content, String pubKey) throws Exception {
		PublicKey publicKey = getPublicKey(pubKey);

		Cipher cipher = Cipher.getInstance("RSA/ECB/PKCS1Padding");// java默认"RSA"="RSA/ECB/PKCS1Padding"
		cipher.init(Cipher.ENCRYPT_MODE, publicKey);
		byte[] data = content.getBytes();
		int inputLen = data.length;
		ByteArrayOutputStream out = new ByteArrayOutputStream();
		int offSet = 0;
		byte[] cache;
		int i = 0;
		// 对数据分段加密
		while (inputLen - offSet > 0) {
			if (inputLen - offSet > MAX_ENCRYPT_BLOCK) {
				cache = cipher.doFinal(data, offSet, MAX_ENCRYPT_BLOCK);
			} else {
				cache = cipher.doFinal(data, offSet, inputLen - offSet);
			}
			out.write(cache, 0, cache.length);
			i++;
			offSet = i * MAX_ENCRYPT_BLOCK;
		}
		byte[] encryptedData = out.toByteArray();
		out.close();
		return Base64.encodeToString(encryptedData, Base64.DEFAULT);
	}

	/**
	 * RSA解密
	 * 
	 * @param content
	 *            密文
	 * @param priKey
	 *            私钥字符串
	 * @return 明文
	 * @throws Exception
	 *             exception
	 */
	public static String decrypt(String content, String priKey) throws Exception {
		PrivateKey privateKey = getPrivateKey(priKey);

		Cipher cipher = Cipher.getInstance("RSA/ECB/PKCS1Padding");
		cipher.init(Cipher.DECRYPT_MODE, privateKey);
		byte[] encryptedData = Base64.decode(content, Base64.DEFAULT);
		int inputLen = encryptedData.length;
		ByteArrayOutputStream out = new ByteArrayOutputStream();
		int offSet = 0;
		byte[] cache;
		int i = 0;
		// 对数据分段解密
		while (inputLen - offSet > 0) {
			if (inputLen - offSet > MAX_DECRYPT_BLOCK) {
				cache = cipher.doFinal(encryptedData, offSet, MAX_DECRYPT_BLOCK);
			} else {
				cache = cipher.doFinal(encryptedData, offSet, inputLen - offSet);
			}
			out.write(cache, 0, cache.length);
			i++;
			offSet = i * MAX_DECRYPT_BLOCK;
		}
		byte[] decryptedData = out.toByteArray();
		out.close();
		return new String(decryptedData);
	}

}
