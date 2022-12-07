#pragma once
#include "Field.h"

// プレートの最大数
const int MAX_PLATE = 2;

enum PlateData
{
	first,
	second,
	radius = 300,
	diameter = 600,
};

class Scroll
{
private: // エイリアス
	using XMFLOAT3 = DirectX::XMFLOAT3;

public:// 静的メンバ関数

	/// <summary>
	/// インスタンスの生成
	/// </summary>
	/// <returns>インスタンス</returns>
	static Scroll* Create();

public:// メンバ関数

	// デストラクタ
	~Scroll();

	/// <summary>
	/// 更新
	/// </summary>
	void Update(XMFLOAT3 playerPos);

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();


private:// メンバ関数

	/// <summary>
	/// 生成処理
	/// </summary>
	void Initialize();

private:// メンバ変数

	// プレートオブジェクト
	Field* plate[MAX_PLATE] = {nullptr};
	// 基点座標
	XMFLOAT3 basePos[MAX_PLATE]{};
	// 次の移動ロードの配列番号
	short next = 0;
	// 最前列ロードの配列番号
	short top = 0;
};

