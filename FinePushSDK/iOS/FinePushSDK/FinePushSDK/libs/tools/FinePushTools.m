//
//  FinePushTools.m
//  FinePushSDK
//
//  Created by Cylee on 17/12/8.
//  Copyright © 2017年 Cylee. All rights reserved.
//

#import "FinePushTools.h"
#import "FinePushKeychainItemWrapper.h"
#import "sys/utsname.h"
#import <CommonCrypto/CommonCrypto.h>

@implementation FinePushTools

+ (NSString *) getBundleID {
    return [[NSBundle mainBundle] bundleIdentifier];
}

+ (NSString *) getUUID {
    FinePushKeychainItemWrapper *appKeyChainWrapper = [[FinePushKeychainItemWrapper alloc] initWithIdentifier:@"BTUUID" accessGroup:nil];
    NSString * uuid = [appKeyChainWrapper objectForKey:(id)kSecAttrAccount];
    if (uuid == nil || [uuid isEqualToString:@""]) {
        CFUUIDRef uuidRef = CFUUIDCreate(kCFAllocatorDefault);
        uuid = (NSString *) CFBridgingRelease(CFUUIDCreateString (kCFAllocatorDefault, uuidRef));
        [appKeyChainWrapper setObject:uuid forKey:(id)kSecAttrAccount];
    }
    NSLog(@"设备ID[%@]", uuid);
    return uuid;
}

+ (NSString *) getDeviceModel {
    struct utsname systemInfo;
    uname(&systemInfo);
    NSString * deviceModel = [NSString stringWithCString:systemInfo.machine encoding:NSUTF8StringEncoding];
    NSLog(@"设备型号[%@]", deviceModel);
    return deviceModel;
}

+ (NSString *) getSystemVersion {
    return [[UIDevice currentDevice] systemVersion];
}

+ (NSString *) getRSAPublicKey {
    return @"-----BEGIN PUBLIC KEY-----\nMIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQDLsduJA8kmfn0mGM8z5tGVz0vj\nVJHn4txZljEm7kIXOcfVnVmamevKceapRDRP01sQiMf0UBwdkOooI9yLkYfIhBZ3\n2uwb/KnaUgCaJ+S28kaypLp7+vTth4t9Ndfj2TWI4CPJ4UvkonXwJLfgkuXzwG7g\ngBSs5UFZ4A4nzXbkmwIDAQAB\n-----END PUBLIC KEY-----";
}

+ (NSString *) getRSAPrivateKey {
    return @"-----BEGIN PRIVATE KEY-----\nMIICeAIBADANBgkqhkiG9w0BAQEFAASCAmIwggJeAgEAAoGBAMux24kDySZ+fSYY\nzzPm0ZXPS+NUkefi3FmWMSbuQhc5x9WdWZqZ68px5qlENE/TWxCIx/RQHB2Q6igj\n3IuRh8iEFnfa7Bv8qdpSAJon5LbyRrKkunv69O2Hi3011+PZNYjgI8nhS+SidfAk\nt+CS5fPAbuCAFKzlQVngDifNduSbAgMBAAECgYAfAZvhZ2ofKfHy8qPXyrLskvmC\nSUVMfwP7vxkMTAhTcMAyjBkvp251CpGKAo/T9uBNzARj9C3TclOyeIMB281HOthd\nYI+DrnvWD0lIcuPsYu80wLzTLdBF+L8LGnq2SwpHSqLd3g0t69clDqdCUXrKHncq\n6rVg6PnUwl73ZfrIAQJBAPbniRblip6gghH1EGzQraFtHNJvYewxAxbxBPqPURDf\nMmjYQQR11zJECQGtsKIySsuglE5tfVsS31Jd8uiU/BsCQQDTMtPZQCVvSyCJJWlk\nibAK9U7KqDREdqDrPV+OsDny0XQbeU1N3836BYlf5qWN0y7GYG45clUmi1RC3bx3\nM0GBAkEAsy2DxyH9XvCMdAusR8uItcVBTVWXcph+7X8rZcnrwpq3Mm79gAckjE3j\nW1x4+rwUm4GFHwVGG3mup0+WoEK+UQJBAJmBLf2P5CWaQ1GrgYjzkqLEXbpqu2Kv\nnpKcjyHU8KmOl4eIiSl66+k3sPulVttYjXzehf73HPDhACOBqwQwmwECQQDYW3XG\nZ4d4DiEwivHHqJUD3ispdydgrVWXJAkwhekmEcKghkCheEPm+SJXBH1ElEBgfTaJ\nn5QPfVCLUiulU7hO\n-----END PRIVATE KEY-----";
}

+ (NSString *) getRSAPublicKeyByGo {
    return @"-----BEGIN PUBLIC KEY-----\nMIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQDFa7acgR3UwlG8qks6Jx81K1ez\nLwtqpyp4os0cwfAvJeigSElgrBgE/Gi0Z81qbpBI9C9MifiF7bk9lRfQnmmhSMWh\ntxkAjxi/ttlQiCYgynW/rH2Fa5mLP2EHkb+aHFQMTcKKiuUt0jtpr/qyM8gXvUwR\nXjUYWRC6Cnx+RzqgTQIDAQAB\n-----END PUBLIC KEY-----";
}

+ (NSString *) getMD5:(NSString *)str {
    if (!str) return nil;
    
    const char *cStr = str.UTF8String;
    unsigned char result[CC_MD5_DIGEST_LENGTH];
    CC_MD5(cStr, (CC_LONG)strlen(cStr), result);
    
    NSMutableString *md5Str = [NSMutableString string];
    for (int i = 0; i < CC_MD5_DIGEST_LENGTH; ++i) {
        [md5Str appendFormat:@"%02x", result[i]];
    }
    return md5Str;
}

@end
