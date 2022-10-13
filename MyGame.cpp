#include "MyGame.h"
#include "PlayScene.h"
#include "TitleScene.h"

void MyGame::Initialize()
{
	// ���N���X�̏�����
	FrameWork::Initialize();

	// �V�[��������
	BaseScene* scene = new TitleScene(sceneManager);
	// �V�[���}�l�[�W���[�ɍŏ��̃V�[�����Z�b�g
	sceneManager->SetNextScene(scene);
}

void MyGame::Finalize()
{
	// ���N���X�̏I������
	FrameWork::Finalize();
}

void MyGame::Updata()
{
	// ���N���X�̍X�V����
	FrameWork::Updata();
}

void MyGame::Draw()
{
	// ���N���X�̕`�揈��
	FrameWork::Draw();
}
