#pragma once
#include <string>
#include <vector>
#include <DirectXMath.h>
#include <json.hpp>
#include <Object3d.h>
#include <Model.h>

// ���x���f�[�^
struct LevelData {

	struct ObjectData {
		// �t�@�C����
		std::string fileName;
		// ���s�ړ�
		DirectX::XMVECTOR translation;
		// ��]�p
		DirectX::XMVECTOR rotation;
		// �X�P�[�����O
		DirectX::XMVECTOR scaling;
		// model
		Model* model = nullptr;
	};

	// �I�u�W�F�N�g�z��
	std::vector<ObjectData> objects;
};

class LevelLoader
{
public:// �ÓI�����o�֐�

	/// <summary>
	/// ���x���f�[�^�t�@�C���̓ǂݍ���
	/// </summary>
	/// <param name="fileName">�t�@�C����</param>
	static LevelData* LoadFile(const std::string& fileName);


private:// �ÓI�����o�֐�

	/// <summary>
	/// ���x���f�[�^����
	/// </summary>
	/// <param name="object"></param>
	/// <param name="levelData"></param>
	/// <returns></returns>
	static LevelData::ObjectData* Scanning(nlohmann::json& object, LevelData* levelData);

private:// �ÓI�����o�ϐ�
	// �i�[�t�@�C����
	static const std::string baseDirectory;
	// �g���q�i�[
	static const std::string extension;

	
};

