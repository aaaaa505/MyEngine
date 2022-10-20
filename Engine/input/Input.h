#pragma once
#include<windows.h>
#include "wrl.h"
#include "WinApp.h"

#define DIRECTINPUT_VERSION 0x0800 //DirectInputのバージョン指定
#include<dinput.h>

//入力
class Input
{
public:
	//namespace省略
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;


public://メンバ関数

	/// <summary>
	/// シングロトン
	/// </summary>
	/// <returns></returns>
	static Input* GetInstacne();

	//初期化
	void Initialize(WinApp* winApp);

	//更新
	void Updata();

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
private://メンバ変数
	//キーボードのデバイス
	ComPtr<IDirectInputDevice8> devkeyboard;

	//DirectInputのインスタンス
	ComPtr<IDirectInput8> dinput;

	//全キーの状態
	BYTE key[256] = {};

	//前回の全キーの状態
	BYTE keyPre[256] = {};

	//WindowsAPI
	WinApp* winApp = nullptr;

};

