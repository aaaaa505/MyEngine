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
	scroll = Scroll::Create();
	// �J�E���g�_�E������
	countDown = CountDown::Create();
}

void PlayScene::Finalize()
{
	// �v���C���[���
	delete player;
	// �G�l�~�[���wwwwwww
	delete enemy;
	// �t�B�[���h���
	delete scroll;
}

void PlayScene::Updata()
{
	for (int i = 0; i < enemy->GetDataSize(); i++)
	{
		if (enemy->GetModelFlag(i) == car)
		{
			if (Collision::BoxToBox(player->GetPos(), { RADIUS_X, RADIUS_Z }, enemy->GetPos(i), {CAR_RADIUS_X, CAR_RADIUS_Z}))
			{
				// �V�[���؂�ւ�
				SceneManager::GetInstance()->ChangeScene("END");
				break;
			}
		}
		else
		{
			if (Collision::BoxToBox(player->GetPos(), { RADIUS_X, RADIUS_Z }, enemy->GetPos(i), { TRACK_RADIUS_X, TRACK_RADIUS_Z }))
			{
				// �V�[���؂�ւ�
				SceneManager::GetInstance()->ChangeScene("END");
				break;
			}
		}
	}

	

	// �v���C���[�X�V
	player->Update(countDown->GetStartFlag());
	// �G�l�~�[�X�V
	enemy->Update(player->GetPos(), player->GetSpeed().z);
	// �t�B�[���h�X�V
	scroll->Update(player->GetPos());

	if (!countDown->GetStartFlag()){ countDown->Update(); }
}

void PlayScene::Draw()
{
	// 3D�I�u�W�F�N�g�`��O����
	Object3d::PreDraw();

	// �v���C���[�`��
	player->Draw();
	// �G�l�~�[�`��
	enemy->Draw();
	// �t�B�[���h�`��
	scroll->Draw();
	
	// �X�v���C�g�O����
	SpriteCommon::GetInstance()->PreDraw();
	if (!countDown->GetStartFlag()) { countDown->Draw(); }
	sprintf_s(strDebug, "11111");
	DebugText::GetInstance()->Print(strDebug, 0.0f, 0.0f, 2);
	DebugText::GetInstance()->DrawAll();
}