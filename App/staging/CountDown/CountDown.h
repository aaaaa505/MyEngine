#pragma once
#include"Sprite.h"

class CountDown
{
private: // エイリアス
	using XMFLOAT2 = DirectX::XMFLOAT2;

public:// 定数
	enum CountNumber
	{
		third,
		second,
		first,
		zero,
	};

	static const int maxTimer = 50;

private:// 定数
	const float centerPos = 0.5f;
	const float movePower = 100.0f;
	const float decayPower = 0.05f;

public:// 静的メンバ関数

	/// <summary>
	/// インスタンスの生成
	/// </summary>
	/// <returns>インスタンス</returns>
	static CountDown* Create();
	
public:// メンバ関数

	// デストラクタ
	~CountDown();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	bool GetStartFlag() { return startFlag; }

private:// メンバ関数

	/// <summary>
	/// 生成処理
	/// </summary>
	void Initialize();

private:// メンバ変数
	Sprite* sprite = nullptr;
	USHORT countFlag = 0;
	int32_t countTimer = 0;
	bool startFlag = false;
};

