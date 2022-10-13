#include "SceneManager.h"

SceneManager::~SceneManager()
{
	// �Ō�̃V�[���̏I���Ɖ��
	nowScene->Finalize();
	delete nowScene;
}

void SceneManager::Updata()
{
	// �V�[���؂�ւ�������Ȃ�
	if (nextScene)
	{
		// ���V�[���̏I��
		if (nowScene)
		{
			nowScene->Finalize();
			delete nowScene;
		}

		// �V�[���؂�ւ�
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
