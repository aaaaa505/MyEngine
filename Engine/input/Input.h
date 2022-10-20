#pragma once
#include<windows.h>
#include "wrl.h"
#include "WinApp.h"

#define DIRECTINPUT_VERSION 0x0800 //DirectInput�̃o�[�W�����w��
#include<dinput.h>

#pragma region ButtonNumber

#define StickLeft	0
#define StickRight	1
#define StickUp		2
#define StickDown	3

#define Button_A		0
#define Button_B		1
#define Button_X		2
#define Button_Y		3
#define Button_L1		4
#define Button_R1		5
#define Button_Back		6
#define Button_Start	7
#define Button_L3		8
#pragma endregion


class Input
{
public:// �G�C���A�X
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

public:// �ÓI�����o�֐�

	/// <summary>
	/// �V���O���g��
	/// </summary>
	/// <returns></returns>
	static Input* GetInstacne();

	/// <summary>
	/// �R�[���o�b�N
	/// </summary>
	/// <param name="ipddi"></param>
	/// <param name="pvRef"></param>
	/// <returns></returns>
	static BOOL CALLBACK DeviceFindCallBack(LPCDIDEVICEINSTANCE ipddi, LPVOID pvRef);

public:// �����o�֐�
	
	/// <summary>
	/// ������
	/// </summary>
	/// <param name="winApp"></param>
	bool Initialize(WinApp* winApp);

	/// <summary>
	/// �X�V
	/// </summary>
	void Updata();


#pragma region �L�[�{�[�h���͊֐�
	/// <summary>
	/// �L�[�̉������`�F�b�N
	/// </summary>
	/// <param name="keyNumber"></param>
	/// <returns></returns>
	bool PushKey(BYTE keyNumber);

	/// <summary>
	/// �L�[�����ꂽ�^�C�~���O���`�F�b�N
	/// </summary>
	/// <param name="keyNumrber"></param>
	/// <returns></returns>
	bool AwayKey(BYTE keyNumrber);

	/// <summary>
	/// �L�[�̃g���K�[���`�F�b�N
	/// </summary>
	/// <param name="keyNumber"></param>
	/// <returns></returns>
	bool TriggerKey(BYTE keyNumber);

	/// <summary>
	/// WASD�̂ǂꂩ�������ꂽ�ꍇ
	/// </summary>
	/// <returns></returns>
	bool PushMoveKey();
#pragma endregion

#pragma region �p�b�h���͊֐�

	/// <summary>
	/// �R���g���[���[�ڑ��`�F�b�N
	/// </summary>
	/// <returns></returns>
	bool CheckPad();

	/// <summary>
	/// �R���g���[���[�̉������`�F�b�N
	/// </summary>
	/// <param name="buttonNumber"></param>
	/// <returns></returns>
	bool PushButton(unsigned int buttonNumber);

	/// <summary>
	/// �R���g���[���[�̉������p�����Ă��邩���`�F�b�N
	/// </summary>
	/// <param name="buttonNumber"></param>
	/// <returns></returns>
	bool PushKeepButton(unsigned int buttonNumber);

	/// <summary>
	/// �Q�[���p�b�h�̍����X�e�B�b�N�f�[�^�擾
	/// </summary>
	/// <param name="sticNum">�X�e�B�b�N�i���o�[(�� SticLeft)</param>
	/// <returns>����</returns>
	bool TiltLeftStick(unsigned int sticNumber);

	/// <summary>
	/// �Q�[���p�b�h�̉E���X�e�B�b�N�f�[�^�擾
	/// </summary>
	/// <param name="sticNumber">�X�e�B�b�N�i���o�[(�� SticLeft)</param>
	/// <returns>����</returns>
	bool TiltRightStick(unsigned int sticNumber);
#pragma endregion

private:// �����o�ϐ�

	/// <summary>
	/// �Q�[���p�b�h�p�b�h�̏�����
	/// </summary>
	/// <returns>����</returns>
	bool PadInitialize(HWND hwnd);

	/// <summary>
	/// ���s���ɏ�����
	/// </summary>
	/// <returns></returns>
	bool InterruptInitialize(HRESULT result);

private:// �����o�ϐ�

	// �L�[�{�[�h�̃f�o�C�X
	ComPtr<IDirectInputDevice8> devKeyBoard;
	// DirectInput�̃C���X�^���X
	ComPtr<IDirectInput8> dinput;
	// �S�L�[�̏��
	BYTE key[256] = {};
	// �O��̑S�L�[�̏��
	BYTE keyPre[256] = {};
	// WindowsAPI
	WinApp* winApp = nullptr;
	// �p�b�h�̃f�o�C�X
	ComPtr<IDirectInputDevice8> devPad;
	// �p�b�h�X�e�[�^�X
	DIJOYSTATE2 padState;
	// �p�b�h�v���X�e�[�^�X
	DIJOYSTATE2 padStatePre;
};

