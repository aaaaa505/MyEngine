#include "PlayScene.h"
#include "TitleScene.h"
#include "Input.h"
#include "DrawNumber.h"
#include "SceneManager.h"
#include "Collision.h"
#include "Audio.h"

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

	// スコア
	sprite = Sprite::Create(scoreBar_Number, { 0.0f, 0.0f });
	crash = Sprite::Create(crash_Number, { 0.0f, 0.0f });
	result = Sprite::Create(result_Number, { 0.0f, 0.0f });
	//Audio::GetInstance()->LoadWave("crash.wav");
}

void PlayScene::Finalize()
{
	// プレイヤー解放
	delete player;
	// エネミー解放
	delete enemy;
	// フィールド解放
	delete scroll;

	delete sprite;
	delete result;
	delete crash;
	delete countDown;
}

void PlayScene::Updata()
{
	for (int i = 0; i < enemy->GetDataSize() && !resultFlag; i++)
	{
		if (enemy->GetModelFlag(i) == car)
		{
			if (Collision::BoxToBox(player->GetPos(), { RADIUS_X, RADIUS_Z }, enemy->GetPos(i), {CAR_RADIUS_X, CAR_RADIUS_Z}))
			{
				// シーン切り替え
				//SceneManager::GetInstance()->ChangeScene("END");
				hitFlag = true;
				player->SetHitFlag(hitFlag);
				//Audio::GetInstance()->PlayWave("crash.wav", false);
				break;
			}
		}
		else
		{
			if (Collision::BoxToBox(player->GetPos(), { RADIUS_X, RADIUS_Z }, enemy->GetPos(i), { TRACK_RADIUS_X, TRACK_RADIUS_Z }))
			{
				// シーン切り替え
				//SceneManager::GetInstance()->ChangeScene("END");
				hitFlag = true;
				player->SetHitFlag(hitFlag);
				//Audio::GetInstance()->PlayWave("crash.wav", false);
				break;
			}
		}
	}

	if (!hitFlag)
	{
		if (countDown->GetStartFlag())
		{
			if (player->GetSpeed().z < 1.0f && player->GetSpeed().z >= 0.1f)
			{
				scoreTimer--;
				if (scoreTimer <= 0)
				{
					scoreTimer = 20;
					score++;
				}
			}
			else
			{
				scoreTimer--;
				if (scoreTimer <= 0)
				{
					scoreTimer = 10;
					score++;
				}
			}
		}
	}
	else
	{
		sceneChangeTimer--;
		if (sceneChangeTimer < 0)
		{
			//Audio::GetInstance()->StopWave("crash.wav");
			resultFlag = true;
		}
	}

	if (player->GetPos().x > 7.0f || player->GetPos().x < -7.0f)
	{
		hitFlag = true;
		player->SetHitFlag(hitFlag);
	}

	sprintf_s(str, "%d", (int)score);
	if (resultFlag)
	{
		
		DrawNumber::GetInstance()->Updata(str, { 570.0f, 380.0f }, 2.0f);
		if (Input::GetInstacne()->TriggerKey(DIK_SPACE))
		{
			SceneManager::GetInstance()->ChangeScene("TITLE");
		}
	}
	else
	{
		DrawNumber::GetInstance()->Updata(str, { 100.0f, 25.0f }, 0.7f);
	}



	// プレイヤー更新
	player->Update(countDown->GetStartFlag());
	// エネミー更新
	enemy->Update(player->GetPos(), player->GetSpeed().z, hitFlag);
	// フィールド更新
	scroll->Update(player->GetPos());

	if (!countDown->GetStartFlag()){ countDown->Update(); }
	
	//sprite->Updata();
	//crash->Updata();
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
	sprite->Draw();
	if (hitFlag){ crash->Draw(); }
	if (resultFlag) { result->Draw(); }
	DrawNumber::GetInstance()->DrawAll();
}
