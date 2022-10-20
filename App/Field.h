#pragma once
#include "Object3d.h"

const int ROAD_MAX = 3;

class Field
{
private: // エイリアス
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;

public: // 静的メンバ関数

	/// <summary>
	/// インスタンス
	/// </summary>
	static Field* Create();

public: // メンバ関数

	// デストラクタ
	~Field();

	/// <summary>
	/// 更新
	/// </summary>
	void Update(XMFLOAT3 pos);

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	/// <summary>
	/// プレイヤー座標取得
	/// </summary>
	/// <returns></returns>
	XMFLOAT3 GetPos(int i) { return obj[i]->GetPosition(); }

	short GetDebug1() { return next; }
	short GetDebug2() { return top; }

private: // メンバ関数
	/// <summary>
	/// 生成処理
	/// </summary>
	void Initialize();

private: // メンバ変数

	// オブジェクト
	Object3d* obj[ROAD_MAX] = {nullptr};
	// モデル
	Model* model = nullptr;

	// 次の移動ロードの配列番号
	short next = 0;
	// 最前列ロードの配列番号
	short top = 0;
};