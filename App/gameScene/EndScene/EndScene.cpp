#include "EndScene.h"
#include "Input.h"
#include "DebugText.h"
#include "SceneManager.h"

void EndScene::Initialize()
{
#pragma region スプライト
	// スプライト生成
	sprite = Sprite::Create(end_Number, { 0.0f, 0.0f });
#pragma endregion
}

void EndScene::Finalize()
{
	// スプライト解放
	delete sprite;
}

void EndScene::Updata()
{
	Input* input = Input::GetInstacne();
	if (input->TriggerKey(DIK_SPACE))
	{
		// シーン切り替え
		SceneManager::GetInstance()->ChangeScene("TITLE");
	}

	sprite->Updata();
}

void EndScene::Draw()
{
	// スプライト前処理
	SpriteCommon::GetInstance()->PreDraw();
	// スプライト描画
	sprite->Draw();

}