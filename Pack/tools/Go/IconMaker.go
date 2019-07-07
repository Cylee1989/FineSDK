package main

import (
	"flag"
	"fmt"
	"image"
	"image/jpeg"
	"image/png"
	"os"
	"path"
	"strconv"

	"github.com/nfnt/resize"
)

var _Service *TService
var iconSizes = []int{48, 72, 96, 144}

// TService 服务
type TService struct {
	SavePath  string
	FileExt   string
	IconImage image.Image
}

func main() {
	inPath := flag.String("i", "", "The import icon path.")
	outPath := flag.String("o", "", "The export icon path.")
	flag.Parse()
	if *inPath == "" || *outPath == "" {
		fmt.Println("Please enter the correct parameters")
		return
	}

	err := _Service.initService(*inPath, *outPath)
	if err != nil {
		fmt.Println(err.Error())
		return
	}

	_Service.make()
}

func (service *TService) initService(inPath, outPath string) error {
	file, err := os.Open(inPath)
	if err != nil {
		return err
	}
	defer file.Close()

	_Service = &TService{}
	_Service.SavePath = outPath
	_Service.FileExt = path.Ext(inPath)
	switch _Service.FileExt {
	case ".png":
		img, err := png.Decode(file)
		if err != nil {
			return err
		}
		_Service.IconImage = img
		break
	case ".jpg":
		img, err := jpeg.Decode(file)
		if err != nil {
			return err
		}
		_Service.IconImage = img
		break
	}

	service.createSavePath(_Service.SavePath)
	return nil
}

func (service *TService) createSavePath(fileName string) {
	os.RemoveAll(fileName)
	if _, err := os.Stat(fileName); os.IsNotExist(err) {
		os.MkdirAll(fileName, os.ModePerm)
	}
}

func (service *TService) make() {
	for index := 0; index < len(iconSizes); index++ {
		num := strconv.Itoa(iconSizes[index])
		img := resize.Resize(uint(iconSizes[index]), 0, service.IconImage, resize.Lanczos3)
		out, err := os.Create(service.SavePath + "/" + num + service.FileExt)
		if err != nil {
			fmt.Println("Icon Make Failed: \n" + err.Error())
			return
		}
		defer out.Close()
		png.Encode(out, img)
	}
	fmt.Println("Icon Make Success!")
}
