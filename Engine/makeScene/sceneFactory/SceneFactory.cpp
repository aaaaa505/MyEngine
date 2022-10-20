#include "SceneFactory.h"

#include "PlayScene.h"
#include "TitleScene.h"
#include "EndScene.h"

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
	else if (sceneName == "END")
	{
		newScene = new EndScene();
	}

	// 作成したシーンをリターン
	return newScene;
}
