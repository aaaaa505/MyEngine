#pragma once
#include "WinApp.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "DebugText.h"
#include "LoadSprite.h"
#include "Object3d.h"
#include "Sprite.h"
#include "SceneManager.h"

class FrameWork
{

public:// メンバ関数

	/// <summary>
	/// 初期化
	/// </summary>
	virtual void Initialize();

	/// <summary>
	/// 終了
	/// </summary>
	virtual void Finalize();

	/// <summary>
	/// 実行
	/// </summary>
	void Run();

	/// <summary>
	/// 更新
	/// </summary>
	virtual void Updata();

	/// <summary>
	/// 描画
	/// </summary>
	virtual void Draw();

protected:
	// 終了フラッグ
	bool endRequest = false;
	// ポインタ置き場
	WinApp* winApp = nullptr;
	DirectXCommon* dxCommon = nullptr;
	SpriteCommon* spriteCommon = nullptr;
	Input* input = nullptr;
	DebugText* debugText = nullptr;
};

