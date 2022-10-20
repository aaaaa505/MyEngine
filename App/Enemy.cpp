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
	//　オブジェクト解放
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		delete obj[i];
	}
	// モデル解放
	delete model;
}

void Enemy::Initialize()
{
	// 初期乱数
	srand(time(NULL));
	// モデル読み込み
	model = Model::LoadFromOBJ("enemy");
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		// 生成
		obj[i] = Object3d::Create();
		// モデルセット
		obj[i]->SetModel(model);
		// スケール
		obj[i]->SetScale({0.5f, 0.5f, 0.5f});
		// 座標
		pos[i] = {0.0f, 100.0f, 0.0f};
		// 初期タイマー値
		settingTimer[i] = (rand() % 120) + 120;
		existenceFlag[i] = false;
	}
	// 速度
	speed = { 0.0f, 0.0f, 0.9f };
}

float Enemy::LaneSetthing()
{
	float x;
	randam = rand() % 4;
	if (randam == 0)
	{
		x = -4.0f;
	}
	else if (randam == 1)
	{
		x = -1.3f;
	}
	else if (randam == 2)
	{
		x = 1.3f;
	}
	else
	{
		x = 4.0f;
	}

	return x;
}

void Enemy::ReSetthing(XMFLOAT3 playerPos, int i)
{
	if (existenceFlag[i] == false)
	{
		settingTimer[i] -= 1;
	}

	if (settingTimer[i] <= 0)
	{
		pos[i] = {LaneSetthing() ,0.0f, playerPos.z + 50.0f};

		existenceFlag[i] = true;
		settingTimer[i] = (rand() % 120) + 120;
	}
}

void Enemy::AutoSprint(int i)
{
	pos[i].z += speed.z;
	obj[i]->SetPosition(pos[i]);
}

void Enemy::Update(XMFLOAT3 playerPos)
{	
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		// 再配置
		ReSetthing(playerPos, i);
		// プレイヤーにぬかされた場合
		if (playerPos.z - 10.0f >= pos[i].z)
		{
			existenceFlag[i] = false;
			pos[i] = {0.0f, 100.0f, 0.0f};
		}

		if (existenceFlag[i])
		{
			AutoSprint(i);
			// 更新
			obj[i]->Update();
		}
	}
}

void Enemy::Draw()
{
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		if (existenceFlag[i])
		{
			// 描画
			obj[i]->Draw();
		}
	}
}
