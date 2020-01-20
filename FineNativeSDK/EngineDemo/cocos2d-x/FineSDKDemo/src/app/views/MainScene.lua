
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

local info_btns = {
    {text = "初始化", tag = 100},
    {text = "登录", tag = 200},
    {text = "充值", tag = 300},
    {text = "注销", tag = 400},
    {text = "退出", tag = 500}
}

function MainScene:onCreate()
    local s = cc.Director:getInstance():getWinSize()

    local layer = cc.Layer:create()
    layer:addTo(self)

    local menu = cc.Menu:create()
    menu:setPosition(cc.p(s.width/2, 0))
    layer:addChild(menu)

    local function fineSDKLuaCallBack(sender)
        print("fineSDKLuaCallBack:", sender)
    end
  
    local function menuCallbackDisabled(tag)
        if tag == 100 then
            local param = {
                appid="1000",
                appkey="123456789"
            }
            local jsonString = json.encode(param)
            Platform:getInstance():initSDK(jsonString, fineSDKLuaCallBack)
        elseif tag == 200 then
            Platform:getInstance():callUniversalFunction("login", nil)
        elseif tag == 300 then
            local param = {
                money="1",
                type="1"
            }
            local jsonString = json.encode(param)
            Platform:getInstance():callUniversalFunction("pay", jsonString)
        elseif tag == 400 then
            Platform:getInstance():callUniversalFunction("logout", nil)
        elseif tag == 500 then
            Platform:getInstance():callUniversalFunction("exit", nil)
        end
    end

    for i=1, #(info_btns) do
        local lb = cc.LabelTTF:create(info_btns[i].text, "Arial", 40)
        local btn = cc.MenuItemLabel:create(lb)
        btn:registerScriptTapHandler(menuCallbackDisabled)
        btn:setPosition(cc.p(0, s.height-200-i*80))
        btn:setTag(info_btns[i].tag)
        menu:addChild(btn)
    end

end

return MainScene
