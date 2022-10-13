#include "PlayScene.h"
#include "Input.h"
#include "DebugText.h"
#include "SpriteCommon.h"

void PlayScene::Initialize()
{
#pragma region オブジェクト
	// カメラ生成＆セット
	camera = new Camera(WinApp::window_width, WinApp::window_height);
	Object3d::SetCamera(camera);


	// OBJからモデルデータを読み込む
	model = Model::LoadFromOBJ("player_N");
	// 3Dオブジェクトの生成
	object3d = Object3d::Create();
	// オブジェクトにモデルをひも付ける
	object3d->SetModel(model);

	camera->SetTarget({ 0.0f, 0.5f, 0.1f });
	camera->SetEye({ 0.0f, 4.0f, -10.0f });
#pragma endregion

#pragma region スプライト
	// スプライト生成
	sprite = Sprite::Create(title_Number, { 0.0f, 0.0f });
#pragma endregion
}

void PlayScene::Finalize()
{
	// カメラ解放
	delete camera;
	// スプライト解放
	delete sprite;
	// オブジェクト解放
	delete object3d;
	// モデル解放
	delete model;
}

void PlayScene::Updata()
{
#pragma region DirectX毎フレーム処理
	Input* input = Input::GetInstacne();

	//DirectX毎フレーム処理　ここから
	camera->MoveCamera(input, 0.5f);

	//更新
	object3d->Update();
	sprite->Updata();
	camera->Update();
	//DirectX毎フレーム処理　ここまで
#pragma endregion DirectX毎フレーム処理
}

void PlayScene::Draw()
{
	// 3Dオブジェクト描画前処理
	Object3d::PreDraw();

	// 3Dオブジェクト描画
	object3d->Draw();

	// スプライト前処理
	SpriteCommon::GetInstance()->PreDraw();

	sprite->Draw();
	//デバッグテキスト描画
	sprintf_s(strDebug, "Test");
	DebugText::GetInstance()->Print(strDebug, 0, 0, 2);
	DebugText::GetInstance()->DrawAll();

}