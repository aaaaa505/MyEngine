#include "FrameWork.h"

void FrameWork::Initialize()
{
	// 汎用クラス初期化
	winApp = new WinApp();
	winApp->Initialize();

	// DirectX基盤クラス初期化
	dxCommon = new DirectXCommon();
	dxCommon->initialize(winApp);

	// 入力クラス初期化
	input = Input::GetInstacne();
	input->Initialize(winApp);

	// 確保したスプライト共通部分インスタンスを初期化
	spriteCommon = SpriteCommon::GetInstance();
	spriteCommon->Initialize(dxCommon->Getdev(), dxCommon->GetCmdList(), WinApp::window_width, WinApp::window_height);

	// ロードスプライト静的初期化
	LoadSprite::StaticInitialize(spriteCommon);

	// デバッグテキスト生成
	debugText = DebugText::GetInstance();
	debugText->Initialize(debugTextTexNumber);

	// オブジェクト3Dの静的初期化
	Object3d::StaticInitialize(dxCommon->Getdev(), dxCommon->GetCmdList());
}

void FrameWork::Finalize()
{
	// クラスの解放
	delete dxCommon;
	debugText->Finalize();
	winApp->Finalize();
	delete winApp;
}

void FrameWork::Run()
{
	// ゲームの初期化
	Initialize();

	while (true)// ゲームループ
	{
		// 毎フレーム更新
		Updata();
		// 終了リクエストが来たら抜ける
		if (endRequest)
		{
			break;
		}
		// 描画
		Draw();
	}

	// 終了処理
	Finalize();
}

void FrameWork::Updata()
{
	if (winApp->ProcessMessage()) {
		// ゲームループから抜ける
		endRequest = true;
		return;
	}

	input->Updata();
}

void FrameWork::Draw()
{
}
