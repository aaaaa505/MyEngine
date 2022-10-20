#pragma once
#include "Object3d.h"

const int ROAD_MAX = 3;

class Field
{
private: // �G�C���A�X
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;

public: // �ÓI�����o�֐�

	/// <summary>
	/// �C���X�^���X
	/// </summary>
	static Field* Create();

public: // �����o�֐�

	// �f�X�g���N�^
	~Field();

	/// <summary>
	/// �X�V
	/// </summary>
	void Update(XMFLOAT3 pos);

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

	/// <summary>
	/// �v���C���[���W�擾
	/// </summary>
	/// <returns></returns>
	XMFLOAT3 GetPos(int i) { return obj[i]->GetPosition(); }

	short GetDebug1() { return next; }
	short GetDebug2() { return top; }

private: // �����o�֐�
	/// <summary>
	/// ��������
	/// </summary>
	void Initialize();

private: // �����o�ϐ�

	// �I�u�W�F�N�g
	Object3d* obj[ROAD_MAX] = {nullptr};
	// ���f��
	Model* model = nullptr;

	// ���̈ړ����[�h�̔z��ԍ�
	short next = 0;
	// �őO�񃍁[�h�̔z��ԍ�
	short top = 0;
};