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
	field = Field::Create();
	// グランド生成
	model_Ground = Model::LoadFromOBJ("debugField");
	obj_Ground = Object3d::Create(model_Ground);
}

void PlayScene::Finalize()
{
	// プレイヤー解放
	delete player;
	// エネミー解放
	delete enemy;
	// フィールド解放
	delete field;
	// グランド解放
	delete model_Ground;
	delete obj_Ground;
}

void PlayScene::Updata()
{

	for (int i = 0; i < 8; i++)
	{
		if (Collision::SphereSphere(player->GetPos(), 0.5f, enemy->GetPos(i), 1.0f))
		{
			// シーン切り替え
			SceneManager::GetInstance()->ChangeScene("END");
			break;
		}
	}

	if (player->GetPos().x < -5.0f)
	{
		// シーン切り替え
		SceneManager::GetInstance()->ChangeScene("END");
	}

	// グランド更新
	obj_Ground->Update();
	// プレイヤー更新
	player->Update();
	// エネミー更新
	enemy->Update(player->GetPos());
	// フィールド更新
	field->Update(player->GetPos());
}

void PlayScene::Draw()
{
	// 3Dオブジェクト描画前処理
	Object3d::PreDraw();
	// グランド描画
	//obj_Ground->Draw();
	// プレイヤー描画
	player->Draw();
	// エネミー描画
	enemy->Draw();
	// フィールド描画
	field->Draw();
	// スプライト前処理
	SpriteCommon::GetInstance()->PreDraw();
	//デバッグテキスト描画
	// カメラ座標
	sprintf_s(strDebug, "Speed = %f  Flag = %d", player->GetSpeed().z, enemy->Get1());
	DebugText::GetInstance()->Print(strDebug, 0, 0, 2);
	DebugText::GetInstance()->DrawAll();

}