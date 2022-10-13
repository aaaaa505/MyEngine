#pragma once
#include "BaseScene.h"
#include "Sprite.h"
#include "LoadSprite.h"
#include "Camera.h"

class TitleScene : public BaseScene
{
public:
	TitleScene(SceneManager* sceneManager);

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

private:// メンバ変数
	Sprite* sprite = nullptr;
};

