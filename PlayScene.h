#pragma once
#include "BaseScene.h"
#include "Object3d.h"
#include "LoadSprite.h"
#include "Camera.h"

class PlayScene : public BaseScene
{
public:
	PlayScene(SceneManager* sceneManager);

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
	Model* model = nullptr;
	Object3d* object3d = nullptr;
	Camera* camera = nullptr;

	char strDebug[100];
};

