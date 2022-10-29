#pragma once
#include "Object3d.h"

class Enemy
{
private: // �G�C���A�X
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;

public: // �ÓI�����o�֐�

	/// <summary>
	/// �C���X�^���X
	/// </summary>
	static Enemy* Create();

public: // �����o�֐�

	// �f�X�g���N�^
	~Enemy();

	/// <summary>
	/// �X�V
	/// </summary>
	void Update(XMFLOAT3 playerPos);

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();
	
#pragma region getter
	// �����^�C�}�[�擾
	int GetCreateTimer() { return createTimer; }
	// �f�[�^�����擾
	int GetDataSize() { return objects.size(); }
#pragma endregion


private:
	/// <summary>
	/// ��������
	/// </summary>
	void Initialize();

	/// <summary>
	/// 
	/// </summary>
	int RandValue(const int maxValue, const int miniValue);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	XMFLOAT3 RandPos();
private:

	// �ԃ��f��
	Model* model_Car = nullptr;
	// �g���b�N���f��
	Model* model_Track = nullptr;
	// �I�u�W�F�N�g
	std::vector<Object3d*>objects;
	// ��������
	int createTimer = 0;
	// ���݃t���b�O
	bool existenceFlag = false;
};