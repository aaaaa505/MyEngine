#pragma once
#include "Object3d.h"
#include "Input.h"
#include "Camera.h"

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
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	// カメラの座標取得
	const XMFLOAT3& GetEye() { return camera->GetEye(); }
	const XMFLOAT3& GetTarget() { return camera->GetTarget(); }
	// プレイヤーの座標取得
	const XMFLOAT3& GetPos() { return obj_Bike->GetPosition(); }

private:

	/// <summary>
	/// 生成処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// 横移動
	/// </summary>
	void BesideMove();

	/// <summary>
	/// 自動移動
	/// </summary>
	void AutoSprint();

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

	// プレイヤー座標
	XMFLOAT3 pos{};
};

