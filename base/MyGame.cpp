#include "MyGame.h"
#include "SceneFactory.h"

void MyGame::Initialize()
{
	// 基底クラスの初期化
	FrameWork::Initialize();

	// シーンファクトリー生成
	sceneFactory = new SceneFactory();
	SceneManager::GetInstance()->SetSceneFactory(sceneFactory);

	// シーンマネージャーに最初のシーンをセット
	SceneManager::GetInstance()->ChangeScene("TITLE");
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
