#include "ManualScene.h"
#include "Input.h"
#include "DebugText.h"
#include "SceneManager.h"

void ManualScene::Initialize()
{
#pragma region �X�v���C�g
	// �X�v���C�g����
	sprite = Sprite::Create(manual_Number, { 0.0f, 0.0f });
#pragma endregion
}

void ManualScene::Finalize()
{
	// �X�v���C�g���
	delete sprite;
}

void ManualScene::Updata()
{
	Input* input = Input::GetInstacne();
	if (input->TriggerKey(DIK_SPACE))
	{
		// �V�[���؂�ւ�
		SceneManager::GetInstance()->ChangeScene("TITLE");
	}

	sprite->Updata();
}

void ManualScene::Draw()
{
	// �X�v���C�g�O����
	SpriteCommon::GetInstance()->PreDraw();
	// �X�v���C�g�`��
	sprite->Draw();

}