#pragma once
#include "Object3d.h"
#include "Input.h"
#include "Camera.h"

// サイズ
#define RADIUS_X 0.4f
#define RADIUS_Z 1.8f

// 速度(Z)
#define MAX_SPEED 1.8f
#define MINI_SPEED 0.15f

// 回転角
#define MAX_ROT 19.0f
#define MAX_ROTSPEED 1.7f
#define PARTITION_ROT 7.0f
#define MITIGATIONVALUE 130.0f

// 加速力
#define ACC_POWER 0.01f
// 減速力
#define BRA_POWER 0.04f
// 惰性力
#define INE_POWER 0.01f

class Player
{
private:// エイリアス
	// DirectX::を省略
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;

public:
	/// <summary>
	/// インスタンスの生成
	/// </summary>
	/// <returns>インスタンス</returns>
	static Player* Create();

public:
	// デストラクタ
	~Player();

	/// <summary>
	/// 更新
	/// </summary>
	void Update(bool startFlag);

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	// カメラの座標取得
	const XMFLOAT3& GetEye() { return camera->GetEye(); }
	const XMFLOAT3& GetTarget() { return camera->GetTarget(); }
	// プレイヤーの座標取得
	const XMFLOAT3& GetPos() { return obj_Bike->GetPosition(); }
	// プレイヤーの速度を取得
	const XMFLOAT3& GetSpeed() { return speed; }

private:
	/// <summary>
	/// 生成処理
	/// </summary>B
	void Initialize();

	/// <summary>
	/// 横移動
	/// </summary>
	void BesideMove();

	/// <summary>
	/// 自動移動
	/// </summary>
	void AutoSprint();

	/// <summary>
	/// 加速
	/// </summary>
	float Fluctuation();

private:
	// カメラ
	Camera* camera = nullptr;
	// バイクモデル
	Model* model_Bike = nullptr;
	// バイクオブジェクト
	Object3d* obj_Bike = nullptr;
	// ドームモデル
	Model* model_Dome = nullptr;
	// ドームオブジェクト
	Object3d* obj_Dome = nullptr;

	// 座標
	XMFLOAT3 pos{};
	// 回転
	XMFLOAT3 rot{};
	// スピード
	XMFLOAT3 speed{};
	// 加速度
	XMFLOAT3 acc{};

	// レース開始フラッグ
	bool startFlag = false;
};

