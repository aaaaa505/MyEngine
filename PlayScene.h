#pragma once
#include "Object3d.h"
#include "Sprite.h"
#include "LoadSprite.h"
#include "Camera.h"

class PlayScene
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 終了
	/// </summary>
	void Finalize();

	/// <summary>
	/// 更新
	/// </summary>
	void Updata();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();


private:// メンバ変数
	Model* model = nullptr;
	Object3d* object3d = nullptr;
	Sprite* sprite = nullptr;
	Camera* camera = nullptr;

	char strDebug[100];
};

