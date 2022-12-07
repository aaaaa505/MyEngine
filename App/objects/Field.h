#pragma once
#include "Object3d.h"
#include <map>
#include <fstream>

struct LevelData;

class Field
{
private:// �G�C���A�X
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;

public:// �ÓI�����o�֐�
	
	/// <summary>
	/// �C���X�^���X�̐���
	/// </summary>
	/// <returns>�C���X�^���X</returns>
	static Field* Create(const std::string& fileName);

public:// �����o�֐�

	// �f�X�g���N�^
	~Field();

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

#pragma region setter
	void SetPosition(XMFLOAT3 movePos);
#pragma endregion

private:// �����o�֐�

	/// <summary>
	/// ��������
	/// </summary>
	void Initialize(const std::string& fileName);


private:
	// ���x���f�[�^
	LevelData* levelData = nullptr;
	// �I�u�W�F�N�g���I�z��
	std::vector<Object3d*> objects;
	// �f�[�^�̏������W
	std::vector<XMFLOAT3> basePos;
};

