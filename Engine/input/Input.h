#pragma once
#include<windows.h>
#include "wrl.h"
#include "WinApp.h"

#define DIRECTINPUT_VERSION 0x0800 //DirectInputのバージョン指定
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
public:// エイリアス
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

public:// 静的メンバ関数

	/// <summary>
	/// シングロトン
	/// </summary>
	/// <returns></returns>
	static Input* GetInstacne();

	/// <summary>
	/// コールバック
	/// </summary>
	/// <param name="ipddi"></param>
	/// <param name="pvRef"></param>
	/// <returns></returns>
	static BOOL CALLBACK DeviceFindCallBack(LPCDIDEVICEINSTANCE ipddi, LPVOID pvRef);

public:// メンバ関数
	
	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="winApp"></param>
	bool Initialize(WinApp* winApp);

	/// <summary>
	/// 更新
	/// </summary>
	void Updata();


#pragma region キーボード入力関数
	/// <summary>
	/// キーの押下をチェック
	/// </summary>
	/// <param name="keyNumber"></param>
	/// <returns></returns>
	bool PushKey(BYTE keyNumber);

	/// <summary>
	/// キーが離れたタイミングをチェック
	/// </summary>
	/// <param name="keyNumrber"></param>
	/// <returns></returns>
	bool AwayKey(BYTE keyNumrber);

	/// <summary>
	/// キーのトリガーをチェック
	/// </summary>
	/// <param name="keyNumber"></param>
	/// <returns></returns>
	bool TriggerKey(BYTE keyNumber);

	/// <summary>
	/// WASDのどれかが押された場合
	/// </summary>
	/// <returns></returns>
	bool PushMoveKey();
#pragma endregion

#pragma region パッド入力関数

	/// <summary>
	/// コントローラー接続チェック
	/// </summary>
	/// <returns></returns>
	bool CheckPad();

	/// <summary>
	/// コントローラーの押下をチェック
	/// </summary>
	/// <param name="buttonNumber"></param>
	/// <returns></returns>
	bool PushButton(unsigned int buttonNumber);

	/// <summary>
	/// コントローラーの押下が継続しているかをチェック
	/// </summary>
	/// <param name="buttonNumber"></param>
	/// <returns></returns>
	bool PushKeepButton(unsigned int buttonNumber);

	/// <summary>
	/// ゲームパッドの左側スティックデータ取得
	/// </summary>
	/// <param name="sticNum">スティックナンバー(例 SticLeft)</param>
	/// <returns>成否</returns>
	bool TiltLeftStick(unsigned int sticNumber);

	/// <summary>
	/// ゲームパッドの右側スティックデータ取得
	/// </summary>
	/// <param name="sticNumber">スティックナンバー(例 SticLeft)</param>
	/// <returns>成否</returns>
	bool TiltRightStick(unsigned int sticNumber);
#pragma endregion

private:// メンバ変数

	/// <summary>
	/// ゲームパッドパッドの初期化
	/// </summary>
	/// <returns>成否</returns>
	bool PadInitialize(HWND hwnd);

	/// <summary>
	/// 実行中に初期化
	/// </summary>
	/// <returns></returns>
	bool InterruptInitialize(HRESULT result);

private:// メンバ変数

	// キーボードのデバイス
	ComPtr<IDirectInputDevice8> devKeyBoard;
	// DirectInputのインスタンス
	ComPtr<IDirectInput8> dinput;
	// 全キーの状態
	BYTE key[256] = {};
	// 前回の全キーの状態
	BYTE keyPre[256] = {};
	// WindowsAPI
	WinApp* winApp = nullptr;
	// パッドのデバイス
	ComPtr<IDirectInputDevice8> devPad;
	// パッドステータス
	DIJOYSTATE2 padState;
	// パッドプレステータス
	DIJOYSTATE2 padStatePre;
};

