#include "PlayScene.h"
#include "TitleScene.h"
#include "Input.h"
#include "DrawNumber.h"
#include "SceneManager.h"
#include "Collision.h"
#include "Audio.h"

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

	// �X�R�A
	sprite = Sprite::Create(scoreBar_Number, { 0.0f, 0.0f });
	crash = Sprite::Create(crash_Number, { 0.0f, 0.0f });
	result = Sprite::Create(result_Number, { 0.0f, 0.0f });
	//Audio::GetInstance()->LoadWave("crash.wav");
}

void PlayScene::Finalize()
{
	// �v���C���[���
	delete player;
	// �G�l�~�[���
	delete enemy;
	// �t�B�[���h���
	delete scroll;

	delete sprite;
	delete result;
	delete crash;
	delete countDown;
}

void PlayScene::Updata()
{
	for (int i = 0; i < enemy->GetDataSize() && !resultFlag; i++)
	{
		if (enemy->GetModelFlag(i) == car)
		{
			if (Collision::BoxToBox(player->GetPos(), { RADIUS_X, RADIUS_Z }, enemy->GetPos(i), {CAR_RADIUS_X, CAR_RADIUS_Z}))
			{
				// �V�[���؂�ւ�
				//SceneManager::GetInstance()->ChangeScene("END");
				hitFlag = true;
				player->SetHitFlag(hitFlag);
				//Audio::GetInstance()->PlayWave("crash.wav", false);
				break;
			}
		}
		else
		{
			if (Collision::BoxToBox(player->GetPos(), { RADIUS_X, RADIUS_Z }, enemy->GetPos(i), { TRACK_RADIUS_X, TRACK_RADIUS_Z }))
			{
				// �V�[���؂�ւ�
				//SceneManager::GetInstance()->ChangeScene("END");
				hitFlag = true;
				player->SetHitFlag(hitFlag);
				//Audio::GetInstance()->PlayWave("crash.wav", false);
				break;
			}
		}
	}

	if (!hitFlag)
	{
		if (countDown->GetStartFlag())
		{
			if (player->GetSpeed().z < 1.0f && player->GetSpeed().z >= 0.1f)
			{
				scoreTimer--;
				if (scoreTimer <= 0)
				{
					scoreTimer = 20;
					score++;
				}
			}
			else
			{
				scoreTimer--;
				if (scoreTimer <= 0)
				{
					scoreTimer = 10;
					score++;
				}
			}
		}
	}
	else
	{
		sceneChangeTimer--;
		if (sceneChangeTimer < 0)
		{
			//Audio::GetInstance()->StopWave("crash.wav");
			resultFlag = true;
		}
	}

	if (player->GetPos().x > 7.0f || player->GetPos().x < -7.0f)
	{
		hitFlag = true;
		player->SetHitFlag(hitFlag);
	}

	sprintf_s(str, "%d", (int)score);
	if (resultFlag)
	{
		
		DrawNumber::GetInstance()->Updata(str, { 570.0f, 380.0f }, 2.0f);
		if (Input::GetInstacne()->TriggerKey(DIK_SPACE))
		{
			SceneManager::GetInstance()->ChangeScene("TITLE");
		}
	}
	else
	{
		DrawNumber::GetInstance()->Updata(str, { 100.0f, 25.0f }, 0.7f);
	}



	// �v���C���[�X�V
	player->Update(countDown->GetStartFlag());
	// �G�l�~�[�X�V
	enemy->Update(player->GetPos(), player->GetSpeed().z, hitFlag);
	// �t�B�[���h�X�V
	scroll->Update(player->GetPos());

	if (!countDown->GetStartFlag()){ countDown->Update(); }
	
	//sprite->Updata();
	//crash->Updata();
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
	sprite->Draw();
	if (hitFlag){ crash->Draw(); }
	if (resultFlag) { result->Draw(); }
	DrawNumber::GetInstance()->DrawAll();
}
