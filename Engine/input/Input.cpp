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

    // DirectInput�I�u�W�F�N�g�̐���	
    result = DirectInput8Create(winApp->GetInstance(), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&dinput, nullptr);
    if (FAILED(result)) {
        assert(0);
        return result;
    }

    // �L�[�{�[�h�f�o�C�X�̐���	
    result = dinput->CreateDevice(GUID_SysKeyboard, &devKeyBoard, NULL);
    if (FAILED(result)) {
        assert(0);
        return result;
    }

    // �f�o�C�X�̗�
    result = dinput->EnumDevices(DI8DEVTYPE_JOYSTICK, DeviceFindCallBack, NULL, DIEDFL_ATTACHEDONLY);
    if (FAILED(result)) {
        assert(0);
        return result;
    }

    // �Q�[���p�b�h�f�o�C�X�̐���
    result = dinput->CreateDevice(GUID_Joystick, &devPad, NULL);

    // ���̓f�[�^�`���̃Z�b�g
    result = devKeyBoard->SetDataFormat(&c_dfDIKeyboard); // �W���`��
    if (FAILED(result)) {
        assert(0);
        return result;
    }

    // �r�����䃌�x���̃Z�b�g
    result = devKeyBoard->SetCooperativeLevel(this->winApp->GetHwnd(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
    if (FAILED(result)) {
        assert(0);
        return result;
    }

    // �f�o�C�X�̃t�H�[�}�b�g�̐ݒ�
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

    //�O��̃L�[���͂�ۑ�
    memcpy(keyPre, key, sizeof(key));

    //�L�[�{�[�h���̎擾�J�n
    result = devKeyBoard->Acquire();

    //�S�L�[�̓��͏����擾����
    result = devKeyBoard->GetDeviceState(sizeof(key), key);

    // �R���g���[���[���Q�[�����ɐڑ������ۂ̏���
    if (devPad == nullptr)
    {
        result = InterruptInitialize(result);
    }

    // �R���g���[���[���ڑ���Ԃł���ꍇ
    if (devPad != nullptr)
    {
        // �Q�[���p�b�h
        result = devPad->Acquire();

        // �O��̓��͂�ۑ�
        padStatePre = padState;

        // �Q�[���p�b�h�̓���
        result = devPad->GetDeviceState(sizeof(padState), &padState);

        devPad->Poll();
    }
}

bool Input::PushKey(BYTE keyNumber)
{
    //�w��L�[�������Ă����true��Ԃ�
    if (key[keyNumber])
    {
        return true;
    }

    //�����łȂ����false��Ԃ�
    return false;
}

bool Input::TriggerKey(BYTE keyNumber)
{
    //�w��L�[�������Ă����true��Ԃ�
    if (key[keyNumber] && !keyPre[keyNumber])
    {
        return true;
    }

    //�����łȂ����false��Ԃ�
    return false;
}

bool Input::AwayKey(BYTE keyNumber)
{
    //�w��L�[�������Ă����true��Ԃ�
    if (!key[keyNumber] && keyPre[keyNumber])
    {
        return true;
    }

    //�����łȂ����false��Ԃ�
    return false;
}

bool Input::PushMoveKey()
{
     //�w��L�[�������Ă����true��Ԃ�
    if (key[DIK_W] || key[DIK_A] || key[DIK_S] || key[DIK_D])
    {
        return true;
    }

    //�����łȂ����false��Ԃ�
    return false;
}

bool Input::PushButton(unsigned int buttonNumber)
{
    // �ُ�Ȉ��������o
    assert(0 <= buttonNumber && buttonNumber < 9);

    if (padState.rgbButtons[buttonNumber] != 0)
    {
        return true;
    }

    return false;
}

bool Input::PushKeepButton(unsigned int buttonNumber)
{
    // �ُ�Ȉ��������o
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
    // �ُ�Ȉ��������o
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
    // �ُ�Ȉ��������o
    assert(0 <= stickNumber && stickNumber <= 3);

    if (devPad != nullptr)
    {
        // �X�e�B�b�N�i���o�[��Left�̏ꍇ
        if (stickNumber == StickLeft)
        {
            if (padState.lRx < -500) { return true; }
        }
        // �X�e�B�b�N�i���o�[��Right�̏ꍇ
        if (stickNumber == StickRight)
        {
            if (padState.lRx > +500) { return true; }
        }
        // �X�e�B�b�N�i���o�[��Up�̏ꍇ
        if (stickNumber == StickUp)
        {
            if (padState.lRy < -500) { return true; }
        }
        // �X�e�B�b�N�i���o�[��Down�̏ꍇ
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

    // ���̓f�[�^�`���̃Z�b�g
    result = devPad->SetDataFormat(&c_dfDIJoystick2);
    if (FAILED(result)) {
        assert(0);
        return result;
    }

    // �����[�h���Βl���[�h�Ƃ��Đݒ�
    DIPROPDWORD diprop;
    ZeroMemory(&diprop, sizeof(diprop));
    diprop.diph.dwSize = sizeof(diprop);
    diprop.diph.dwHeaderSize = sizeof(diprop.diph);
    diprop.diph.dwHow = DIPH_DEVICE;
    diprop.diph.dwObj = 0;
    diprop.dwData = DIPROPAXISMODE_ABS;	// ��Βl���[�h�̎w��(DIPROPAXISMODE_REL�ɂ����瑊�Βl

    result = devPad->SetProperty(DIPROP_AXISMODE, &diprop.diph);
    if (FAILED(result)) {
        assert(0);
        return result;
    }

    // X���̒l�͈̔͐ݒ�
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

    // Y���̒l�͈̔͐ݒ�
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


    // �r�����䃌�x���̃Z�b�g
    result = devPad->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
    if (FAILED(result)) {
        assert(0);
        return result;
    }


    return result;
}

bool Input::InterruptInitialize(HRESULT result)
{
    // �Q�[���p�b�h�f�o�C�X�̐���
    result = dinput->CreateDevice(GUID_Joystick, &devPad, NULL);

    // �f�o�C�X�̃t�H�[�}�b�g�̐ݒ�
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
