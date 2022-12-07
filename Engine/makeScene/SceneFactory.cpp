#include "SceneFactory.h"

#include "TitleScene.h"
#include "ManualScene.h"
#include "PlayScene.h"

BaseScene* SceneFactory::CreateScene(const std::string& sceneName)
{
	// ���̃V�[���𐶐�
	BaseScene* newScene = nullptr;
	
	// �C�ӂ̃V�[������
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

	// �쐬�����V�[�������^�[��
	return newScene;
}