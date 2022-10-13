#pragma once
#include "BaseScene.h"

class SceneManager
{
public:

	/// <summary>
	/// インスタンス取得
	/// </summary>
	/// <returns></returns>
	static SceneManager* GetInstance();

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

private:// 外部で新たなインスタンスを作らせないために隠蔽
	SceneManager() = default;
	~SceneManager();
	SceneManager(const SceneManager&) = delete;
	void operator= (const SceneManager&) = delete;

private:
	// 今のシーン
	BaseScene* nowScene = nullptr;
	// 次のシーン
	BaseScene* nextScene = nullptr;
};

