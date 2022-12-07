#include "TitleScene.h"
#include "Input.h"
#include "DebugText.h"
#include "SceneManager.h"
#include "Audio.h"

void TitleScene::Initialize()
{
	for (int i = 0; i < maxTex; i++)
	{
		// スプライト生成
		sprites[i] = Sprite::Create(title_None_Number + i, {0.0f, 0.0f});
	}

	Audio::GetInstance()->LoadWave("title.wav");
	Audio::GetInstance()->LoadWave("select.wav");
}

void TitleScene::Finalize()
{
	// スプライト解放
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
			// シーン切り替え
			SceneManager::GetInstance()->ChangeScene("PLAY");
			audio->StopWave("title.wav");
		}
	}
	
	else if (texFlag == manual)
	{
		if (input->TriggerKey(DIK_SPACE))
		{
			// シーン切り替え
			SceneManager::GetInstance()->ChangeScene("MANUAL");
		}
	}

	sprites[texFlag]->Updata();
}

void TitleScene::Draw()
{
	// スプライト前処理
	SpriteCommon::GetInstance()->PreDraw();
	// スプライト描画
	sprites[texFlag]->Draw();
}