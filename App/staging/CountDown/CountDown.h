#pragma once
#include"Sprite.h"

class CountDown
{
private: // �G�C���A�X
	using XMFLOAT2 = DirectX::XMFLOAT2;

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

private://�񋓒萔
	enum CountNumber
	{
		third,
		second,
		first,
		zero,
	};

private:// �萔
	static const float centerPos;
	static const float movePower;
	static const float decayPower;

	static const int maxTimer = 50;

private:// �����o�ϐ�
	Sprite* sprite = nullptr;
	USHORT countFlag = 0;
	int32_t countTimer = 0;
	bool startFlag = false;
};

