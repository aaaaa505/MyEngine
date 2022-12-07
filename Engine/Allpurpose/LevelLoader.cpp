#include "LevelLoader.h"

#include <json.hpp>
#include <fstream>
#include <cassert>

const std::string LevelLoader::baseDirectory = "Resources/levels/";
const std::string LevelLoader::extension = ".json";

LevelData::ObjectData* LevelLoader::Scanning(nlohmann::json& object, LevelData* levelData)
{
	// 種別を取得
	std::string type = object["type"].get<std::string>();

	// MESH
	if (type.compare("MESH") == 0)
	{
		// 要素追加
		levelData->objects.emplace_back(LevelData::ObjectData{});
		// 今回追加した要素の参照を得る
		LevelData::ObjectData& objectData = levelData->objects.back();

		if (object.contains("file_name"))
		{
			// ファイル名
			objectData.fileName = object["file_name"];
			objectData.model = Model::LoadFromOBJ(objectData.fileName);
		}

		// トランスフォームのパラメータ読み込み
		nlohmann::json& transform = object["transform"];
		// 平行移動
		objectData.translation.m128_f32[0] = (float)transform["translation"][1];
		objectData.translation.m128_f32[1] = (float)transform["translation"][2];
		objectData.translation.m128_f32[2] = -(float)transform["translation"][0];
		objectData.translation.m128_f32[3] = 1.0f;


		for (nlohmann::json& child : object["children"])
		{
			Scanning(child, levelData);
		}

		return &objectData;
	}
}

LevelData* LevelLoader::LoadFile(const std::string& fileName)
{
	// 連結してフルパスを得る
	const std::string fullPath = baseDirectory + fileName + extension;

	// ファイルストリーム
	std::ifstream file;

	//ファイルを開く
	file.open(fullPath);
	// ファイルオープン失敗をチェック
	if (file.fail())
	{
		assert(0);
	}

	// JSON文字列から解凍したデータ
	nlohmann::json deserialized;

	// 解凍
	file >> deserialized;

	// 正しいレベルデータファイルかチェック
	assert(deserialized.is_object());
	assert(deserialized.contains("name"));
	assert(deserialized["name"].is_string());

	// "name"を文字列として取得
	std::string name =
	deserialized["name"].get<std::string>();
	// 正しいレベルデータファイルかチェック
	assert(name.compare("scene") == 0);
	
	// レベルデータ格納用インスタンスを生成
	LevelData* levelData = new LevelData();

	// "objects"の全オブジェクトを走査
	for (nlohmann::json& object : deserialized["objects"])
	{
		assert(object.contains("type"));

		// 走査
		Scanning(object, levelData);
	}

	return levelData;

}
