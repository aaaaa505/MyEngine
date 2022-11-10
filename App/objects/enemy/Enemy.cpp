#include "Enemy.h"
#include <stdlib.h>
#include <time.h>
#include "Input.h"

Enemy* Enemy::Create()
{
	// インスタンスの生成
	Enemy* instance = new Enemy();

	// インスタンスの初期化
	instance->Initialize();

	// インスタンスを返す
	return instance;
}

Enemy::~Enemy()
{
	// モデル解放
	for (int i = 0; i < MAX_MODEL; i++)
	{
		delete model[i];
	}
	// オブジェクト解放
	for (auto& object : objects)
	{
		delete object;
	}
	// スピード情報解放
	speeds.clear();
	// モデルフラッグ解放
	modelFlags.clear();
}

void Enemy::Initialize()
{
	srand(time(NULL));
	// モデル読み込み
	model[car] = Model::LoadFromOBJ("car");
	model[track] = Model::LoadFromOBJ("track");
	// 生成時間
	for (int i = 0; i < MAX_TIMER; i++)
	{
		createTimer[i] = (rand() % RANDTIMER_MAX) + RANDTIMER_MINI;
	}
	// 存在フラッグ
	existenceFlag = false;
}

void Enemy::AutoSprint(int number)
{
	XMFLOAT3 pos = objects[number]->GetPosition();
	pos.z += speeds[number];
	objects[number]->SetPosition(pos);
}

DirectX::XMFLOAT3 Enemy::RandPos(int number)
{
	if (number == left_Second)
	{
		return { -SIDELINE, 0.0f, player_Pos.z + BASEPOS };
	}
	else if (number == left_First)
	{
		return { -CENTERLINER, 0.0f, player_Pos.z + BASEPOS };
	}
	else if (number == right_First)
	{
		return { CENTERLINER, 0.0f, player_Pos.z + BASEPOS };
	}
	else
	{
		return { SIDELINE, 0.0f, player_Pos.z + BASEPOS };
	}
}

short Enemy::RandModel()
{
	modelFlags.push_back(rand() % MAX_MODEL);
	return modelFlags[objects.size()];
}

float Enemy::RandSpeed()
{
	int randFlag = rand() % MAX_SPEED;
	if (randFlag == First)
	{
		return BottonSpeed;
	}
	else if (randFlag == Second)
	{
		return MiddleSpeed;
	}
	else
	{
		return TopSpeed;
	}
	
}

void Enemy::Update(const XMFLOAT3& playerPos, const float& playerSpeed)
{	
	// プレイヤーの座標を格納
	player_Pos = playerPos;
	player_Speed = playerSpeed;

	// タイマー
	for (int i = 0; i < MAX_TIMER; i++)
	{
		createTimer[i]--;
		if (createTimer[i] <= 0)
		{
			createTimer[i] = (rand() % RANDTIMER_MAX) + RANDTIMER_MINI;
			speeds.push_back(RandSpeed());
			objects.push_back(Object3d::Create(RandPos(i), model[RandModel()]));
		}
	}


	
	for (int i = 0; i < objects.size(); i++)
	{
		// 自動走行
		AutoSprint(i);
		//　プレイヤーがエネミーを追い越したら
		if (objects[i]->GetPosition().z < playerPos.z - 20.0f)
		{
			// データを解放
			objects.erase(objects.begin() + i);
			speeds.erase(speeds.begin() + i);
			modelFlags.erase(modelFlags.begin() + i);
			break;
		}
		// オブジェクトデータ更新
		objects[i]->Update();
	}
}

void Enemy::Draw()
{
	
	for (int i = 0; i < objects.size(); i++)
	{
		// オブジェクトデータ更新
		objects[i]->Draw();
	}
}

const DirectX::XMFLOAT3& Enemy::GetPos(const int& number)
{
	// データがあれば
	if (!objects.empty())
	{
		return objects[number]->GetPosition();
	}
	else
	{
		return { 0.0f, 0.0f, 0.0 };
	}
}

const bool& Enemy::GetModelFlag(const int& number)
{
	// データがあれば
	if (!modelFlags.empty())
	{
		return modelFlags[number];
	}
	else
	{
		return false;
	}
}
