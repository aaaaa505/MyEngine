#pragma once
#include "Object3d.h"

const int MAX_ENEMY = 8;

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

	// <summary>
	// プレイヤー座標取得
	// </summary>
	// <returns></returns>
	XMFLOAT3 GetPos(int i) { return pos[i]; }
	bool Get1() { return existenceFlag[0]; }
	int Get2() { return settingTimer[0]; }
	
private:
	/// <summary>
	/// 生成処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// 再配置
	/// </summary>
	/// <param name="topPos"></param>
	void ReSetthing(XMFLOAT3 playerPos, int i);

	/// <summary>
	/// 列を決定
	/// </summary>
	float LaneSetthing();

	/// <summary>
	/// 自動移動
	/// </summary>
	void AutoSprint(int i);
private:

	// オブジェクト
	Object3d* obj[MAX_ENEMY] = { nullptr };
	// モデル
	Model* model = nullptr;
	// 座標
	XMFLOAT3 pos[MAX_ENEMY]{};
	// 速度
	XMFLOAT3 speed{};
	// ランダムフラッグ
	short randam = 0;
	// 存在フラッグ
	bool existenceFlag[MAX_ENEMY] = { false };
	// 配置タイマー
	int settingTimer[MAX_ENEMY] = { 0 };
};