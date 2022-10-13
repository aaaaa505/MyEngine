#include "MyGame.h"

void MyGame::Initialize()
{
	//生成&初期化
	winApp = new WinApp();
	winApp->Initialize();

	dxCommon = new DirectXCommon();
	dxCommon->initialize(winApp);

	input = new Input();
	input->Initialize(winApp);

	spriteCommon = new SpriteCommon();
	//確保したスプライト共通部分インスタンスを初期化
	spriteCommon->Initialize(dxCommon->Getdev(), dxCommon->GetCmdList(), WinApp::window_width, WinApp::window_height);


#pragma region オブジェクト
	//カメラ生成
	camera = new Camera(WinApp::window_width, WinApp::window_height);

	Object3d::StaticInitialize(dxCommon->Getdev());

	Object3d::SetCamera(camera);
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
	LoadSprite::StaticInitialize(spriteCommon);

	//デバッグテキスト生成
	debugText = DebugText::Create(spriteCommon, debugTextTexNumber);
	debugText->Initialize(spriteCommon, debugTextTexNumber);

	//スプライト生成
	sprite = Sprite::Create(spriteCommon, sample2, { 0.0f, 0.0f });
	sprite->SetSize({ 100.0f, 100.0f });

#pragma endregion
}

void MyGame::Finalize()
{
	//クラスの解放
	delete dxCommon;
	delete input;
	delete spriteCommon;
	delete sprite;
	delete object3d;
	delete model;
	delete debugText;
	delete camera;


#pragma region WindowsAPI後始末
	winApp->Finalize();
	delete winApp;
#pragma endregion WindowsAPI後始末
}

void MyGame::Updata()
{
#pragma region ウィンドウメッセージ処理
	if (winApp->ProcessMessage()) {
		//ゲームループから抜ける
		endRequest = true;
		return;
	}
#pragma endregion ウィンドウメッセージ処理

#pragma region DirectX毎フレーム処理
	//DirectX毎フレーム処理　ここから
	camera->MoveCamera(input, 0.5f);

	//更新g
	object3d->Update();
	sprite->Updata();
	input->Updata();
	camera->Update();

	//DirectX毎フレーム処理　ここまで
#pragma endregion DirectX毎フレーム処理
}

void MyGame::Draw()
{
	dxCommon->PreDraw();
	//3Dオブジェクト描画前処理
	Object3d::PreDraw(dxCommon->GetCmdList());

	//3Dオブジェクト描画
	object3d->Draw();

	//3Dオブジェクト後処理
	Object3d::PostDraw();

	//スプライト共通コマンド
	spriteCommon->PreDraw(dxCommon->GetCmdList());

	//sprite->Draw();
	//デバッグテキスト描画
	/*XMFLOAT3 position = obj_Player->GetRotation();
	sprintf_s(strDebug, "%f  %f   %f", position.x, position.y, position.z);
	debugText->Print(strDebug, 0, 0, 2);
	debugText->DrawAll();*/

	spriteCommon->PostDraw();
	//描画後処理
	dxCommon->PostDraw();
}
