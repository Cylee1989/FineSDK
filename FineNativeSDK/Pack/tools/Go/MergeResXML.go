package main

import (
	"bytes"
	"encoding/xml"
	"flag"
	"fmt"
	"io/ioutil"
	"os"
	"strings"
)

// TXMLData XML属性
type TXMLData struct {
	Data  string
	Names map[string]bool
}

// TService 服务
type TService struct {
	MainPath   string    // 主XML文件路径
	LinkPaths  string    // 依赖XML文件路径
	OutputPath string    // 导出XML文件路径
	XMLData    *TXMLData // XML Style属性
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
		MainPath:   *mainPath,
		LinkPaths:  *linkPaths,
		OutputPath: *outputPath,
		XMLData:    &TXMLData{Data: "", Names: make(map[string]bool)},
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
	service.makeXML()
}

// 保存XML文件数据
func (service *TService) saveXMLFileData(path string) {
	content, err := ioutil.ReadFile(path)
	if err != nil {
		return
	}

	isSaveData := false
	isHasContent := false
	decoder := xml.NewDecoder(bytes.NewBuffer(content))
	for t, err := decoder.Token(); err == nil; t, err = decoder.Token() {
		switch token := t.(type) {
		case xml.StartElement:
			tokenNameLocal := token.Name.Local
			if tokenNameLocal == "style" || tokenNameLocal == "string" {
				for _, attr := range token.Attr {
					value := attr.Value
					if attr.Name.Local == "name" && !service.XMLData.Names[value] {
						service.XMLData.Names[value] = true
						isSaveData = true
					}
				}
			}
			if isSaveData {
				service.XMLData.Data += "\n<" + tokenNameLocal
				for _, attr := range token.Attr {
					service.XMLData.Data += " " + attr.Name.Local + "=\"" + attr.Value + "\""
				}
				service.XMLData.Data += ">"
			}
		case xml.EndElement:
			tokenNameLocal := token.Name.Local
			if isSaveData {
				if tokenNameLocal == "style" || tokenNameLocal == "string" {
					if isHasContent && tokenNameLocal != "string" {
						service.XMLData.Data += "\n"
						isHasContent = false
					}
					isSaveData = false
				}
				service.XMLData.Data += "</" + tokenNameLocal + ">"
			}
		case xml.CharData:
			if isSaveData {
				content := string([]byte(token))
				if strings.TrimSpace(content) != "" {
					service.XMLData.Data += content
					isHasContent = true
				}
			}
		}
	}
}

func (service *TService) makeXML() {
	content := "<resources>"
	content += service.XMLData.Data
	content += "\n</resources>"
	service.saveNewXML(content)
}

func (service *TService) saveNewXML(content string) {
	fileName := service.OutputPath
	os.Remove(fileName)
	f, err := os.OpenFile(fileName, os.O_RDWR|os.O_CREATE|os.O_APPEND, 0644)
	if err != nil {
		return
	}
	defer f.Close()
	f.Write([]byte(xml.Header))
	f.Write([]byte(content))
	fmt.Println("Merge ManifestXML Success!")
}
