#pragma once
#include "Object3d.h"

// ���f���̍ő吔
#define MAX_MODEL 2
// TRACK���f���̃T�C�Y
#define TRACK_RADIUS_X 1.3f
#define TRACK_RADIUS_Z 4.5f
// CAR���f���̃T�C�Y
#define CAR_RADIUS_X 1.3f
#define CAR_RADIUS_Z 3.0f

enum EnemyData
{
	car,
	track,
};

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
	void Update(const XMFLOAT3& playerPos, const float& playerSpeed);

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

#pragma region getter
	// �����^�C�}�[�擾
	int GetCreateTimer() { return createTimer; }
	// �f�[�^�����擾
	int GetDataSize() { return objects.size(); }
	// ���W�擾
	const XMFLOAT3& GetPos(const int& number);
	// ���f���t���b�O�擾
	const bool& GetModelFlag(const int& number);
#pragma endregion


private:
	/// <summary>
	/// ��������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �����ړ�
	/// </summary>
	/// <param name="i">�z��̃J�E���g</param>
	void AutoSprint(int i);

	/// <summary>
	/// �����ɗ^�������l�͈̔͂Ń����_���ɒl�����肷��
	/// </summary>
	/// <param name="maxValue">�ő�l</param>
	/// <param name="miniValue">�ŏ��l</param>
	/// <returns></returns>
	int RandValue(const int maxValue, const int miniValue);

	/// <summary>
	/// �����_���ɍ��W�����肷��
	/// </summary>
	/// <returns></returns>
	XMFLOAT3 RandPos();

	/// <summary>
	/// �����_���Ƀ��f�������肷��
	/// </summary>
	/// <returns></returns>
	short RandModel();

	/// <summary>
	/// �����_���ɃX�s�[�h�����肷��
	/// </summary>
	/// <returns></returns>
	int RandTimer();


private:

	// �ԃ��f��
	Model* model[MAX_MODEL] = { nullptr };
	// �I�u�W�F�N�g
	std::vector<Object3d*>objects;
	// ���x
	std::vector<float>speeds;
	// ���f���t���b�O
	std::vector<bool>modelFlag;
	// ��������
	int createTimer = 0;
	// ���݃t���b�O
	bool existenceFlag = false;

	// �v���C���[���W
	XMFLOAT3 player_Pos{};
	// �v���C���[�X�s�[�h
	float player_Speed = 0.0f;
};