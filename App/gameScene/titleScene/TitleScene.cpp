#include "TitleScene.h"
#include "Input.h"
#include "DebugText.h"
#include "SceneManager.h"

void TitleScene::Initialize()
{
#pragma region �X�v���C�g
	// �X�v���C�g����
	sprite = Sprite::Create(title_Number, { 0.0f, 0.0f });
#pragma endregion
}

void TitleScene::Finalize()
{
	// �X�v���C�g���
	delete sprite;
}

void TitleScene::Updata()
{
	Input* input = Input::GetInstacne();
	if (input->TriggerKey(DIK_SPACE))
	{
		// �V�[���؂�ւ�
		SceneManager::GetInstance()->ChangeScene("PLAY");
	}

	sprite->Updata();
}

void TitleScene::Draw()
{
	// �X�v���C�g�O����
	SpriteCommon::GetInstance()->PreDraw();
	// �X�v���C�g�`��
	sprite->Draw();

}