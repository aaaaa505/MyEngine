#include "SceneFactory.h"

#include "PlayScene.h"
#include "TitleScene.h"

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

	// �쐬�����V�[�������^�[��
	return newScene;
}
