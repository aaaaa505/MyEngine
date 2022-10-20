#include "EndScene.h"
#include "Input.h"
#include "DebugText.h"
#include "SceneManager.h"

void EndScene::Initialize()
{
#pragma region �X�v���C�g
	// �X�v���C�g����
	sprite = Sprite::Create(end_Number, { 0.0f, 0.0f });
#pragma endregion
}

void EndScene::Finalize()
{
	// �X�v���C�g���
	delete sprite;
}

void EndScene::Updata()
{
	Input* input = Input::GetInstacne();
	if (input->TriggerKey(DIK_SPACE))
	{
		// �V�[���؂�ւ�
		SceneManager::GetInstance()->ChangeScene("TITLE");
	}

	sprite->Updata();
}

void EndScene::Draw()
{
	// �X�v���C�g�O����
	SpriteCommon::GetInstance()->PreDraw();
	// �X�v���C�g�`��
	sprite->Draw();

}