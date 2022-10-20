#include "Field.h"

Field* Field::Create()
{
	// インスタンスの生成
	Field* instance = new Field();

	// インスタンスの初期化
	instance->Initialize();
	
	// インスタンスを返す
	return instance;
}

Field::~Field()
{
	// オブジェクト解放
	for (int i = 0; i < ROAD_MAX; i++)
	{
		delete obj[i];
	}
	// モデル解放
	delete model;
}

void Field::Initialize()
{
	// モデル読み込み
	model = Model::LoadFromOBJ("road");
	for (int i = 0; i < ROAD_MAX; i++)
	{
		// 生成
		obj[i] = Object3d::Create();	
		// モデルセット
		obj[i]->SetModel(model);
		// 初期座標セット(3枚用)
		obj[i]->SetPosition({ 0.0f, 0.1f, 20.0f + i * 40.0f });
	}
	
	// 初期最前配列番号を格納
	top = 2;
}

void Field::Update(XMFLOAT3 pos)
{
	// 列の中心座標を通過したら
	if (obj[next]->GetPosition().z + 40 <= pos.z)
	{
		// 移動対象objを最前列に配置
		obj[next]->SetPosition({ 0.0f, 0.1f, obj[top]->GetPosition().z + 40.0f});
		// 最前列の配列番号を移動したobjの番号にする
		top = next;
		// 次の移動対象objにカウントを進める
		next += 1;
		// 配列の最大値になった場合
		if (next == ROAD_MAX)
		{
			next = 0;
		}
	}

	for (int i = 0; i < ROAD_MAX; i++)
	{
		// 更新
		obj[i]->Update();
	}
}

void Field::Draw()
{
	for (int i = 0; i < ROAD_MAX; i++)
	{
		// 描画
		obj[i]->Draw();
	}
}
