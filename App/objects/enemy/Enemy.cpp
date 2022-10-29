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
	delete model_Car;
	//　オブジェクト解放
	for (int i = 0; i < objects.size(); i++)
	{
		delete objects[i];
	}
}

void Enemy::Initialize()
{
	// モデル読み込み
	model_Car = Model::LoadFromOBJ("car");
	model_Track = Model::LoadFromOBJ("track");
	// 生成時間
	createTimer = 180;
	// 存在フラッグ
	existenceFlag = false;
}

void Enemy::Update(XMFLOAT3 playerPos)
{	
	// タイマー
	createTimer--;
	if (createTimer <= 0)
	{
		createTimer = 180;
		objects.push_back(Object3d::Create({-6.0f, 0.0f, playerPos.z + 900.0f}, model_Track));
	}


	if (!objects.empty())
	{
		for (int i = 0; i < objects.size(); i++)
		{
			//　プレイヤーがエネミーを追い越したら
			if (objects[i]->GetPosition().z < playerPos.z)
			{
				//　データ外列の
				objects.erase(objects.begin());
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
