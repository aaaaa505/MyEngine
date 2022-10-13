#include "SceneManager.h"

SceneManager::~SceneManager()
{
	// 最後のシーンの終了と解放
	nowScene->Finalize();
	delete nowScene;
}

SceneManager* SceneManager::GetInstance()
{
	static SceneManager instance;

	return &instance;
}

void SceneManager::Updata()
{
	// シーン切り替えがあるなら
	if (nextScene)
	{
		// 旧シーンの終了
		if (nowScene)
		{
			nowScene->Finalize();
			delete nowScene;
		}

		// シーン切り替え
		nowScene = nextScene;
		nextScene = nullptr;

		// 次のシーンの初期化
		nowScene->Initialize();
	}

	// 現在のシーン更新
	nowScene->Updata();
}

void SceneManager::Draw()
{
	// 現在のシーン描画
	nowScene->Draw();
}
