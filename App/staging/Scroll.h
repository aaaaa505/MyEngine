#pragma once
#include "Field.h"

// �v���[�g�̍ő吔
const int MAX_PLATE = 2;

enum PlateData
{
	first,
	second,
	radius = 300,
	diameter = 600,
};

class Scroll
{
private: // �G�C���A�X
	using XMFLOAT3 = DirectX::XMFLOAT3;

public:// �ÓI�����o�֐�

	/// <summary>
	/// �C���X�^���X�̐���
	/// </summary>
	/// <returns>�C���X�^���X</returns>
	static Scroll* Create();

public:// �����o�֐�

	// �f�X�g���N�^
	~Scroll();

	/// <summary>
	/// �X�V
	/// </summary>
	void Update(XMFLOAT3 playerPos);

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();


private:// �����o�֐�

	/// <summary>
	/// ��������
	/// </summary>
	void Initialize();

private:// �����o�ϐ�

	// �v���[�g�I�u�W�F�N�g
	Field* plate[MAX_PLATE] = {nullptr};
	// ��_���W
	XMFLOAT3 basePos[MAX_PLATE]{};
	// ���̈ړ����[�h�̔z��ԍ�
	short next = 0;
	// �őO�񃍁[�h�̔z��ԍ�
	short top = 0;
};

