#include "MyGame.h"
#include "PlayScene.h"
#include "TitleScene.h"

void MyGame::Initialize()
{
	// 基底クラスの初期化
	FrameWork::Initialize();

	// シーン初期化
	BaseScene* scene = new TitleScene(sceneManager);
	// シーンマネージャーに最初のシーンをセット
	sceneManager->SetNextScene(scene);
}

void MyGame::Finalize()
{
	// 基底クラスの終了処理
	FrameWork::Finalize();
}

void MyGame::Updata()
{
	// 基底クラスの更新処理
	FrameWork::Updata();
}

void MyGame::Draw()
{
	// 基底クラスの描画処理
	FrameWork::Draw();
}
