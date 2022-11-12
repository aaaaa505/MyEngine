#pragma once
#include "Object3d.h"
#include "Input.h"
#include "Camera.h"

// �T�C�Y
#define RADIUS_X 0.4f
#define RADIUS_Z 1.8f

// ���x(Z)
#define MAX_SPEED 1.8f
#define MINI_SPEED 0.15f

// ��]�p
#define MAX_ROT 19.0f
#define MAX_ROTSPEED 1.7f
#define PARTITION_ROT 7.0f
#define MITIGATIONVALUE 130.0f

// ������
#define ACC_POWER 0.01f
// ������
#define BRA_POWER 0.04f
// �Đ���
#define INE_POWER 0.01f

class Player
{
private:// �G�C���A�X
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;

public:
	/// <summary>
	/// �C���X�^���X�̐���
	/// </summary>
	/// <returns>�C���X�^���X</returns>
	static Player* Create();

public:
	// �f�X�g���N�^
	~Player();

	/// <summary>
	/// �X�V
	/// </summary>
	void Update(bool startFlag);

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

	// �J�����̍��W�擾
	const XMFLOAT3& GetEye() { return camera->GetEye(); }
	const XMFLOAT3& GetTarget() { return camera->GetTarget(); }
	// �v���C���[�̍��W�擾
	const XMFLOAT3& GetPos() { return obj_Bike->GetPosition(); }
	// �v���C���[�̑��x���擾
	const XMFLOAT3& GetSpeed() { return speed; }

private:
	/// <summary>
	/// ��������
	/// </summary>B
	void Initialize();

	/// <summary>
	/// ���ړ�
	/// </summary>
	void BesideMove();

	/// <summary>
	/// �����ړ�
	/// </summary>
	void AutoSprint();

	/// <summary>
	/// ����
	/// </summary>
	float Fluctuation();

private:
	// �J����
	Camera* camera = nullptr;
	// �o�C�N���f��
	Model* model_Bike = nullptr;
	// �o�C�N�I�u�W�F�N�g
	Object3d* obj_Bike = nullptr;
	// �h�[�����f��
	Model* model_Dome = nullptr;
	// �h�[���I�u�W�F�N�g
	Object3d* obj_Dome = nullptr;

	// ���W
	XMFLOAT3 pos{};
	// ��]
	XMFLOAT3 rot{};
	// �X�s�[�h
	XMFLOAT3 speed{};
	// �����x
	XMFLOAT3 acc{};

	// ���[�X�J�n�t���b�O
	bool startFlag = false;
};

