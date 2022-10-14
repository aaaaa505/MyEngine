#pragma once
#include "Object3d.h"
#include "Input.h"
#include "Camera.h"

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
	void Update();

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

	// �J�����̍��W�擾
	const XMFLOAT3& GetEye() { return camera->GetEye(); }
	// �v���C���[�̍��W�擾
	const XMFLOAT3& GetPos() { return obj->GetPosition(); }

private:

	/// <summary>
	/// ��������
	/// </summary>
	void Initialize();

private:
	// �J����
	Camera* camera = nullptr;
	// �o�C�N���f��
	Model* model = nullptr;
	// �o�C�N�I�u�W�F�N�g
	Object3d* obj = nullptr;
};

