#pragma once
#include "Object3d.h"

class Enemy
{
private: // エイリアス
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;

public: // 静的メンバ関数

	/// <summary>
	/// インスタンス
	/// </summary>
	static Enemy* Create();

public: // メンバ関数

	// デストラクタ
	~Enemy();

	/// <summary>
	/// 更新
	/// </summary>
	void Update(XMFLOAT3 playerPos);

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();
	
#pragma region getter
	// 生成タイマー取得
	int GetCreateTimer() { return createTimer; }
	// データ数を取得
	int GetDataSize() { return objects.size(); }
#pragma endregion


private:
	/// <summary>
	/// 生成処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// 
	/// </summary>
	int RandValue(const int maxValue, const int miniValue);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	XMFLOAT3 RandPos();
private:

	// 車モデル
	Model* model_Car = nullptr;
	// トラックモデル
	Model* model_Track = nullptr;
	// オブジェクト
	std::vector<Object3d*>objects;
	// 生成時間
	int createTimer = 0;
	// 存在フラッグ
	bool existenceFlag = false;
};