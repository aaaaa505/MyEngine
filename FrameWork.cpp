#include "FrameWork.h"

void FrameWork::Initialize()
{
	// 汎用クラス初期化
	winApp = new WinApp();
	winApp->Initialize();

	dxCommon = new DirectXCommon();
	dxCommon->initialize(winApp);

	input = new Input();
	input->Initialize(winApp);

	//確保したスプライト共通部分インスタンスを初期化
	spriteCommon = new SpriteCommon();
	spriteCommon->Initialize(dxCommon->Getdev(), dxCommon->GetCmdList(), WinApp::window_width, WinApp::window_height);

	// ロードスプライト静的初期化
	LoadSprite::StaticInitialize(spriteCommon);

	//デバッグテキスト生成
	debugText = DebugText::Create(spriteCommon, debugTextTexNumber);
	debugText->Initialize(spriteCommon, debugTextTexNumber);

	// オブジェクト3Dの静的初期化
	Object3d::StaticInitialize(dxCommon->Getdev());

	//カメラ生成＆セット
	camera = new Camera(WinApp::window_width, WinApp::window_height);
	Object3d::SetCamera(camera);

}

void FrameWork::Finalize()
{
	//クラスの解放
	delete dxCommon;
	delete input;
	delete spriteCommon;
	delete debugText;
	delete camera;
	winApp->Finalize();
	delete winApp;
}

void FrameWork::Updata()
{
	if (winApp->ProcessMessage()) {
		//ゲームループから抜ける
		endRequest = true;
		return;
	}

	input->Updata();
	camera->Update();
}

void FrameWork::Draw()
{
}
