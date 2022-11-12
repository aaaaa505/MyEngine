#include "ManualScene.h"
#include "Input.h"
#include "DebugText.h"
#include "SceneManager.h"

void ManualScene::Initialize()
{
#pragma region スプライト
	// スプライト生成
	sprite = Sprite::Create(manual_Number, { 0.0f, 0.0f });
#pragma endregion
}

void ManualScene::Finalize()
{
	// スプライト解放
	delete sprite;
}

void ManualScene::Updata()
{
	Input* input = Input::GetInstacne();
	if (input->TriggerKey(DIK_SPACE))
	{
		// シーン切り替え
		SceneManager::GetInstance()->ChangeScene("TITLE");
	}

	sprite->Updata();
}

void ManualScene::Draw()
{
	// スプライト前処理
	SpriteCommon::GetInstance()->PreDraw();
	// スプライト描画
	sprite->Draw();

}