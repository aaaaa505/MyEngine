#include "SceneFactory.h"

#include "PlayScene.h"
#include "TitleScene.h"

BaseScene* SceneFactory::CreateScene(const std::string& sceneName)
{
	// 次のシーンを生成
	BaseScene* newScene = nullptr;
	
	// 任意のシーン生成
	if (sceneName == "TITLE")
	{
		newScene = new TitleScene();
	}
	else if (sceneName == "PLAY")
	{
		newScene = new PlayScene();
	}

	// 作成したシーンをリターン
	return newScene;
}
