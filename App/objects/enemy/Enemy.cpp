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
	//　オブジェクト解放
	for (int i = 0; i < objects.size(); i++)
	{
		delete objects[i];
	}
}

void Enemy::Initialize()
{
	// モデル読み込み
	model[car] = Model::LoadFromOBJ("car");
	model[track] = Model::LoadFromOBJ("track");
	// 生成時間
	createTimer = 90;
	// 存在フラッグ
	existenceFlag = false;
}

void Enemy::AutoSprint(int i)
{
	XMFLOAT3 pos = objects[i]->GetPosition();
	pos.z += speeds[i];
	objects[i]->SetPosition(pos);
}

int Enemy::RandValue(const int maxValue, const int miniValue)
{
	if (miniValue == 0)
	{
		return rand() % maxValue;
	}
	else
	{
		return (rand() % maxValue) + miniValue;
	}
}

DirectX::XMFLOAT3 Enemy::RandPos()
{
	int randFlag = rand() % 4;
	if (randFlag == 0)
	{
		return { -5.3f, 0.0f, player_Pos.z + 310.0f };
	}
	else if (randFlag == 1)
	{
		return { -1.8f, 0.0f, player_Pos.z + 310.0f };
	}
	else if (randFlag == 2)
	{
		return { 1.8f, 0.0f, player_Pos.z + 310.0f };
	}
	else
	{
		return { 5.3f, 0.0f, player_Pos.z + 310.0f };
	}
}

short Enemy::RandModel()
{
	modelFlag.push_back(rand() % MAX_MODEL);
	return modelFlag[objects.size()];
}

int Enemy::RandTimer()
{
	if (player_Speed > 0.0f && player_Speed <= 0.5f)
	{
		return (rand() % 10) + 80;
	}
	else if (player_Speed > 0.5f && player_Speed <= 1.0f)
	{
		return (rand() % 10) + 40;
	}
	else
	{
		return (rand() % 10) + 20;
	}
}

void Enemy::Update(const XMFLOAT3& playerPos, const float& playerSpeed)
{	
	// プレイヤーの座標を格納
	player_Pos = playerPos;
	player_Speed = playerSpeed;

	// タイマー
	createTimer--;
	if (createTimer <= 0)
	{
		// 0.1 90  1.5 20
		// ※
		createTimer = RandTimer();
		// ※
		speeds.push_back(0.5f);
		objects.push_back(Object3d::Create(RandPos(), model[RandModel()]));

	}


	if (!objects.empty())
	{
		for (int i = 0; i < objects.size(); i++)
		{
			// 自動走行
			AutoSprint(i);
			//　プレイヤーがエネミーを追い越したら
			if (objects[i]->GetPosition().z < playerPos.z - 20.0f)
			{
				//　データ外列の
				objects.erase(objects.begin() + i);
				speeds.erase(speeds.begin() + i);
				modelFlag.erase(modelFlag.begin() + i);
			}
			// オブジェクトデータ更新
			objects[i]->Update();
		}
	}
}

void Enemy::Draw()
{
	if (!objects.empty())
	{
		for (int i = 0; i < objects.size(); i++)
		{
			// オブジェクトデータ更新
			objects[i]->Draw();
		}
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
	if (!modelFlag.empty())
	{
		return modelFlag[number];
	}
	else
	{
		return false;
	}
}
