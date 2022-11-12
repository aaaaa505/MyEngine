#pragma once
#include"Sprite.h"

class CountDown
{
private: // �G�C���A�X
	using XMFLOAT2 = DirectX::XMFLOAT2;

public:// �萔
	enum CountNumber
	{
		third,
		second,
		first,
		zero,
	};

	static const int maxTimer = 50;

private:// �萔
	const float centerPos = 0.5f;
	const float movePower = 100.0f;
	const float decayPower = 0.05f;

public:// �ÓI�����o�֐�

	/// <summary>
	/// �C���X�^���X�̐���
	/// </summary>
	/// <returns>�C���X�^���X</returns>
	static CountDown* Create();
	
public:// �����o�֐�

	// �f�X�g���N�^
	~CountDown();

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

	bool GetStartFlag() { return startFlag; }

private:// �����o�֐�

	/// <summary>
	/// ��������
	/// </summary>
	void Initialize();

private:// �����o�ϐ�
	Sprite* sprite = nullptr;
	USHORT countFlag = 0;
	int32_t countTimer = 0;
	bool startFlag = false;
};

