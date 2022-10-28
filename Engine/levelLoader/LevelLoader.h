#pragma once
#include <string>
#include <vector>
#include <DirectXMath.h>
#include <json.hpp>
#include <Object3d.h>
#include <Model.h>

// レベルデータ
struct LevelData {

	struct ObjectData {
		// ファイル名
		std::string fileName;
		// 平行移動
		DirectX::XMVECTOR translation;
		// 回転角
		DirectX::XMVECTOR rotation;
		// スケーリング
		DirectX::XMVECTOR scaling;
		// model
		Model* model = nullptr;
	};

	// オブジェクト配列
	std::vector<ObjectData> objects;
};

class LevelLoader
{
public:// 静的メンバ関数

	/// <summary>
	/// レベルデータファイルの読み込み
	/// </summary>
	/// <param name="fileName">ファイル名</param>
	static LevelData* LoadFile(const std::string& fileName);


private:// 静的メンバ関数

	/// <summary>
	/// レベルデータ走査
	/// </summary>
	/// <param name="object"></param>
	/// <param name="levelData"></param>
	/// <returns></returns>
	static LevelData::ObjectData* Scanning(nlohmann::json& object, LevelData* levelData);

private:// 静的メンバ変数
	// 格納ファイル名
	static const std::string baseDirectory;
	// 拡張子格納
	static const std::string extension;

	
};

