package main

import (
	"bytes"
	"encoding/xml"
	"flag"
	"fmt"
	"image/png"
	"io/ioutil"
	"os"
	"strings"

	"github.com/nfnt/resize"
)

// TService 服务
type TService struct {
	ConfigXMLPath          string
	IconPath               string
	MainManifestXMLPath    string
	ReplaceManifestXMLPath string
	ResXMLPath             string
	ConfigXML              *TConfig
	ManifestXMLData        *TManifestXMLData
	StringsXMLData         *TStringsXMLData
}

// TConfig fine_config.xml配置文件
type TConfig struct {
	XMLName                    xml.Name       `xml:"FineSDK"`
	AppName                    string         `xml:"AppName"`
	PackageName                string         `xml:"PackageName"`
	ScreenOrientation          string         `xml:"ScreenOrientation"`
	LaunchMode                 string         `xml:"LaunchMode"`
	LaunchIntent               *TLaunchIntent `xml:"LaunchIntent"`
	FixedScreenOrientationList string         `xml:"FixedScreenOrientationList"`
}

// TLaunchIntent fine_config.xml配置文件中LaunchIntent属性
type TLaunchIntent struct {
	XMLName   xml.Name `xml:"LaunchIntent"`
	InnerText string   `xml:",innerxml"`
}

// TManifestXMLData Manifest配置
type TManifestXMLData struct {
	ManifestAttr          string
	ApplicationAttr       string
	SupportsScreensAttr   string
	UsesSdkAttr           string
	UsesConfigurationAttr string
	LaunchActivityName    string
	IconName              string
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

// TStringsXMLData strings.xml属性
type TStringsXMLData struct {
	Data  string
	Names map[string]bool
}

func main() {
	configXMLPath := flag.String("c", "", "This is the AndroidManifest XML files Path.")
	iconPath := flag.String("i", "", "This is the Icon files Path.")
	mainManifestXMLPath := flag.String("m", "", "This is the Main AndroidManifest XML files Path.")
	replaceManifestXMLPath := flag.String("r", "", "This is the replace AndroidManifest XML files Path.")
	resXMLPath := flag.String("s", "", "This is the Res files Path.")
	flag.Parse()

	fmt.Println("MergeResXML Params -c:", *configXMLPath)
	fmt.Println("MergeResXML Params -i:", *iconPath)
	fmt.Println("MergeResXML Params -m:", *mainManifestXMLPath)
	fmt.Println("MergeResXML Params -r:", *replaceManifestXMLPath)
	fmt.Println("MergeResXML Params -s:", *resXMLPath)
	if *configXMLPath == "" || *mainManifestXMLPath == "" || *replaceManifestXMLPath == "" || *resXMLPath == "" || *iconPath == "" {
		fmt.Println("Please enter the correct parameters!")
		return
	}

	service := &TService{
		ConfigXMLPath:          *configXMLPath,
		MainManifestXMLPath:    *mainManifestXMLPath,
		ReplaceManifestXMLPath: *replaceManifestXMLPath,
		ResXMLPath:             *resXMLPath,
		IconPath:               *iconPath,
		ManifestXMLData: &TManifestXMLData{
			InApplication:  make(map[string]*TokenInfo),
			OutApplication: make(map[string]*TokenInfo),
		},
		StringsXMLData: &TStringsXMLData{Data: "", Names: make(map[string]bool)},
	}
	service.loadConfigXML()
}

// 读取fine_config.xml文件
func (service *TService) loadConfigXML() {
	content, err := ioutil.ReadFile(service.ConfigXMLPath)
	if err != nil {
		return
	}
	xml.Unmarshal(content, &service.ConfigXML)
	service.readLaunchActivityName()
}

// 读取 MainManifest.xml 中启动Activity字段
func (service *TService) readLaunchActivityName() {
	content, err := ioutil.ReadFile(service.MainManifestXMLPath)
	if err != nil {
		return
	}

	actName := ""
	decoder := xml.NewDecoder(bytes.NewBuffer(content))
	for t, err := decoder.Token(); err == nil; t, err = decoder.Token() {
		switch token := t.(type) {
		case xml.StartElement: // 处理元素开始（标签）
			tokenNameLocal := token.Name.Local
			for _, attr := range token.Attr {
				attrName := attr.Name.Local
				attrValue := attr.Value
				if tokenNameLocal == "application" && attrName == "icon" {
					temp := strings.Split(attrValue, "/")
					service.ManifestXMLData.IconName = temp[1]
				}
				if tokenNameLocal == "activity" && attrName == "name" {
					actName = attrValue
				}
				if actName != "" && attrValue == "android.intent.category.LAUNCHER" {
					service.ManifestXMLData.LaunchActivityName = actName
				}
			}
		case xml.EndElement:
			tokenNameLocal := token.Name.Local
			if tokenNameLocal == "activity" {
				actName = ""
			}
		}
	}
	service.replaceManifestXMLMainInfo()
	service.replaceStringsXMLInfo()
}

// 替换 AndroidManifest.xml 中信息
func (service *TService) replaceManifestXMLMainInfo() {
	content, err := ioutil.ReadFile(service.ReplaceManifestXMLPath)
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
					if attrName == "package" && service.ConfigXML.PackageName != "" {
						attrValue = service.ConfigXML.PackageName
					}
					service.ManifestXMLData.ManifestAttr += space + attrName + "=" + "\"" + attrValue + "\" "
				} else if tokenNameLocal == "application" {
					service.ManifestXMLData.ApplicationAttr += attr
				} else if tokenNameLocal == "supports-screens" {
					service.ManifestXMLData.SupportsScreensAttr += attr
				} else if tokenNameLocal == "uses-sdk" {
					service.ManifestXMLData.UsesSdkAttr += attr
				} else if tokenNameLocal == "uses-configuration" {
					service.ManifestXMLData.UsesConfigurationAttr += attr
				}
			}
		}
	}

	service.replaceManifestXMLOtherInfo()
}

// 替换 AndroidManifest.xml 中其他信息
func (service *TService) replaceManifestXMLOtherInfo() {
	content, err := ioutil.ReadFile(service.ReplaceManifestXMLPath)
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
					service.replaceTokenInfo(tokenInfo)

					key := tokenInfo.Tag + "_" + tokenInfo.Name
					if isInApplication == true {
						if service.ManifestXMLData.InApplication[key] == nil {
							service.ManifestXMLData.InApplication[key] = tokenInfo
						}
					} else {
						if service.ManifestXMLData.OutApplication[key] == nil {
							service.ManifestXMLData.OutApplication[key] = tokenInfo
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

	service.makeManifestXML()
}

func (service *TService) replaceTokenInfo(tokenInfo *TokenInfo) {
	if tokenInfo.Tag == "activity" {
		// 替换启动Activity资源
		if tokenInfo.Name == service.ManifestXMLData.LaunchActivityName && service.ManifestXMLData.LaunchActivityName != "" {
			// 替换启动模式
			if service.ConfigXML.LaunchMode != "" {
				if strings.Contains(tokenInfo.Attr, "android:launchMode") {
					tokenInfo.Attr = strings.Replace(tokenInfo.Attr, "android:launchMode=\"standard\"", "android:launchMode=\""+service.ConfigXML.LaunchMode+"\"", 1)
					tokenInfo.Attr = strings.Replace(tokenInfo.Attr, "android:launchMode=\"singleTop\"", "android:launchMode=\""+service.ConfigXML.LaunchMode+"\"", 1)
					tokenInfo.Attr = strings.Replace(tokenInfo.Attr, "android:launchMode=\"singleTask\"", "android:launchMode=\""+service.ConfigXML.LaunchMode+"\"", 1)
					tokenInfo.Attr = strings.Replace(tokenInfo.Attr, "android:launchMode=\"singleInstance\"", "android:launchMode=\""+service.ConfigXML.LaunchMode+"\"", 1)
				} else {
					tokenInfo.Attr += "android:launchMode=" + "\"" + service.ConfigXML.LaunchMode + "\" "
				}
			}
			// 替换Intent
			if service.ConfigXML.LaunchIntent != nil && service.ConfigXML.LaunchIntent.InnerText != "" {
				tokenInfo.Data = service.ConfigXML.LaunchIntent.InnerText
			}
		}

		// 替换启动方向
		if strings.Contains(tokenInfo.Attr, "android:screenOrientation") {
			if service.ConfigXML.ScreenOrientation != "" && !strings.Contains(service.ConfigXML.FixedScreenOrientationList, tokenInfo.Name) {
				tokenInfo.Attr = strings.Replace(tokenInfo.Attr, "android:screenOrientation=\"behind\"", "android:screenOrientation=\""+service.ConfigXML.ScreenOrientation+"\"", 1)
				tokenInfo.Attr = strings.Replace(tokenInfo.Attr, "android:screenOrientation=\"portrait\"", "android:screenOrientation=\""+service.ConfigXML.ScreenOrientation+"\"", 1)
				tokenInfo.Attr = strings.Replace(tokenInfo.Attr, "android:screenOrientation=\"landscape\"", "android:screenOrientation=\""+service.ConfigXML.ScreenOrientation+"\"", 1)
				tokenInfo.Attr = strings.Replace(tokenInfo.Attr, "android:screenOrientation=\"sensorPortrait\"", "android:screenOrientation=\""+service.ConfigXML.ScreenOrientation+"\"", 1)
				tokenInfo.Attr = strings.Replace(tokenInfo.Attr, "android:screenOrientation=\"sensorLandscape\"", "android:screenOrientation=\""+service.ConfigXML.ScreenOrientation+"\"", 1)
			}
		}
	}
}

func (service *TService) makeManifestXML() {
	content := ""
	// 增加 manifest 标签
	content += "<manifest " + service.ManifestXMLData.ManifestAttr + ">\n"

	// 增加 uses-sdk 标签
	if service.ManifestXMLData.UsesSdkAttr != "" {
		content += "<uses-sdk " + service.ManifestXMLData.UsesSdkAttr + "/>\n"
	}

	// 增加 supports-screens 标签
	if service.ManifestXMLData.SupportsScreensAttr != "" {
		content += "<supports-screens " + service.ManifestXMLData.SupportsScreensAttr + "/>\n"
	}

	// 增加 uses-configuration 标签
	if service.ManifestXMLData.UsesConfigurationAttr != "" {
		content += "<uses-configuration " + service.ManifestXMLData.UsesConfigurationAttr + "/>\n"
	}

	// 增加 application外层 标签
	for _, token := range service.ManifestXMLData.OutApplication {
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
	content += "<application " + service.ManifestXMLData.ApplicationAttr + " >\n"

	// 增加 application内层 标签
	for _, token := range service.ManifestXMLData.InApplication {
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
	service.saveNewXML(service.ReplaceManifestXMLPath, content)
}

// 替换 strings.xml 中信息
func (service *TService) replaceStringsXMLInfo() {
	content, err := ioutil.ReadFile(service.ResXMLPath + "/values/strings.xml")
	if err != nil {
		return
	}

	isAppName := false
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
					if attr.Name.Local == "name" && !service.StringsXMLData.Names[value] {
						service.StringsXMLData.Names[value] = true
						isSaveData = true
					}
				}
			}
			if isSaveData {
				service.StringsXMLData.Data += "\n<" + tokenNameLocal
				for _, attr := range token.Attr {
					service.StringsXMLData.Data += " " + attr.Name.Local + "=\"" + attr.Value + "\""
					if attr.Value == "app_name" {
						isAppName = true
					}
				}
				service.StringsXMLData.Data += ">"
			}
		case xml.EndElement:
			tokenNameLocal := token.Name.Local
			if isSaveData {
				if tokenNameLocal == "style" || tokenNameLocal == "string" {
					if isHasContent && tokenNameLocal != "string" {
						service.StringsXMLData.Data += "\n"
						isHasContent = false
					}
					isSaveData = false
				}
				service.StringsXMLData.Data += "</" + tokenNameLocal + ">"
			}
		case xml.CharData:
			if isSaveData {
				content := string([]byte(token))
				if strings.TrimSpace(content) != "" {
					if isAppName {
						service.StringsXMLData.Data += service.ConfigXML.AppName
						isAppName = false
					} else {
						service.StringsXMLData.Data += content
					}
					isHasContent = true
				}
			}
		}
	}

	service.makeStringsXML()
}

func (service *TService) makeStringsXML() {
	content := "<resources>"
	content += service.StringsXMLData.Data
	content += "\n</resources>"
	service.saveNewXML(service.ResXMLPath+"/values/strings.xml", content)
}

func (service *TService) saveNewXML(fileName, content string) {
	os.Remove(fileName)
	f, err := os.OpenFile(fileName, os.O_RDWR|os.O_CREATE|os.O_APPEND, 0644)
	if err != nil {
		return
	}
	defer f.Close()
	f.Write([]byte(xml.Header))
	f.Write([]byte(content))
	fmt.Println("Replace XML Success!")
	service.replaceIcon()
}

// 替换新ICON
func (service *TService) replaceIcon() {
	files, _ := ioutil.ReadDir(service.ResXMLPath)
	for _, file := range files {
		filePath := service.ResXMLPath + "/" + file.Name()
		if file.IsDir() {
			if strings.Contains(filePath, "drawable-") || strings.Contains(filePath, "mipmap-") {
				if strings.Contains(filePath, "-ldpi") || strings.Contains(filePath, "-mdpi") {
					service.makeIconFile(filePath, 48)
				} else if strings.Contains(filePath, "-hdpi") {
					service.makeIconFile(filePath, 72)
				} else if strings.Contains(filePath, "-xhdpi") {
					service.makeIconFile(filePath, 96)
				} else if strings.Contains(filePath, "-xxhdpi") {
					service.makeIconFile(filePath, 144)
				} else if strings.Contains(filePath, "-xxxhdpi") {
					service.makeIconFile(filePath, 196)
				}
			}
		}
	}
}

// 生成新ICON
func (service *TService) makeIconFile(path string, size uint) error {
	file, err := os.Open(service.IconPath)
	if err != nil {
		return err
	}
	defer file.Close()

	img, err := png.Decode(file)
	if err != nil {
		fmt.Println("Icon Make Failed: \n" + err.Error())
		return err
	}

	imgOut := resize.Resize(size, 0, img, resize.Lanczos3)
	out, err := os.Create(path + "/" + service.ManifestXMLData.IconName + ".png")
	if err != nil {
		fmt.Println("Icon Make Failed: \n" + err.Error())
		return err
	}
	defer out.Close()

	png.Encode(out, imgOut)
	return nil
}
