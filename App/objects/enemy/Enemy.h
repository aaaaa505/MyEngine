#pragma once
#include "Object3d.h"

// ���f���̍ő吔
#define MAX_MODEL 2
#define MAX_TIMER 4
#define MAX_SPEED 3
// TRACK���f���̃T�C�Y
#define TRACK_RADIUS_X 1.3f
#define TRACK_RADIUS_Z 6.1f
// CAR���f���̃T�C�Y
#define CAR_RADIUS_X 1.3f
#define CAR_RADIUS_Z 3.0f
// RandTimer�̍ő吔
#define RANDTIMER_MAX 200
// RandTimer�̍ŏ���
#define RANDTIMER_MINI 50
// ���C���̒��S���W
#define CENTERLINER 1.8f
#define SIDELINE 5.3f
// �X�s�[�h
#define TopSpeed 0.7f
#define MiddleSpeed 0.6f
#define BottonSpeed 0.5f
// �z�u���W
#define BASEPOS 310.0f
enum ModelNumber
{
	car,
	track,
};

enum LineNumber
{
	left_Second,
	left_First, 
	right_First,
	rightSecond,
};

enum SpeedNumber
{
	First,
	Second,
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
	int GetCreateTimer() { return createTimer[0]; }
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
	void AutoSprint(int number);

	/// <summary>
	/// �����_���ɍ��W�����肷��
	/// </summary>
	/// <returns></returns>
	XMFLOAT3 RandPos(int number);

	/// <summary>
	/// �����_���Ƀ��f�������肷��
	/// </summary>
	/// <returns></returns>
	short RandModel();

	/// <summary>
	/// �����_���ɃX�s�[�h�����肷��
	/// </summary>
	/// <returns></returns>
	float RandSpeed();


private:

	// �ԃ��f��
	Model* model[MAX_MODEL] = { nullptr };
	// �I�u�W�F�N�g
	std::vector<Object3d*>objects;
	// ���x
	std::vector<float>speeds;
	// ���f���t���b�O
	std::vector<bool>modelFlags;
	// ��������
	int createTimer[MAX_TIMER] = {};
	// ���݃t���b�O
	bool existenceFlag = false;

	// �v���C���[���W
	XMFLOAT3 player_Pos{};
	// �v���C���[�X�s�[�h
	float player_Speed = 0.0f;
};