#include "LevelLoader.h"

#include <json.hpp>
#include <fstream>
#include <cassert>

const std::string LevelLoader::baseDirectory = "Resources/levels/";
const std::string LevelLoader::extension = ".json";

LevelData::ObjectData* LevelLoader::Scanning(nlohmann::json& object, LevelData* levelData)
{
	// ��ʂ��擾
	std::string type = object["type"].get<std::string>();

	// MESH
	if (type.compare("MESH") == 0)
	{
		// �v�f�ǉ�
		levelData->objects.emplace_back(LevelData::ObjectData{});
		// ����ǉ������v�f�̎Q�Ƃ𓾂�
		LevelData::ObjectData& objectData = levelData->objects.back();

		if (object.contains("file_name"))
		{
			// �t�@�C����
			objectData.fileName = object["file_name"];
			objectData.model = Model::LoadFromOBJ(objectData.fileName);
		}

		// �g�����X�t�H�[���̃p�����[�^�ǂݍ���
		nlohmann::json& transform = object["transform"];
		// ���s�ړ�
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
	// �A�����ăt���p�X�𓾂�
	const std::string fullPath = baseDirectory + fileName + extension;

	// �t�@�C���X�g���[��
	std::ifstream file;

	//�t�@�C�����J��
	file.open(fullPath);
	// �t�@�C���I�[�v�����s���`�F�b�N
	if (file.fail())
	{
		assert(0);
	}

	// JSON�����񂩂�𓀂����f�[�^
	nlohmann::json deserialized;

	// ��
	file >> deserialized;

	// ���������x���f�[�^�t�@�C�����`�F�b�N
	assert(deserialized.is_object());
	assert(deserialized.contains("name"));
	assert(deserialized["name"].is_string());

	// "name"�𕶎���Ƃ��Ď擾
	std::string name =
	deserialized["name"].get<std::string>();
	// ���������x���f�[�^�t�@�C�����`�F�b�N
	assert(name.compare("scene") == 0);
	
	// ���x���f�[�^�i�[�p�C���X�^���X�𐶐�
	LevelData* levelData = new LevelData();

	// "objects"�̑S�I�u�W�F�N�g�𑖍�
	for (nlohmann::json& object : deserialized["objects"])
	{
		assert(object.contains("type"));

		// ����
		Scanning(object, levelData);
	}

	return levelData;

}
