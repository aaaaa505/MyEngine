#include "MyGame.h"
#include "PlayScene.h"

void MyGame::Initialize()
{
	// ���N���X�̏�����
	FrameWork::Initialize();

	// �v���C�V�[��������
	scene = new PlayScene();
	scene->Initialize();
}

void MyGame::Finalize()
{
	// �V�[���N���X�̏I������
	scene->Finalize();

	// ���N���X�̏I������
	FrameWork::Finalize();
}

void MyGame::Updata()
{
	scene->Updata();

	// ���N���X�̍X�V����
	FrameWork::Updata();
}

void MyGame::Draw()
{
	// �`��O����
	dxCommon->PreDraw();
	
	// �V�[���`��
	scene->Draw();

	// �f�o�b�O�e�L�X�g�`��
	debugText->DrawAll();

	//�`��㏈��
	dxCommon->PostDraw();
}
