#include "SceneFactory.h"

#include "TitleScene.h"
#include "ManualScene.h"
#include "PlayScene.h"
#include "EndScene.h"

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
	else if (sceneName == "END")
	{
		newScene = new EndScene();
	}

	// �쐬�����V�[�������^�[��
	return newScene;
}
