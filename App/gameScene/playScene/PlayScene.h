#pragma once
#include "BaseScene.h"
#include "Object3d.h"
#include "LoadSprite.h"
#include "Camera.h"
#include "Player.h"
#include "Enemy.h"
#include "Scroll.h"

class PlayScene : public BaseScene
{
public:

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize() override;

	/// <summary>
	/// 終了
	/// </summary>
	void Finalize() override;

	/// <summary>
	/// 更新
	/// </summary>
	void Updata() override;

	/// <summary>
	/// 描画
	/// </summary>
	void Draw() override;


private:
	// プレイヤー
	Player* player = nullptr;
	// プレイヤー
	Enemy* enemy = nullptr;
	// スクロール
	Scroll* scroll = nullptr;
	// グランド
	Model* model_Ground = nullptr;
	Object3d* obj_Ground = nullptr;

	// デバッグテキスト用
	char strDebug[100];
};

