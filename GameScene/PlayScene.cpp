#include "PlayScene.h"
#include "TitleScene.h"
#include "Input.h"
#include "DebugText.h"
#include "SceneManager.h"

void PlayScene::Initialize()
{
	// グランド生成
	model = Model::LoadFromOBJ("ground");
	obj = Object3d::Create(model);
	// プレイヤー生成
	player = Player::Create();
}

void PlayScene::Finalize()
{
	// グランド解放
	delete model;
	delete obj;
	delete player;
}

void PlayScene::Updata()
{
	Input* input = Input::GetInstacne();
	if (input->Triggerkey(DIK_SPACE))
	{
		// シーン切り替え
		SceneManager::GetInstance()->ChangeScene("TITLE");
	}

	// グランド更新
	obj->Update();
	// プレイヤー更新
	player->Update();
}

void PlayScene::Draw()
{
	// 3Dオブジェクト描画前処理
	Object3d::PreDraw();
	// グランド描画
	obj->Draw();
	// プレイヤー描画
	player->Draw();
	// スプライト前処理
	SpriteCommon::GetInstance()->PreDraw();
	//デバッグテキスト描画
	// カメラ座標
	sprintf_s(strDebug, "%f  %f", player->GetEye().x, player->GetPos().x);
	DebugText::GetInstance()->Print(strDebug, 0, 0, 2);
	DebugText::GetInstance()->DrawAll();

}