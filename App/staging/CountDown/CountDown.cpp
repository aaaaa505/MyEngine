#include "CountDown.h"
#include "WinApp.h"
#include "LoadSprite.h"
#include "Audio.h"

CountDown* CountDown::Create()
{
    // インスタンス生成
    CountDown* instance = new CountDown();
    // インスタンス初期化
    instance->Initialize();

    return instance;
}

CountDown::~CountDown()
{
    delete sprite;
}

void CountDown::Initialize()
{
    // スプライト生成
    sprite = Sprite::Create(third_Number, { WinApp::window_width / 2, WinApp::window_height / 2 });
    // アンカーポイントを画像の中心へ
    sprite->SetAnchorPoint({centerPos, centerPos});
    // 初期タイマーセット
    countTimer = maxTimer;
	// 音源読み込み
	Audio::GetInstance()->LoadWave("countDown.wav");
}


void CountDown::Update()
{
	Audio* audio = Audio::GetInstance();

	// カウントダウン処理
	if (countFlag < zero)
	{
		countTimer--;
		if (countTimer <= 0)
		{
			countFlag++;
			countTimer = maxTimer;
		}

		if (countFlag == third)
		{
			sprite->SetTexture(third_Number);
		}
		else if (countFlag == second)
		{
			sprite->SetTexture(second_Number);
		}
		else if (countFlag == first)
		{
			sprite->SetTexture(first_Number);
		}
		else
		{
			sprite->SetTexture(zero_Number);
		}

		audio->PlayWave("countDown.wav", false);
	}

	if (countFlag == zero)
	{
		DirectX::XMFLOAT2 size = sprite->GetSize();
		float alpha = sprite->GetAlpha();
		size.x += movePower;
		size.y += movePower;
		alpha -= decayPower;
		sprite->SetAlpha(alpha);
		sprite->SetSize(size);
		if (alpha < -3.0f)
		{
			startFlag = true;
			audio->StopWave("countDown.wav");
		}
	}

	sprite->Updata();
}

void CountDown::Draw()
{
	sprite->Draw();
}