#include "PlayScene.h"
#include "TitleScene.h"
#include "Input.h"
#include "DebugText.h"
#include "SceneManager.h"
#include "Collision.h"

void PlayScene::Initialize()
{
	// プレイヤー生成
	player = Player::Create();
	// エネミー生成
	enemy = Enemy::Create();
	// フィールド生成
	scroll = Scroll::Create();
}

void PlayScene::Finalize()
{
	// プレイヤー解放
	delete player;
	// エネミー解放
	delete enemy;
	// フィールド解放
	delete scroll;
}

void PlayScene::Updata()
{

	//if (player->GetPos().x < -5.0f)
	//{
	//	// シーン切り替え
	//	SceneManager::GetInstance()->ChangeScene("END");
	//}

	// プレイヤー更新
	player->Update();
	// エネミー更新
	enemy->Update(player->GetPos());
	// フィールド更新
	scroll->Update(player->GetPos());
}

void PlayScene::Draw()
{
	// 3Dオブジェクト描画前処理
	Object3d::PreDraw();

	// プレイヤー描画
	player->Draw();
	// エネミー描画
	enemy->Draw();
	// フィールド描画
	scroll->Draw();
	// スプライト前処理
	SpriteCommon::GetInstance()->PreDraw();
	//デバッグテキスト描画
	
	sprintf_s(strDebug, "CreateTimer = %d  PlayerPos = %f", enemy->GetCreateTimer(), player->GetPos().x);
	DebugText::GetInstance()->Print(strDebug, 0, 0, 2);
	DebugText::GetInstance()->DrawAll();

}