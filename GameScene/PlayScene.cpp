#include "PlayScene.h"
#include "TitleScene.h"
#include "Input.h"
#include "DebugText.h"
#include "SceneManager.h"

void PlayScene::Initialize()
{
	// �O�����h����
	model_Ground = Model::LoadFromOBJ("ground");
	obj_Ground = Object3d::Create(model_Ground);
	// ���[�h����
	model_Road = Model::LoadFromOBJ("load");
	obj_Road = Object3d::Create(model_Road);
	// �v���C���[����
	player = Player::Create();
}

void PlayScene::Finalize()
{
	// �O�����h���
	delete model_Ground;
	delete obj_Ground;
	delete model_Road;
	delete obj_Road;
	delete player;
}

void PlayScene::Updata()
{
	Input* input = Input::GetInstacne();
	if (input->TriggerKey(DIK_SPACE))
	{
		// �V�[���؂�ւ�
		SceneManager::GetInstance()->ChangeScene("TITLE");
	}

	// �O�����h�X�V
	obj_Ground->Update();
	// ���[�h�X�V
	obj_Road->Update();
	// �v���C���[�X�V
	player->Update();
}

void PlayScene::Draw()
{
	// 3D�I�u�W�F�N�g�`��O����
	Object3d::PreDraw();
	// �O�����h�`��
	obj_Ground->Draw();
	// ���[�h�`��
	obj_Road->Draw();
	// �v���C���[�`��
	player->Draw();
	// �X�v���C�g�O����
	SpriteCommon::GetInstance()->PreDraw();
	//�f�o�b�O�e�L�X�g�`��
	// �J�������W
	sprintf_s(strDebug, "%f   %f", player->GetPos().z, player->GetEye().z);
	DebugText::GetInstance()->Print(strDebug, 0, 0, 2);
	DebugText::GetInstance()->DrawAll();

}