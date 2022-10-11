#include "Input.h"
#include "WinApp.h"
#include "DirectXCommon.h"
#include "Object3d.h"
#include "SpriteCommon.h"
#include "Sprite.h"
#include "DebugText.h"
#include "LoadSprite.h"
#include "PostEffect.h"
#include "Camera.h"

using namespace DirectX;
using namespace Microsoft::WRL;

//Windowsアプリのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	HRESULT result;

#pragma region 汎用クラス
	//生成&初期化
	WinApp* winApp = nullptr;
	winApp = new WinApp();
	winApp->Initialize();

	DirectXCommon* dxCommon = nullptr;
	dxCommon = new DirectXCommon();
	dxCommon->initialize(winApp);

	Input* input = nullptr;
	input = new Input();
	input->Initialize(winApp);

	//スプライト共通部分を確保
	SpriteCommon* spriteCommon = nullptr;
	spriteCommon = new SpriteCommon();
	//確保したスプライト共通部分インスタンスを初期化
	spriteCommon->Initialize(dxCommon->Getdev(), dxCommon->GetCmdList(), WinApp::window_width, WinApp::window_height);
#pragma endregion

#pragma region オブジェクト
	//カメラ生成
	Camera* camera = new Camera(WinApp::window_width, WinApp::window_height);
	
	Object3d::StaticInitialize(dxCommon->Getdev());

	Object3d::SetCamera(camera);
	//OBJからモデルデータを読み込む
	Model* model_Ground = Model::LoadFromOBJ("ground");
	Model* model_Skydome = Model::LoadFromOBJ("skydome");
	Model* model_Player = Model::LoadFromOBJ("player_N");
	//3Dオブジェクトの生成
	Object3d* obj_Ground = Object3d::Create();
	Object3d* obj_Skydome = Object3d::Create();
	//Object3d* obj_Player = Object3d::Create();
	std::unique_ptr<Object3d> obj_Player(Object3d::Create());
	//オブジェクトにモデルをひも付ける
	obj_Ground->SetModel(model_Ground);
	obj_Skydome->SetModel(model_Skydome);
	obj_Player->SetModel(model_Player);
	obj_Player->SetPosition({ 0.0f, 0.5f, 0.0f });
	obj_Player->SetRotation({ 0.0f, 90.0f, 0.0f });

	camera->SetTarget({ 0.0f, 0.5f, 0.1f });
	camera->SetEye({0.0f, 4.0f, -10.0f});
#pragma endregion

#pragma region スプライト
	LoadSprite::StaticInitialize(spriteCommon);

	//デバッグテキスト生成
	DebugText* debugText = DebugText::Create(spriteCommon, debugTextTexNumber);
	debugText->Initialize(spriteCommon, debugTextTexNumber);
	char strDebug[100];

	//スプライト生成
	Sprite* sprite = Sprite::Create(spriteCommon, sample2, { 0.0f, 0.0f });

	sprite->SetSize({ 100.0f, 100.0f });

#pragma endregion

	//ポストエフェクト
	PostEffect* postEffect = new PostEffect();
	postEffect->Initialize(dxCommon->Getdev());
	

	while (true)//ゲームループ
	{
#pragma region ウィンドウメッセージ処理
		if (winApp->ProcessMessage()) {
			//ゲームループから抜ける
			break;
		}
#pragma endregion ウィンドウメッセージ処理

#pragma region DirectX毎フレーム処理
		//DirectX毎フレーム処理　ここから
		camera->MoveCamera(input, 0.5f);
		
		//更新
		obj_Ground->Update();
		obj_Skydome->Update();
		obj_Player->Update();
		sprite->Updata();
		input->Updata();
		camera->Update();

		//DirectX毎フレーム処理　ここまで
#pragma endregion DirectX毎フレーム処理

#pragma region グラフィックスコマンド
		dxCommon->PreDraw();
		//3Dオブジェクト描画前処理
		Object3d::PreDraw(dxCommon->GetCmdList());

		//3Dオブジェクト描画
		obj_Player->Draw();
		obj_Skydome->Draw();
		obj_Ground->Draw();

		//3Dオブジェクト後処理
		Object3d::PostDraw();

		//スプライト共通コマンド
		spriteCommon->PreDraw(dxCommon->GetCmdList());

		//sprite->Draw();
		//デバッグテキスト描画
		XMFLOAT3 position = obj_Player->GetRotation();
		sprintf_s(strDebug, "%f  %f   %f", position.x, position.y, position.z);
		debugText->Print(strDebug, 0, 0, 2);
		debugText->DrawAll();

		spriteCommon->PostDraw();
		//描画後処理
		dxCommon->PostDraw();
		
		// test

		//postEffect->PreDrawScene(dxCommon->GetCmdList());
		////3Dオブジェクト描画前処理
		//Object3d::PreDraw(dxCommon->GetCmdList());

		////3Dオブジェクト描画
		//obj_Player->Draw();

		////3Dオブジェクト後処理
		//Object3d::PostDraw();

		////スプライト共通コマンド
		//spriteCommon->PreDraw(dxCommon->GetCmdList());

		////sprite->Draw();
		////デバッグテキスト描画
		////XMFLOAT3 position = obj_Player->GetPosition();
		////sprintf_s(strDebug, "x = %f  y = %f  z = %f", position.x, position.y, position.z);
		////debugText->Print(strDebug, 0, 0, 2);
		////debugText->DrawAll();

		//spriteCommon->PostDraw();
		//postEffect->PostDrawScene(dxCommon->GetCmdList());
		//// ４描画コマンドここまで
		 // //描画前処理
		//dxCommon->PreDraw();
		////ポストエフェクト描画
		//postEffect->Draw(dxCommon->GetCmdList());
		//


		////描画後処理
		//dxCommon->PostDraw();
		
	}

	//クラスの解放
	delete dxCommon;
	delete input;
	delete spriteCommon;
	delete obj_Ground;
	delete obj_Skydome;
	delete model_Ground;
	delete sprite;
	delete debugText;
	delete camera;


#pragma region WindowsAPI後始末
	winApp->Finalize();
	delete winApp;
#pragma endregion WindowsAPI後始末

	return 0;
}
