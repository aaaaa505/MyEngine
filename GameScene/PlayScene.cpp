#include "PlayScene.h"
#include "TitleScene.h"
#include "Input.h"
#include "DebugText.h"
#include "SceneManager.h"

void PlayScene::Initialize()
{
	// �O�����h����
	model = Model::LoadFromOBJ("ground");
	obj = Object3d::Create(model);
	// �v���C���[����
	player = Player::Create();
}

void PlayScene::Finalize()
{
	// �O�����h���
	delete model;
	delete obj;
	delete player;
}

void PlayScene::Updata()
{
	Input* input = Input::GetInstacne();
	if (input->Triggerkey(DIK_SPACE))
	{
		// �V�[���؂�ւ�
		SceneManager::GetInstance()->ChangeScene("TITLE");
	}

	// �O�����h�X�V
	obj->Update();
	// �v���C���[�X�V
	player->Update();
}

void PlayScene::Draw()
{
	// 3D�I�u�W�F�N�g�`��O����
	Object3d::PreDraw();
	// �O�����h�`��
	obj->Draw();
	// �v���C���[�`��
	player->Draw();
	// �X�v���C�g�O����
	SpriteCommon::GetInstance()->PreDraw();
	//�f�o�b�O�e�L�X�g�`��
	// �J�������W
	sprintf_s(strDebug, "%f  %f", player->GetEye().x, player->GetPos().x);
	DebugText::GetInstance()->Print(strDebug, 0, 0, 2);
	DebugText::GetInstance()->DrawAll();

}