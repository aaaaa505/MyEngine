#pragma once
#include "WinApp.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Audio.h"
#include "DebugText.h"
#include "DrawNumber.h"
#include "LoadSprite.h"
#include "Object3d.h"
#include "Sprite.h"
#include "SceneManager.h"
#include "AbstractSceneFactory.h"

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
	Audio* audio = nullptr;
	DebugText* debugText = nullptr;
	DrawNumber* drawNumber = nullptr;
	AbstractSceneFactory* sceneFactory = nullptr;

};

