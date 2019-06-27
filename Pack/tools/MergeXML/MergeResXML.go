package main

import (
	"encoding/xml"
	"flag"
	"fmt"
	"io/ioutil"
	"os"
	"strings"
)

// XMLResources XML中resources数组
type XMLResources struct {
	XMLName xml.Name    `xml:"resources"`
	Styles  []XMLStyle  `xml:"style"`
	Strings []XMLString `xml:"string"`
}

// XMLString resources数组中的string数组
type XMLString struct {
	XMLName   xml.Name `xml:"string"`
	Name      string   `xml:"name,attr"`
	InnerText string   `xml:",innerxml"`
}

// XMLStyle resources数组中的style数组
type XMLStyle struct {
	XMLName   xml.Name `xml:"style"`
	Name      string   `xml:"name,attr"`
	Parent    string   `xml:"parent,attr,omitempty"`
	InnerText string   `xml:",innerxml"`
}

// TService 服务
type TService struct {
	MainPath     string               // 主XML文件路径
	LinkPaths    string               // 依赖XML文件路径
	OutputPath   string               // 导出XML文件路径
	XMLName      xml.Name             // XML名称
	mapXMLStyle  map[string]XMLStyle  // XML Style属性
	mapXMLString map[string]XMLString // XML String属性
}

func main() {
	mainPath := flag.String("m", "", "This is the main XML files Path.")
	linkPaths := flag.String("l", "", "This is the link XML files Path. Multiple files must be separated by commas.")
	outputPath := flag.String("o", "", "This is the output XML file Path.")
	flag.Parse()

	fmt.Println("MergeResXML Params -m:", *mainPath)
	fmt.Println("MergeResXML Params -l:", *linkPaths)
	fmt.Println("MergeResXML Params -o:", *outputPath)
	if *linkPaths == "" || *outputPath == "" {
		fmt.Println("Please enter the correct parameters!")
		return
	}

	service := &TService{
		MainPath:     *mainPath,
		LinkPaths:    *linkPaths,
		OutputPath:   *outputPath,
		mapXMLStyle:  make(map[string]XMLStyle),
		mapXMLString: make(map[string]XMLString),
	}
	service.loadXMLFile()
}

// 读取XML文件
func (service *TService) loadXMLFile() {
	service.saveXMLFileData(service.MainPath)
	files := strings.Split(service.LinkPaths, ",")
	for index := 0; index < len(files); index++ {
		service.saveXMLFileData(files[index])
	}
	service.mergeXMLFile()
}

// 保存XML文件数据
func (service *TService) saveXMLFileData(path string) {
	if path != "" {
		temp := service.parseXMLFile(path)
		service.XMLName = temp.XMLName
		for _, style := range temp.Styles {
			if service.mapXMLStyle[style.Name].Name == "" {
				service.mapXMLStyle[style.Name] = style
			}
		}
		for _, str := range temp.Strings {
			if service.mapXMLString[str.Name].Name == "" {
				service.mapXMLString[str.Name] = str
			}
		}
	}
}

// 解析XML文件
func (service *TService) parseXMLFile(filePath string) XMLResources {
	rs := XMLResources{}

	fi, err := os.Open(filePath)
	if err != nil {
		return rs
	}
	defer fi.Close()

	fd, err := ioutil.ReadAll(fi)
	if err != nil {
		return rs
	}

	xml.Unmarshal([]byte(fd), &rs)
	return rs
}

// 合并XML文件
func (service *TService) mergeXMLFile() {
	xmlRes := XMLResources{
		XMLName: service.XMLName,
		Styles:  make([]XMLStyle, len(service.mapXMLStyle)),
		Strings: make([]XMLString, len(service.mapXMLString)),
	}

	count := 0
	for _, style := range service.mapXMLStyle {
		xmlRes.Styles[count] = style
		count++
	}
	count = 0
	for _, str := range service.mapXMLString {
		xmlRes.Strings[count] = str
		count++
	}
	service.exportXMLFile(xmlRes)
}

// 导出XML文件
func (service *TService) exportXMLFile(res XMLResources) {
	b, err := xml.MarshalIndent(res, "  ", "    ")
	if err != nil {
		return
	}

	fileName := service.OutputPath
	os.Remove(fileName)
	f, err := os.OpenFile(fileName, os.O_RDWR|os.O_CREATE|os.O_APPEND, 0644)
	if err != nil {
		return
	}
	defer f.Close()
	f.Write([]byte(xml.Header))
	f.Write(b)
	fmt.Println("Merge ResXML Success!")
}
