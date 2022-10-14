#pragma once
#include "BaseScene.h"
#include "AbstractSceneFactory.h"

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

	/// <summary>
	/// 次シーン予約
	/// </summary>
	/// <param name="sceneName">シーン名</param>
	void ChangeScene(const std::string& sceneName);

	
	void SetSceneFactory(AbstractSceneFactory* sceneFactory) { this->sceneFactory = sceneFactory; }

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
	// シーンファクトリー
	AbstractSceneFactory* sceneFactory = nullptr;
};

