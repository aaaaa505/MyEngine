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
	// カウントダウン生成
	countDown = CountDown::Create();
}

void PlayScene::Finalize()
{
	// プレイヤー解放
	delete player;
	// エネミー解放wwwwwww
	delete enemy;
	// フィールド解放
	delete scroll;
}

void PlayScene::Updata()
{
	for (int i = 0; i < enemy->GetDataSize(); i++)
	{
		if (enemy->GetModelFlag(i) == car)
		{
			if (Collision::BoxToBox(player->GetPos(), { RADIUS_X, RADIUS_Z }, enemy->GetPos(i), {CAR_RADIUS_X, CAR_RADIUS_Z}))
			{
				// シーン切り替え
				SceneManager::GetInstance()->ChangeScene("END");
				break;
			}
		}
		else
		{
			if (Collision::BoxToBox(player->GetPos(), { RADIUS_X, RADIUS_Z }, enemy->GetPos(i), { TRACK_RADIUS_X, TRACK_RADIUS_Z }))
			{
				// シーン切り替え
				SceneManager::GetInstance()->ChangeScene("END");
				break;
			}
		}
	}

	

	// プレイヤー更新
	player->Update(countDown->GetStartFlag());
	// エネミー更新
	enemy->Update(player->GetPos(), player->GetSpeed().z);
	// フィールド更新
	scroll->Update(player->GetPos());

	if (!countDown->GetStartFlag()){ countDown->Update(); }
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
	if (!countDown->GetStartFlag()) { countDown->Draw(); }
	sprintf_s(strDebug, "11111");
	DebugText::GetInstance()->Print(strDebug, 0.0f, 0.0f, 2);
	DebugText::GetInstance()->DrawAll();
}