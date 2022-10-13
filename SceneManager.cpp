#include "SceneManager.h"

SceneManager::~SceneManager()
{
	// 最後のシーンの終了と解放
	nowScene->Finalize();
	delete nowScene;
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

		nowScene->Initialize();
	}

	nowScene->Updata();
}

void SceneManager::Draw()
{
	nowScene->Draw();
}
