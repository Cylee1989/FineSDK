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

// TService 服务
type TService struct {
	MainPath              string
	LinkPaths             string
	OutputPath            string
	ManifestAttr          string
	ApplicationAttr       string
	SupportsScreensAttr   string
	UsesSdkAttr           string
	UsesConfigurationAttr string
	InApplication         map[string]*TokenInfo
	OutApplication        map[string]*TokenInfo
}

// TokenInfo 标签信息
type TokenInfo struct {
	Tag  string // 标签
	Name string // 名称
	Attr string // 属性
	Data string // 内容
}

func main() {
	mainPath := flag.String("m", "", "This is the main XML file Path.")
	linkPaths := flag.String("l", "", "This is the link XML files Path. Multiple files must be separated by commas.")
	outputPath := flag.String("o", "", "This is the output XML file Path.")
	flag.Parse()

	fmt.Println("MergeManifestXML Params -m:", *mainPath)
	fmt.Println("MergeManifestXML Params -l:", *linkPaths)
	fmt.Println("MergeManifestXML Params -o:", *outputPath)
	if *mainPath == "" || *linkPaths == "" || *outputPath == "" {
		fmt.Println("Please enter the correct parameters!")
		return
	}

	service := TService{
		MainPath:       *mainPath,
		LinkPaths:      *linkPaths,
		OutputPath:     *outputPath,
		InApplication:  make(map[string]*TokenInfo),
		OutApplication: make(map[string]*TokenInfo),
	}

	service.readMainXMLInfo()
	service.readMergeXMLInfo(service.MainPath)
	files := strings.Split(service.LinkPaths, ",")
	for index := 0; index < len(files); index++ {
		service.readMergeXMLInfo(files[index])
	}
	service.makeManifestXML()
}

func (service *TService) readMainXMLInfo() {
	content, err := ioutil.ReadFile(service.MainPath)
	if err != nil {
		return
	}

	decoder := xml.NewDecoder(bytes.NewBuffer(content))
	for t, err := decoder.Token(); err == nil; t, err = decoder.Token() {
		switch token := t.(type) {
		case xml.StartElement: // 处理元素开始（标签）
			tokenNameLocal := token.Name.Local
			for _, attr := range token.Attr {
				attrSpace := attr.Name.Space
				attrName := attr.Name.Local
				attrValue := attr.Value

				attr := "android:" + attrName + "=" + "\"" + attrValue + "\" "
				if tokenNameLocal == "manifest" {
					space := attrSpace + ":"
					if attrSpace == "" || attrSpace == "http://schemas.android.com/apk/res/android" {
						space = ""
					}
					service.ManifestAttr += space + attrName + "=" + "\"" + attrValue + "\" "
				} else if tokenNameLocal == "application" {
					service.ApplicationAttr += attr
				} else if tokenNameLocal == "supports-screens" {
					service.SupportsScreensAttr += attr
				} else if tokenNameLocal == "uses-sdk" {
					service.UsesSdkAttr += attr
				} else if tokenNameLocal == "uses-configuration" {
					service.UsesConfigurationAttr += attr
				}
			}
		}
	}
}

func (service *TService) readMergeXMLInfo(path string) {
	content, err := ioutil.ReadFile(path)
	if err != nil {
		return
	}

	tokenNum := 0
	isInApplication := false
	isStart, isEnd := false, false
	tempTokenLocalName := ""
	tempTokenInfo := &TokenInfo{}
	decoder := xml.NewDecoder(bytes.NewBuffer(content))
	for t, err := decoder.Token(); err == nil; t, err = decoder.Token() {
		switch token := t.(type) {
		case xml.StartElement: // 处理元素开始（标签）
			tokenNameLocal := token.Name.Local
			if tokenNameLocal == "manifest" || tokenNameLocal == "application" || tokenNameLocal == "supports-screens" || tokenNameLocal == "uses-sdk" || tokenNameLocal == "uses-configuration" {
				if tokenNameLocal == "application" {
					isInApplication = true
				}
			} else {
				if tokenNum == 0 {
					tempTokenInfo.Tag = tokenNameLocal
					for _, attr := range token.Attr {
						tempTokenInfo.Attr += "android:" + attr.Name.Local + "=" + "\"" + attr.Value + "\" "
						if attr.Name.Local == "name" {
							tempTokenInfo.Name = attr.Value
						}
					}
				} else {
					tempTokenLocalName = tokenNameLocal
					tempTokenInfo.Data += "<" + tokenNameLocal + " "
					for _, attr := range token.Attr {
						tempTokenInfo.Data += "android:" + attr.Name.Local + "=" + "\"" + attr.Value + "\" "
					}
				}
				isStart = true
				tokenNum++
			}
		case xml.EndElement: // 处理元素结束（标签）
			tokenNameLocal := token.Name.Local
			tempTokenLocalName = tokenNameLocal
			if tokenNameLocal == "manifest" || tokenNameLocal == "application" || tokenNameLocal == "supports-screens" || tokenNameLocal == "uses-sdk" || tokenNameLocal == "uses-configuration" {
				if tokenNameLocal == "application" {
					isInApplication = false
				}
			} else {
				isEnd = true
				tokenNum--
			}
		case xml.CharData: // 处理字符数据（这里就是元素的文本）
			if tempTokenInfo.Name != "" {
				if tokenNum == 0 {
					tokenInfo := &TokenInfo{}
					tokenInfo.Tag = tempTokenInfo.Tag
					tokenInfo.Name = tempTokenInfo.Name
					tokenInfo.Attr = tempTokenInfo.Attr
					tokenInfo.Data = tempTokenInfo.Data
					key := tokenInfo.Tag + "_" + tokenInfo.Name
					if isInApplication == true {
						if service.InApplication[key] == nil {
							service.InApplication[key] = tokenInfo
						}
					} else {
						if service.OutApplication[key] == nil {
							service.OutApplication[key] = tokenInfo
						}
					}
					tempTokenInfo.Tag = ""
					tempTokenInfo.Name = ""
					tempTokenInfo.Attr = ""
					tempTokenInfo.Data = ""
				} else {
					if tempTokenInfo.Data != "" {
						if isStart && isEnd {
							tempTokenInfo.Data += "/>\n"
						} else if isStart && !isEnd {
							tempTokenInfo.Data += ">\n"
						} else if !isStart && isEnd {
							tempTokenInfo.Data += "</" + tempTokenLocalName + ">\n"
						}
					}
				}
			}
			isStart, isEnd = false, false
		}
	}
}

func (service *TService) makeManifestXML() {
	content := ""
	// 增加 manifest 标签
	content += "<manifest " + service.ManifestAttr + ">\n"

	// 增加 uses-sdk 标签
	if service.UsesSdkAttr != "" {
		content += "<uses-sdk " + service.UsesSdkAttr + "/>\n"
	}

	// 增加 supports-screens 标签
	if service.SupportsScreensAttr != "" {
		content += "<supports-screens " + service.SupportsScreensAttr + "/>\n"
	}

	// 增加 uses-configuration 标签
	if service.UsesConfigurationAttr != "" {
		content += "<uses-configuration " + service.UsesConfigurationAttr + "/>\n"
	}

	// 增加 application外层 标签
	for _, token := range service.OutApplication {
		content += "<" + token.Tag + " " + token.Attr
		if token.Data == "" {
			content += "/>\n"
		} else {
			content += ">\n"
			content += token.Data
			content += "</" + token.Tag + ">\n"
		}
	}

	// 增加 application 标签
	content += "<application " + service.ApplicationAttr + " >\n"

	// 增加 application内层 标签
	for _, token := range service.InApplication {
		content += "<" + token.Tag + " " + token.Attr
		if token.Data == "" {
			content += "/>\n"
		} else {
			content += ">\n"
			content += token.Data
			content += "</" + token.Tag + ">\n"
		}
	}

	content += "</application>\n"
	content += "</manifest>\n"
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
