#pragma once
#include "SpriteCommon.h"

enum  SpriteNumber
{
	// �f�o�b�N�e�L�X�g
	debugTextTexNumber,
	
	// �^�C�g���i���o�[
	title_Number,

	// �G���h�i���o�[
	end_Number,

};

class LoadSprite
{
public:// �ÓI�����o�֐�
	/// <summary>
	/// �ÓI������
	/// </summary>
	static void StaticInitialize(SpriteCommon* spriteCommon);
};

