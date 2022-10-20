#pragma once
#include<windows.h>

//WindowAPI
class WinApp
{
public://静的メンバ関数
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

public://メンバ関数
	//初期化
	void Initialize();

	//更新
	void Updata();

	//getter
	HWND GetHwnd() { return hwnd; }
	HINSTANCE GetHInstance() { return w.hInstance; }

	//終了
	void Finalize();

	//メッセージ処理
	bool ProcessMessage();


private://メンバ変数
	//ウィンドウハンドル
	HWND hwnd = nullptr;

	//ウィンドウクラスの設定
	WNDCLASSEX w{};


public://定数
	//ウィンドウ横幅
	static const int window_width = 1280;

	//ウィンドウ縦幅
	static const int window_height = 720;

};

