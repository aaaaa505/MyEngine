#include "PlayScene.h"
#include "TitleScene.h"
#include "Input.h"
#include "DebugText.h"
#include "SceneManager.h"
#include "Collision.h"

void PlayScene::Initialize()
{
	// �v���C���[����
	player = Player::Create();
	// �G�l�~�[����
	enemy = Enemy::Create();
	// �t�B�[���h����
	field = Field::Create();
	// �O�����h����
	model_Ground = Model::LoadFromOBJ("debugField");
	obj_Ground = Object3d::Create(model_Ground);
}

void PlayScene::Finalize()
{
	// �v���C���[���
	delete player;
	// �G�l�~�[���
	delete enemy;
	// �t�B�[���h���
	delete field;
	// �O�����h���
	delete model_Ground;
	delete obj_Ground;
}

void PlayScene::Updata()
{

	for (int i = 0; i < 8; i++)
	{
		if (Collision::SphereSphere(player->GetPos(), 0.5f, enemy->GetPos(i), 1.0f))
		{
			// �V�[���؂�ւ�
			SceneManager::GetInstance()->ChangeScene("END");
			break;
		}
	}

	if (player->GetPos().x < -5.0f)
	{
		// �V�[���؂�ւ�
		SceneManager::GetInstance()->ChangeScene("END");
	}

	// �O�����h�X�V
	obj_Ground->Update();
	// �v���C���[�X�V
	player->Update();
	// �G�l�~�[�X�V
	enemy->Update(player->GetPos());
	// �t�B�[���h�X�V
	field->Update(player->GetPos());
}

void PlayScene::Draw()
{
	// 3D�I�u�W�F�N�g�`��O����
	Object3d::PreDraw();
	// �O�����h�`��
	//obj_Ground->Draw();
	// �v���C���[�`��
	player->Draw();
	// �G�l�~�[�`��
	enemy->Draw();
	// �t�B�[���h�`��
	field->Draw();
	// �X�v���C�g�O����
	SpriteCommon::GetInstance()->PreDraw();
	//�f�o�b�O�e�L�X�g�`��
	// �J�������W
	sprintf_s(strDebug, "Speed = %f  Flag = %d", player->GetSpeed().z, enemy->Get1());
	DebugText::GetInstance()->Print(strDebug, 0, 0, 2);
	DebugText::GetInstance()->DrawAll();

}