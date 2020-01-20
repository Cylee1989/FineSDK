filepath=$(cd "$(dirname "$0")"; pwd) #工作目录的绝对路径
cd $filepath

$NDK10_Build clean
$NDK10_Build

cd -
exit 0
