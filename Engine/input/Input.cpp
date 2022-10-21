#include "Input.h"
#include <cassert>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

Input* Input::GetInstacne()
{
    static Input instacne;

    return &instacne;
}

BOOL Input::DeviceFindCallBack(LPCDIDEVICEINSTANCE ipddi, LPVOID pvRef)
{
    return DIENUM_CONTINUE;
}

bool Input::Initialize(WinApp* winApp)
{
    HRESULT result = S_FALSE;

    assert(winApp);
    assert(!dinput);

    this->winApp = winApp;

    // DirectInputオブジェクトの生成	
    result = DirectInput8Create(winApp->GetInstance(), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&dinput, nullptr);
    if (FAILED(result)) {
        assert(0);
        return result;
    }

    // キーボードデバイスの生成	
    result = dinput->CreateDevice(GUID_SysKeyboard, &devKeyBoard, NULL);
    if (FAILED(result)) {
        assert(0);
        return result;
    }

    // デバイスの列挙
    result = dinput->EnumDevices(DI8DEVTYPE_JOYSTICK, DeviceFindCallBack, NULL, DIEDFL_ATTACHEDONLY);
    if (FAILED(result)) {
        assert(0);
        return result;
    }

    // ゲームパッドデバイスの生成
    result = dinput->CreateDevice(GUID_Joystick, &devPad, NULL);

    // 入力データ形式のセット
    result = devKeyBoard->SetDataFormat(&c_dfDIKeyboard); // 標準形式
    if (FAILED(result)) {
        assert(0);
        return result;
    }

    // 排他制御レベルのセット
    result = devKeyBoard->SetCooperativeLevel(this->winApp->GetHwnd(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
    if (FAILED(result)) {
        assert(0);
        return result;
    }

    // デバイスのフォーマットの設定
    if (devPad != nullptr)
    {
        result = PadInitialize(this->winApp->GetHwnd());
        if (FAILED(result)) {
            assert(0);
            return result;
        }
    }

    return true;
}

void Input::Updata()
{

    HRESULT result;

    //前回のキー入力を保存
    memcpy(keyPre, key, sizeof(key));

    //キーボード情報の取得開始
    result = devKeyBoard->Acquire();

    //全キーの入力情報を取得する
    result = devKeyBoard->GetDeviceState(sizeof(key), key);

    // コントローラーがゲーム中に接続した際の処理
    if (devPad == nullptr)
    {
        result = InterruptInitialize(result);
    }

    // コントローラーが接続状態である場合
    if (devPad != nullptr)
    {
        // ゲームパッド
        result = devPad->Acquire();

        // 前回の入力を保存
        padStatePre = padState;

        // ゲームパッドの入力
        result = devPad->GetDeviceState(sizeof(padState), &padState);

        devPad->Poll();
    }
}

bool Input::PushKey(BYTE keyNumber)
{
    //指定キーを押していればtrueを返す
    if (key[keyNumber])
    {
        return true;
    }

    //そうでなければfalseを返す
    return false;
}

bool Input::TriggerKey(BYTE keyNumber)
{
    //指定キーを押していればtrueを返す
    if (key[keyNumber] && !keyPre[keyNumber])
    {
        return true;
    }

    //そうでなければfalseを返す
    return false;
}

bool Input::AwayKey(BYTE keyNumber)
{
    //指定キーを押していればtrueを返す
    if (!key[keyNumber] && keyPre[keyNumber])
    {
        return true;
    }

    //そうでなければfalseを返す
    return false;
}

bool Input::PushMoveKey()
{
     //指定キーを押していればtrueを返す
    if (key[DIK_W] || key[DIK_A] || key[DIK_S] || key[DIK_D])
    {
        return true;
    }

    //そうでなければfalseを返す
    return false;
}

bool Input::PushButton(unsigned int buttonNumber)
{
    // 異常な引数を検出
    assert(0 <= buttonNumber && buttonNumber < 9);

    if (padState.rgbButtons[buttonNumber] != 0)
    {
        return true;
    }

    return false;
}

bool Input::PushKeepButton(unsigned int buttonNumber)
{
    // 異常な引数を検出
    assert(0 <= buttonNumber && buttonNumber <= 9);

    if (padStatePre.rgbButtons[buttonNumber] != 0 &&
        padState.rgbButtons[buttonNumber] != 0)
    {
        return true;
    }

    return false;
}

bool Input::TiltLeftStick(unsigned int stickNumber)
{
    // 異常な引数を検出
    assert(0 <= stickNumber && stickNumber <= 3);

    if (devPad != nullptr)
    {
        if (stickNumber == StickLeft)
        {
            if (padState.lX < -500) { return true; }
        }

        if (stickNumber == StickRight)
        {
            if (padState.lX > +500) { return true; }
        }

        if (stickNumber == StickUp)
        {
            if (padState.lY < -500) { return true; }
        }

        if (stickNumber == StickDown)
        {
            if (padState.lY > +500) { return true; }
        }
    }
    return false;
}

bool Input::TiltRightStick(unsigned int stickNumber)
{
    // 異常な引数を検出
    assert(0 <= stickNumber && stickNumber <= 3);

    if (devPad != nullptr)
    {
        // スティックナンバーがLeftの場合
        if (stickNumber == StickLeft)
        {
            if (padState.lRx < -500) { return true; }
        }
        // スティックナンバーがRightの場合
        if (stickNumber == StickRight)
        {
            if (padState.lRx > +500) { return true; }
        }
        // スティックナンバーがUpの場合
        if (stickNumber == StickUp)
        {
            if (padState.lRy < -500) { return true; }
        }
        // スティックナンバーがDownの場合
        if (stickNumber == StickDown)
        {
            if (padState.lRy > +500) { return true; }
        }
    }

    return false;
}

bool Input::PadInitialize(HWND hwnd)
{
    HRESULT result = S_FALSE;

    // 入力データ形式のセット
    result = devPad->SetDataFormat(&c_dfDIJoystick2);
    if (FAILED(result)) {
        assert(0);
        return result;
    }

    // 軸モードを絶対値モードとして設定
    DIPROPDWORD diprop;
    ZeroMemory(&diprop, sizeof(diprop));
    diprop.diph.dwSize = sizeof(diprop);
    diprop.diph.dwHeaderSize = sizeof(diprop.diph);
    diprop.diph.dwHow = DIPH_DEVICE;
    diprop.diph.dwObj = 0;
    diprop.dwData = DIPROPAXISMODE_ABS;	// 絶対値モードの指定(DIPROPAXISMODE_RELにしたら相対値

    result = devPad->SetProperty(DIPROP_AXISMODE, &diprop.diph);
    if (FAILED(result)) {
        assert(0);
        return result;
    }

    // X軸の値の範囲設定
    DIPROPRANGE diprg;
    ZeroMemory(&diprg, sizeof(diprg));
    diprg.diph.dwSize = sizeof(diprg);
    diprg.diph.dwHeaderSize = sizeof(diprg.diph);
    diprg.diph.dwHow = DIPH_BYOFFSET;
    diprg.diph.dwObj = DIJOFS_X;
    diprg.lMin = -1000;
    diprg.lMax = 1000;
    result = devPad->SetProperty(DIPROP_RANGE, &diprg.diph);
    if (FAILED(result)) {
        assert(0);
        return result;
    }
    diprg.diph.dwObj = DIJOFS_RX;
    result = devPad->SetProperty(DIPROP_RANGE, &diprg.diph);
    if (FAILED(result)) {
        assert(0);
        return result;
    }

    // Y軸の値の範囲設定
    diprg.diph.dwObj = DIJOFS_Y;
    result = devPad->SetProperty(DIPROP_RANGE, &diprg.diph);
    if (FAILED(result)) {
        assert(0);
        return result;
    }
    diprg.diph.dwObj = DIJOFS_RY;
    result = devPad->SetProperty(DIPROP_RANGE, &diprg.diph);
    if (FAILED(result)) {
        assert(0);
        return result;
    }


    // 排他制御レベルのセット
    result = devPad->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
    if (FAILED(result)) {
        assert(0);
        return result;
    }


    return result;
}

bool Input::InterruptInitialize(HRESULT result)
{
    // ゲームパッドデバイスの生成
    result = dinput->CreateDevice(GUID_Joystick, &devPad, NULL);

    // デバイスのフォーマットの設定
    if (devPad != nullptr)
    {
        result = PadInitialize(this->winApp->GetHwnd());
    }

    return result;
}

bool Input::CheckPad()
{
    if (devPad != nullptr)
    {
        return true;
    }
    
    return false;
}
