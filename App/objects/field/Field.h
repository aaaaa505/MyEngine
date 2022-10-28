#pragma once
#include "Object3d.h"
#include <map>
#include <fstream>

struct LevelData;

class Field
{
private:// エイリアス
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;

public:// 静的メンバ関数
	
	/// <summary>
	/// インスタンスの生成
	/// </summary>
	/// <returns>インスタンス</returns>
	static Field* Create(const std::string& fileName);

public:// メンバ関数

	// デストラクタ
	~Field();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

#pragma region setter
	void SetPosition(XMFLOAT3 movePos);
#pragma endregion

private:// メンバ関数

	/// <summary>
	/// 生成処理
	/// </summary>
	void Initialize(const std::string& fileName);


private:
	// レベルデータ
	LevelData* levelData = nullptr;
	// オブジェクト動的配列
	std::vector<Object3d*> objects;
	// データの初期座標
	std::vector<XMFLOAT3> basePos;
};

