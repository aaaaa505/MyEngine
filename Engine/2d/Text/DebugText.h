#pragma once
#include <Windows.h>
#include <string>
#include "Sprite.h"

class DebugText
{
private:// �G�C���A�X

	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;

public://�萔�̐錾
	static const int maxCharCount = 256;	//�ő啶����
	static const int fontWidth = 9;			//�t�H���g�摜��1�������̉���
	static const int fontHeight = 18;		//�t�H���g�摜��1�������̏c��
	static const int fontLineCount = 14;	//�t�H���g�摜��1�s���̕�����

public://�����o�֐�

	/// <summary>
	/// �C���X�^���X�̎擾
	/// </summary>
	/// <returns></returns>
	static DebugText* GetInstance();

	/// <summary>
	/// ������
	/// </summary>
	/// <param name="texnumber"></param>
	void Initialize(UINT texnumber);

	/// <summary>
	/// �I��
	/// </summary>
	void Finalize();

	/// <summary>
	/// ������X�V
	/// </summary>
	/// <param name="text">�����i�[�p</param>
	/// <param name="pos">���W</param>
	/// <param name="size">�傫��</param>
	void Print(const std::string& text, const XMFLOAT2& pos, const float& size);

	/// <summary>
	/// �S�`��
	/// </summary>
	void DrawAll();

private: //�����o�ϐ�

	// �X�v���C�g�f�[�^�̔z��
	Sprite* spriteDatas[maxCharCount] = {};
	// �X�v���C�g�f�[�^�z��̓Y�����ԍ�
	int32_t spriteIndex = 0;
};