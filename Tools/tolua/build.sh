#!/bin/bash
#
# Invoked build.xml, overriding the lolua++ property


usage(){
cat << EOF
usage: $0 [options]
OPTIONS:
-h	this help
"If you want to create a LuaXXX.cpp file, please enter the command < ./build.sh XXX >!"

EOF
}

scriptName=$1

if [ ! "$scriptName" ]; then
    usage
    exit 1
fi

chmod +x ./tolua++
./tolua++ -L basic.lua -o Lua${scriptName}.cpp ${scriptName}.pkg