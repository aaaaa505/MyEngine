#include "MyGame.h"
#include "PlayScene.h"

void MyGame::Initialize()
{
	// 基底クラスの初期化
	FrameWork::Initialize();

	// プレイシーン初期化
	scene = new PlayScene();
	scene->Initialize();
}

void MyGame::Finalize()
{
	// シーンクラスの終了処理
	scene->Finalize();

	// 基底クラスの終了処理
	FrameWork::Finalize();
}

void MyGame::Updata()
{
	scene->Updata();

	// 基底クラスの更新処理
	FrameWork::Updata();
}

void MyGame::Draw()
{
	// 描画前処理
	dxCommon->PreDraw();
	
	// シーン描画
	scene->Draw();

	// デバッグテキスト描画
	debugText->DrawAll();

	//描画後処理
	dxCommon->PostDraw();
}
