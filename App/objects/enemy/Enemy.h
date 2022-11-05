#pragma once
#include "Object3d.h"

// モデルの最大数
#define MAX_MODEL 2
// TRACKモデルのサイズ
#define TRACK_RADIUS_X 1.3f
#define TRACK_RADIUS_Z 4.5f
// CARモデルのサイズ
#define CAR_RADIUS_X 1.3f
#define CAR_RADIUS_Z 3.0f

enum EnemyData
{
	car,
	track,
};

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
	void Update(const XMFLOAT3& playerPos, const float& playerSpeed);

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

#pragma region getter
	// 生成タイマー取得
	int GetCreateTimer() { return createTimer; }
	// データ数を取得
	int GetDataSize() { return objects.size(); }
	// 座標取得
	const XMFLOAT3& GetPos(const int& number);
	// モデルフラッグ取得
	const bool& GetModelFlag(const int& number);
#pragma endregion


private:
	/// <summary>
	/// 生成処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// 自動移動
	/// </summary>
	/// <param name="i">配列のカウント</param>
	void AutoSprint(int i);

	/// <summary>
	/// 引数に与えた数値の範囲でランダムに値を決定する
	/// </summary>
	/// <param name="maxValue">最大値</param>
	/// <param name="miniValue">最小値</param>
	/// <returns></returns>
	int RandValue(const int maxValue, const int miniValue);

	/// <summary>
	/// ランダムに座標を決定する
	/// </summary>
	/// <returns></returns>
	XMFLOAT3 RandPos();

	/// <summary>
	/// ランダムにモデルを決定する
	/// </summary>
	/// <returns></returns>
	short RandModel();

	/// <summary>
	/// ランダムにスピードを決定する
	/// </summary>
	/// <returns></returns>
	int RandTimer();


private:

	// 車モデル
	Model* model[MAX_MODEL] = { nullptr };
	// オブジェクト
	std::vector<Object3d*>objects;
	// 速度
	std::vector<float>speeds;
	// モデルフラッグ
	std::vector<bool>modelFlag;
	// 生成時間
	int createTimer = 0;
	// 存在フラッグ
	bool existenceFlag = false;

	// プレイヤー座標
	XMFLOAT3 player_Pos{};
	// プレイヤースピード
	float player_Speed = 0.0f;
};