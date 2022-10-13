#include "MyGame.h"

void MyGame::Initialize()
{
	// 基底クラスの初期化
	FrameWork::Initialize();

#pragma region オブジェクト
	//OBJからモデルデータを読み込む
	model = Model::LoadFromOBJ("player_N");
	//3Dオブジェクトの生成
	object3d = Object3d::Create();
	//オブジェクトにモデルをひも付ける
	object3d->SetModel(model);

	camera->SetTarget({ 0.0f, 0.5f, 0.1f });
	camera->SetEye({ 0.0f, 4.0f, -10.0f });
#pragma endregion

#pragma region スプライト
	//スプライト生成
	sprite = Sprite::Create(spriteCommon, sample2, { 0.0f, 0.0f });
	sprite->SetSize({ 100.0f, 100.0f });

#pragma endregion
}

void MyGame::Finalize()
{
	delete sprite;
	delete object3d;
	delete model;

	// 基底クラスの終了処理
	FrameWork::Finalize();
}

void MyGame::Updata()
{
	// 基底クラスの更新処理
	FrameWork::Updata();

#pragma region DirectX毎フレーム処理
	//DirectX毎フレーム処理　ここから
	camera->MoveCamera(input, 0.5f);

	//更新
	object3d->Update();
	sprite->Updata();
	//DirectX毎フレーム処理　ここまで
#pragma endregion DirectX毎フレーム処理
}

void MyGame::Draw()
{
	// 描画前処理
	dxCommon->PreDraw();
	// 3Dオブジェクト描画前処理
	Object3d::PreDraw(dxCommon->GetCmdList());

	// 3Dオブジェクト描画
	object3d->Draw();

	// 3Dオブジェクト後処理
	Object3d::PostDraw();

	// スプライト前処理
	spriteCommon->PreDraw(dxCommon->GetCmdList());

	//sprite->Draw();
	//デバッグテキスト描画
	/*XMFLOAT3 position = obj_Player->GetRotation();
	sprintf_s(strDebug, "%f  %f   %f", position.x, position.y, position.z);
	debugText->Print(strDebug, 0, 0, 2);
	debugText->DrawAll();*/

	// スプライト後処理
	spriteCommon->PostDraw();
	//描画後処理
	dxCommon->PostDraw();
}
