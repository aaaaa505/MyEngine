#pragma once
#include "BaseScene.h"
#include "Object3d.h"
#include "LoadSprite.h"
#include "Sprite.h"
#include "Camera.h"
#include "Player.h"
#include "Enemy.h"
#include "Scroll.h"
#include "CountDown.h"

class PlayScene : public BaseScene
{
public:// 定数
	static const int maxCount = 4;
	static const int maxTimer = 60;

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
	// エネミー
	Enemy* enemy = nullptr;
	// スクロール
	Scroll* scroll = nullptr;
	// カウントダウン
	CountDown* countDown = nullptr;

	bool hitFlag = false;

	// スコア
	Sprite* sprite = nullptr;
	int32_t score = 0;
	int32_t scoreTimer = 30;
	char str[100];

	// クラッシュ
	Sprite* crash = nullptr;
	int32_t sceneChangeTimer = 80;

	// result
	Sprite* result = nullptr;
	bool resultFlag = false;
};

