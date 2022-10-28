#include "Scroll.h"

Scroll* Scroll::Create()
{
	// インスタンス生成
	Scroll* instance = new Scroll();

	// インスタンス初期化
	instance->Initialize();

	// インスタンスを返す
	return instance;
}

Scroll::~Scroll()
{
	for (int i = 0; i < MAX_PLATE; i++)
	{
		delete(plate[i]);
	}
}

void Scroll::Initialize()
{
	// ネクスト
	plate[first] = Field::Create("plateSetthing");
	basePos[first] = { 0.0f, 0.0f, radius };
	plate[first]->SetPosition(basePos[first]);

	// トップ
	plate[second] = Field::Create("plateSetthing");
	basePos[second] = { 0.0f, 0.0f, radius + diameter};
	plate[second]->SetPosition(basePos[second]);

	// 移動対象プレートに一番プレートの配列番号を代入
	next = first;
	// 最前列プレートに2プレートの配列番号を代入
	top = second;
}

void Scroll::Update(XMFLOAT3 playerPos)
{
	// セカンドプレートの中心座標を通過した場合
	if (basePos[top].z <= playerPos.z)
	{
		// ファーストプレートを最前列に配置
		basePos[next] = { 0.0f, 0.0f, basePos[top].z + diameter };
		plate[next]->SetPosition(basePos[next]);
		// 最前列の配列番号を移動したobjの番号にする
		top = next;
		// 次の移動対象objにカウントを進める
		next++;
		// 配列の最大値になった場合
		if (next == MAX_PLATE)
		{
			next = first;
		}
	}

	for (int i = 0; i < MAX_PLATE; i++)
	{
		plate[i]->Update();
	}
}

void Scroll::Draw()
{
	for (int i = 0; i < MAX_PLATE; i++)
	{
		plate[i]->Draw();
	}
}