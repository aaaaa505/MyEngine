#pragma once
#include "SpriteCommon.h"

enum  SpriteNumber
{
	// �f�o�b�N�e�L�X�g
	debugTextTexNumber,
	// �����e�N�X�`���[
	NumberNumber,
	// �^�C�g�� ���I���i���o�[
	title_None_Number,
	// �^�C�g�� �X�^�[�g�I���i���o�[
	title_Start_Number,
	// �^�C�g�� �}�j���A���I���i���o�[
	title_Manual_Number,
	// �}�j���A���i���o�[
	manual_Number,
	// �G���h�i���o�[
	end_Number,
	// �J�E���g�_�E��
	third_Number,
	second_Number,
	first_Number,
	zero_Number,


};

class LoadSprite
{
public:// �ÓI�����o�֐�
	/// <summary>
	/// �ÓI������
	/// </summary>
	static void StaticInitialize(SpriteCommon* spriteCommon);
};

