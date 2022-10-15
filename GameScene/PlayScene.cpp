#include "PlayScene.h"
#include "TitleScene.h"
#include "Input.h"
#include "DebugText.h"
#include "SceneManager.h"

void PlayScene::Initialize()
{
	// グランド生成
	model_Ground = Model::LoadFromOBJ("ground");
	obj_Ground = Object3d::Create(model_Ground);
	// ロード生成
	model_Road = Model::LoadFromOBJ("load");
	obj_Road = Object3d::Create(model_Road);
	// プレイヤー生成
	player = Player::Create();
}

void PlayScene::Finalize()
{
	// グランド解放
	delete model_Ground;
	delete obj_Ground;
	delete model_Road;
	delete obj_Road;
	delete player;
}

void PlayScene::Updata()
{
	Input* input = Input::GetInstacne();
	if (input->TriggerKey(DIK_SPACE))
	{
		// シーン切り替え
		SceneManager::GetInstance()->ChangeScene("TITLE");
	}

	// グランド更新
	obj_Ground->Update();
	// ロード更新
	obj_Road->Update();
	// プレイヤー更新
	player->Update();
}

void PlayScene::Draw()
{
	// 3Dオブジェクト描画前処理
	Object3d::PreDraw();
	// グランド描画
	obj_Ground->Draw();
	// ロード描画
	obj_Road->Draw();
	// プレイヤー描画
	player->Draw();
	// スプライト前処理
	SpriteCommon::GetInstance()->PreDraw();
	//デバッグテキスト描画
	// カメラ座標
	sprintf_s(strDebug, "%f   %f", player->GetPos().z, player->GetEye().z);
	DebugText::GetInstance()->Print(strDebug, 0, 0, 2);
	DebugText::GetInstance()->DrawAll();

}