package main

import (
	"flag"
	"fmt"
	"io/ioutil"
	"strings"
)

// 检测字符串出现的次数
var _TotalAppearCount = 0

func main() {
	dirs := flag.String("d", "", "The file dir to be find. Multiple paths must be separated by commas.")
	findKey := flag.String("k", "", "This string to be find.")
	flag.Parse()

	if *dirs == "" || *findKey == "" {
		fmt.Println("Please enter the correct parameters!")
		return
	}

	listFile(*dirs, *findKey)
	fmt.Println(_TotalAppearCount)
}

func listFile(dir, key string) {
	files, _ := ioutil.ReadDir(dir)
	for _, file := range files {
		filePath := dir + "/" + file.Name()
		if file.IsDir() {
			listFile(filePath, key)
		} else {
			bytes, err := ioutil.ReadFile(filePath)
			if err != nil {
				return
			}
			_TotalAppearCount += strings.Count(string(bytes), key)
		}
	}
}
