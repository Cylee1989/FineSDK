#!/bin/sh

curPath=$(cd "$(dirname "$0")"; pwd) #工作目录的绝对路径

apkPath=
game=
platform=
channel=

usage(){
	echo "打包脚本，参数如下 。"
	echo "－a: APK的文件路径。"
	echo "－g: 游戏标识。"
	echo "－p: 渠道标识。"
	echo "－c: 媒介标识"
}

while getopts "a:g:p:c:" arg
do
	case $arg in
		a)
			apkPath=$OPTARG
			echo "APK路径=$apkPath"
			;;
		g)
			game=$OPTARG
			echo "游戏=$game"
			;;
		p)
			platform=$OPTARG
			echo "渠道=$platform"
			;;
		c)
			channel=$OPTARG
			echo "媒介=$channel"
			;;
		\?)
			usage
			echo "unknown argument"
			;;
	esac
done

if [[ -z $apkPath ]]; then
	echo "error: apkPath is null, please input right apkPath"
	usage
	exit 1
fi

if [[ -z $game ]]; then
	echo "error: game name is null, please input right game name"
	usage
	exit 1
fi

if [[ -z $platform ]]; then
	echo "error: platform is null, please input right platform"
	usage
	exit 1	
fi

echo "----------------------------------------------------------------------------------------------------"
echo "设定工作环境"
sdkProjPath="$curPath/../plugins/android/$platform"
gameConfigPath="$curPath/../config/$game"
if [ ! -d "$sdkProjPath" -o ! -d "$gameConfigPath/$platform" ]; then
	echo "不存在游戏[$game] 渠道[$platform]项目工程"
	exit 1
fi

sdkProjPath=$(cd $sdkProjPath; pwd)
gameConfigPath=$(cd $gameConfigPath; pwd)
toolPath="$curPath/bin"
chmod +x "$toolPath/aapt" "$toolPath/apktool" "$toolPath/dx" "$toolPath/aidl" "$toolPath/zipalign" 
androidJar="$toolPath/android/android-26.jar"
goToolsPath="$curPath/Go"

keystore=
if [ -f $gameConfigPath/$platform/fine.store.ini -a -f $gameConfigPath/$platform/fine.store ]; then
	chmod a+x $gameConfigPath/$platform/fine.store.ini
	source $gameConfigPath/$platform/fine.store.ini
	keystore=$gameConfigPath/$platform/fine.store
elif [ -f $gameConfigPath/fine.store.ini -a -f $gameConfigPath/fine.store ]; then
	chmod a+x $gameConfigPath/fine.store.ini
	source $gameConfigPath/fine.store.ini
	keystore=$gameConfigPath/fine.store
else
	echo 不存在fine.store.ini 或 fine.store
	exit 1
fi

if [ -f $gameConfigPath/version.ini ]; then
	chmod a+x $gameConfigPath/version.ini
	source $gameConfigPath/version.ini
else
	echo 不存在version.ini
	exit 1
fi

configXMLPath=
if [ -f $gameConfigPath/$platform/fine_config.xml ]; then
	configXMLPath=$gameConfigPath/$platform/fine_config.xml
else
	echo 不存在fine_config.xml
	exit 1
fi

iconPath=
if [ -f $gameConfigPath/$platform/fine_icon.png ]; then
	iconPath=$gameConfigPath/$platform/fine_icon.png
elif [ -f $gameConfigPath/fine_icon.png ]; then
	iconPath=$gameConfigPath/fine_icon.png
else
	echo 不存在fine_icon.png
	exit 1
fi

echo "sdkProjPath:"$sdkProjPath
echo "gameConfigPath:"$gameConfigPath
echo "keystore:"$keystore
echo "storepass:"$storepass
echo "keyalias:"$keyalias
echo "aliaspass:"$aliaspass
echo "versionName:"$versionName
echo "versionCode:"$versionCode
echo "configXMLPath:"$configXMLPath
echo "iconPath:"$iconPath

echo "----------------------------------------------------------------------------------------------------"
echo "生成build环境目录"
buildDir="$curPath/.build"
if [[ -d $buildDir ]]; then
	rm -rf $buildDir
fi
mkdir $buildDir
buildDir_apk="$buildDir/f_apk"
buildDir_merge="$buildDir/f_merge"
mkdir $buildDir_merge

echo "----------------------------------------------------------------------------------------------------"
echo "解压APK包"
$toolPath/apktool d $apkPath -o $buildDir_apk

echo "----------------------------------------------------------------------------------------------------"
echo "编译渠道工程"
cd $sdkProjPath
gradle clean #assembleRelease

echo "----------------------------------------------------------------------------------------------------"
echo "获取项目所有依赖工程路径"
allTaskPath=()
allTaskCount=1
allTaskFlag="FineSDK-"
touch "$buildDir/build.log"
echo $(gradle allTask) >> "$buildDir/build.log"
allTaskConsole=($(cat "$buildDir/build.log"))
for str in ${allTaskConsole[@]}; do
	if [[ "$str" =~ "$allTaskFlag" ]]; then
		path=${str#*$allTaskFlag}
		if [[ "$path" != "$sdkProjPath" ]]; then
			allTaskPath[$allTaskCount]=$path
			echo "Module Path: ${allTaskPath[$allTaskCount]}"
			allTaskCount=`expr $allTaskCount + 1`
		fi
	fi
done

echo "----------------------------------------------------------------------------------------------------"
echo "合并资源，编译工程R.java文件"
merge_res="$buildDir_merge/res"
mkdir $merge_res
merge_lib="$buildDir_merge/lib"
mkdir $merge_lib
merge_src="$buildDir_merge/src"
mkdir $merge_src
merge_assets="$buildDir_merge/assets"
merge_assets_FineSDK="$merge_assets/FineSDK"
mkdir $merge_assets $merge_assets_FineSDK
for(( i=${#allTaskPath[@]};i>0;i--)) do
	taskPath=${allTaskPath[i]}
	# copy libs资源
	if [ -d "$taskPath/libs/" ];then
		cp -rf $taskPath/libs/ $merge_lib
	fi

	# copy jniLibs资源
	if [ -d "$taskPath/src/main/jniLibs/" ];then
		cp -rf $taskPath/src/main/jniLibs/ $merge_lib
	fi

	# copy java资源
	if [ -d "$taskPath/src/main/java/" ];then
		cp -rf $taskPath/src/main/java/ $merge_src
	fi

	# copy res资源
	if [ -d "$taskPath/src/main/res/" ];then
		cp -rf $taskPath/src/main/res/ $merge_res
	fi

	# 编译AIDL资源
	aidlPath="$taskPath/src/main/aidl/"
	if [ -d "$aidlPath" ];then
		for path in `find $aidlPath -type d`
		do
			for filePath in `find $path -type f -depth 1`
			do
				filetype=${filePath##*.}
				if [[ "$filetype" == "aidl" ]]; then
					echo "AIDL文件编译:" $filePath
					$toolPath/aidl -p$toolPath/android/framework.aidl -I$taskPath -o$merge_src $filePath
				fi
			done
		done
	fi

	# 编译依赖工程R.java文件
	$toolPath/aapt package -f -m -J $merge_src -S $taskPath/src/main/res -M $taskPath/src/main/AndroidManifest.xml -I $androidJar
done

cp -rf $gameConfigPath/fine_app.json $merge_assets_FineSDK
cp -rf $gameConfigPath/$platform/fine_platform.json $merge_assets_FineSDK
cp -rf $gameConfigPath/$platform/logo $merge_assets_FineSDK

cp -rf $buildDir_apk/res/ $merge_res

echo "----------------------------------------------------------------------------------------------------"
echo "合并XML资源..."
stringsXMLFile=""
stylesXMLFile=""
manifestXMLFile=""
for (( i = 1; i <= ${#allTaskPath[@]}; i++ )); do
	taskPath=${allTaskPath[i]}
	stringsXML="$taskPath/src/main/res/values/strings.xml"
	if [ -f $stringsXML ];then
		if [ "$stringsXMLFile" == "" ];then
			stringsXMLFile=$stringsXML
		else
			stringsXMLFile+=",$stringsXML"
		fi
	fi

	stylesXML="$taskPath/src/main/res/values/styles.xml"
	if [ -f $stylesXML ];then
		if [ "$stylesXMLFile" == "" ];then
			stylesXMLFile=$stylesXML
		else
			stylesXMLFile+=",$stylesXML"
		fi
	fi

	manifestXML="$taskPath/src/main/AndroidManifest.xml"
	if [ -f $manifestXML ];then
		if [ "$manifestXMLFile" == "" ];then
			manifestXMLFile=$manifestXML
		else
			manifestXMLFile+=",$manifestXML"
		fi
	fi

done

if [ ! -d "$merge_res/values" ];then
	mkdir "$merge_res/values"
fi

$goToolsPath/MergeResXML -m "$buildDir_apk/res/values/strings.xml" -l "$stringsXMLFile" -o "$merge_res/values/strings.xml"
$goToolsPath/MergeResXML -m "$buildDir_apk/res/values/styles.xml" -l "$stylesXMLFile" -o "$merge_res/values/styles.xml"
$goToolsPath/MergeManifestXML -m "$buildDir_apk/AndroidManifest.xml" -l "$manifestXMLFile" -o "$buildDir_merge/AndroidManifest.xml"
$goToolsPath/ReplaceXMLAttr -c $configXMLPath -i $iconPath -m "$buildDir_apk/AndroidManifest.xml" -r "$buildDir_merge/AndroidManifest.xml" -s "$merge_res"
$toolPath/aapt package -f -m -J $merge_src -S $merge_res -M $buildDir_merge/AndroidManifest.xml -I $androidJar

echo "----------------------------------------------------------------------------------------------------"
echo "编译Java为Class文件"
merge_class=$buildDir_merge/class
mkdir $merge_class

classPath="$androidJar"
for path in `find $merge_lib -type d`
do
	for filePath in `find $path -type f -depth 1`
	do
	    filetype=${filePath##*.}
	    if [[ "$filetype" == "jar" ]]; then
	    	classPath+=":$filePath"
	    fi
	done
done

javaFiles=""
for path in `find $merge_src -type d`
do
	for filePath in `find $path -type f -depth 1`
	do
	    filetype=${filePath##*.}
	    if [[ "$filetype" == "java" ]]; then
	    	javaFiles+=" $filePath "
	    fi
	done
done

javac -d $merge_class $javaFiles -sourcepath $merge_src -classpath $classPath -encoding UTF-8 -g:none -nowarn -source 1.6 -target 1.6
rm -rf $merge_src

echo "----------------------------------------------------------------------------------------------------"
echo "编译Class为Dex文件"
merge_class_unzip=$buildDir_merge/class_unzip
mkdir $merge_class_unzip
merge_dex=$buildDir_merge/dex
mkdir $merge_dex
for path in `find $merge_lib -type d`
do
	for filePath in `find $path -type f -depth 1`
	do
	    filetype=${filePath##*.}
	    if [[ "$filetype" == "jar" ]]; then
	    	unzip -o -q $filePath -d $merge_class_unzip
	    fi
	done
done
cp -rf $merge_class/ $merge_class_unzip
rm -rf $merge_class
rm -rf $merge_lib/*.jar
rm -rf "$merge_class_unzip/META-INF"

cd $merge_class_unzip
jar cvf all.jar *
$toolPath/dx --dex --output=$merge_dex/classes.dex all.jar
cd -
rm -rf $merge_class_unzip

echo "----------------------------------------------------------------------------------------------------"
echo "编译Dex为Smali文件"
merge_smali=$buildDir_merge/smali
mkdir $merge_smali
java -jar $toolPath/baksmali-2.2.7.jar disassemble -o $merge_smali $merge_dex/classes.dex
rm -rf $merge_dex

echo "----------------------------------------------------------------------------------------------------"
echo "覆盖资源"
cp -rf $merge_assets $buildDir_apk
cp -rf $merge_res $buildDir_apk
cp -rf $merge_lib $buildDir_apk
cp -rf $merge_smali $buildDir_apk
cp -rf $buildDir_merge/AndroidManifest.xml $buildDir_apk

echo "----------------------------------------------------------------------------------------------------"
echo "重打包APK"
rm ~/Library/apktool/framework/1.apk
unSignedAPK=$buildDir/unsigned.apk
find $buildDir_apk -name .DS_Store -exec rm -rf {} \;
$toolPath/apktool b $buildDir_apk -o $unSignedAPK

echo "----------------------------------------------------------------------------------------------------"
echo "签名APK"
unAlignAPKName=$buildDir/unalign.apk
jarsigner -sigfile CERT -digestalg SHA1 -sigalg MD5withRSA -keystore $keystore -storepass $storepass -keypass $aliaspass -signedjar $unAlignAPKName $unSignedAPK $keyalias
if [ ! -f $unAlignAPKName ];then
	echo "签名失败"
	exit 1
else
	rm -rf $unSignedAPK
fi

echo "----------------------------------------------------------------------------------------------------"
echo "字节对齐"
apkFilePath="$curPath/../apk/$(date +%y%m%d)"
if [ ! -d $apkFilePath ]; then
	mkdir -p $apkFilePath
fi
apkFilePath=$(cd $apkFilePath; pwd)
apkFileName="$game"_"$platform"_"$channel"_"$versionName"_"$versionCode"_"$(date +%y%m%d%H%M)".apk

$toolPath/zipalign 4 $unAlignAPKName $apkFilePath/$apkFileName
if [ ! -f $apkFilePath/$apkFileName ];then
	echo "对齐失败"
	exit 1
else
	rm $unAlignAPKName
fi

echo "----------------------------------------------------------------------------------------------------"
echo "打包完成"
rm -rf $buildDir