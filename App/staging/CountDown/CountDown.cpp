#include "CountDown.h"
#include "WinApp.h"
#include "LoadSprite.h"
#include "Audio.h"

// �ÓI�����o�ϐ��̎���
const float CountDown::centerPos = 0.5f;
const float CountDown::movePower = 100.0f;
const float CountDown::decayPower = 0.05f;

CountDown* CountDown::Create()
{
    // �C���X�^���X����
    CountDown* instance = new CountDown();
    // �C���X�^���X������
    instance->Initialize();

    return instance;
}

CountDown::~CountDown()
{
    delete sprite;
}

void CountDown::Initialize()
{
    // �X�v���C�g����
    sprite = Sprite::Create(third_Number, { WinApp::window_width / 2, WinApp::window_height / 2 });
    // �A���J�[�|�C���g���摜�̒��S��
    sprite->SetAnchorPoint({centerPos, centerPos});
    // �����^�C�}�[�Z�b�g
    countTimer = maxTimer;
	// �����ǂݍ���
	//Audio::GetInstance()->LoadWave("countDown.wav");
}


void CountDown::Update()
{
	Audio* audio = Audio::GetInstance();

	// �J�E���g�_�E������
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

		//audio->PlayWave("countDown.wav", false);
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
		if (alpha < -2.5f)
		{
			startFlag = true;
			//audio->StopWave("countDown.wav");
		}
	}

	sprite->Updata();
}

void CountDown::Draw()
{
	sprite->Draw();
}