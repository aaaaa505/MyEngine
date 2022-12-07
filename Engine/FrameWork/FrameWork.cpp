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

	// オーディオの初期化
	audio = Audio::GetInstance();
	if (!audio->Initialize())
	{
		assert(0);
	}

	// 確保したスプライト共通部分インスタンスを初期化
	spriteCommon = SpriteCommon::GetInstance();
	spriteCommon->Initialize(dxCommon->Getdev(), dxCommon->GetCmdList(), WinApp::window_width, WinApp::window_height);

	// ロードスプライト静的初期化
	LoadSprite::StaticInitialize(spriteCommon);

	// デバッグテキスト生成
	debugText = DebugText::GetInstance();
	debugText->Initialize(debugTextTexNumber);

	// Drawナンバー生成
	drawNumber = DrawNumber::GetInstance();
	drawNumber->Initialize(NumberNumber);

	// オブジェクト3Dの静的初期化
	Object3d::StaticInitialize(dxCommon->Getdev(), dxCommon->GetCmdList());

}

void FrameWork::Finalize()
{
	// シーンファクトリー解放
	delete sceneFactory;
	// DirectX基盤クラス解放
	delete dxCommon;
	// デバッグテキストの終了処理
	debugText->Finalize();
	// DrawNumberの終了処理
	drawNumber->Finalize();
	// WindowsAPIの終了処理
	winApp->Finalize();
	// WindowsAPIクラス解放
	delete winApp;
}

void FrameWork::Run()
{
	// 初期化
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
	// Windowsメッセージの処理
	if (winApp->ProcessMessage()) {
		// ゲームループから抜ける
		endRequest = true;
		return;
	}

	// 入力の更新
	input->Updata();

	// シーンの更新
	SceneManager::GetInstance()->Updata();
}

void FrameWork::Draw()
{
	// 描画前処理
	dxCommon->PreDraw();

	// シーン描画
	SceneManager::GetInstance()->Draw();

	// デバッグテキスト描画
	debugText->DrawAll();

	//描画後処理
	dxCommon->PostDraw();
}
