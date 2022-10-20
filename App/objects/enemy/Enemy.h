#pragma once
#include "Object3d.h"

const int MAX_ENEMY = 8;

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

	// <summary>
	// �v���C���[���W�擾
	// </summary>
	// <returns></returns>
	XMFLOAT3 GetPos(int i) { return pos[i]; }
	bool Get1() { return existenceFlag[0]; }
	int Get2() { return settingTimer[0]; }
	
private:
	/// <summary>
	/// ��������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �Ĕz�u
	/// </summary>
	/// <param name="topPos"></param>
	void ReSetthing(XMFLOAT3 playerPos, int i);

	/// <summary>
	/// �������
	/// </summary>
	float LaneSetthing();

	/// <summary>
	/// �����ړ�
	/// </summary>
	void AutoSprint(int i);
private:

	// �I�u�W�F�N�g
	Object3d* obj[MAX_ENEMY] = { nullptr };
	// ���f��
	Model* model = nullptr;
	// ���W
	XMFLOAT3 pos[MAX_ENEMY]{};
	// ���x
	XMFLOAT3 speed{};
	// �����_���t���b�O
	short randam = 0;
	// ���݃t���b�O
	bool existenceFlag[MAX_ENEMY] = { false };
	// �z�u�^�C�}�[
	int settingTimer[MAX_ENEMY] = { 0 };
};