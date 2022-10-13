#pragma once
#include "BaseScene.h"

class SceneManager
{
public:
	~SceneManager();

	/// <summary>
	/// 更新
	/// </summary>
	void Updata();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	// 次シーン予約
	void SetNextScene(BaseScene* nextScene) { this->nextScene = nextScene; }

private:
	// 今のシーン
	BaseScene* nowScene = nullptr;
	// 次のシーン
	BaseScene* nextScene = nullptr;
};

