#include "SceneFactory.h"

#include "TitleScene.h"
#include "ManualScene.h"
#include "PlayScene.h"

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
	else if (sceneName == "MANUAL")
	{
		newScene = new ManualScene();
	}

	// 作成したシーンをリターン
	return newScene;
}
