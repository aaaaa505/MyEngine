#include "TitleScene.h"
#include "Input.h"
#include "DebugText.h"
#include "SceneManager.h"
#include "PlayScene.h"

TitleScene::TitleScene(SceneManager* sceneManager)
	:BaseScene(sceneManager)
{

}

void TitleScene::Initialize()
{
#pragma region スプライト
	// スプライト生成
	sprite = Sprite::Create(title_Number, { 0.0f, 0.0f });
#pragma endregion
}

void TitleScene::Finalize()
{
	// スプライト解放
	delete sprite;
}

void TitleScene::Updata()
{
	Input* input = Input::GetInstacne();
	if (input->Triggerkey(DIK_SPACE))
	{
		// シーン切り替え
		BaseScene* scene = new PlayScene(sceneManager);
		sceneManager->SetNextScene(scene);
	}

	sprite->Updata();
}

void TitleScene::Draw()
{
	// スプライト前処理
	SpriteCommon::GetInstance()->PreDraw();
	// スプライト描画
	sprite->Draw();

}