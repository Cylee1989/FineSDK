releasePath=$1
debugPath=$2

lipo -create $release $debug -output libFineSDK.a
