#include "TitleScene.h"
#include "Input.h"
#include "DebugText.h"
#include "SceneManager.h"
#include "Audio.h"

void TitleScene::Initialize()
{
	for (int i = 0; i < maxTex; i++)
	{
		// �X�v���C�g����
		sprites[i] = Sprite::Create(title_None_Number + i, {0.0f, 0.0f});
	}

	Audio::GetInstance()->LoadWave("title.wav");
	Audio::GetInstance()->LoadWave("select.wav");
}

void TitleScene::Finalize()
{
	// �X�v���C�g���
	for (int i = 0; i < maxTex; i++)
	{
		delete sprites[i];
	}
}

void TitleScene::Updata()
{
	Input* input = Input::GetInstacne();
	Audio* audio = Audio::GetInstance();

	audio->PlayWave("title.wav", true);

	if (input->TriggerKey(DIK_S))
	{
		audio->StopWave("select.wav");
		audio->PlayWave("select.wav", false);
		texFlag = manual;
	}

	if (input->TriggerKey(DIK_W))
	{
		audio->StopWave("select.wav");
		audio->PlayWave("select.wav", false);
		texFlag = start;
	}

	if (texFlag == start)
	{
		if (input->TriggerKey(DIK_SPACE))
		{
			// �V�[���؂�ւ�
			SceneManager::GetInstance()->ChangeScene("PLAY");
			audio->StopWave("title.wav");
		}
	}
	
	else if (texFlag == manual)
	{
		if (input->TriggerKey(DIK_SPACE))
		{
			// �V�[���؂�ւ�
			SceneManager::GetInstance()->ChangeScene("MANUAL");
		}
	}

	sprites[texFlag]->Updata();
}

void TitleScene::Draw()
{
	// �X�v���C�g�O����
	SpriteCommon::GetInstance()->PreDraw();
	// �X�v���C�g�`��
	sprites[texFlag]->Draw();
}