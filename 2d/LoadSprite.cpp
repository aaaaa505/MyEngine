#include "LoadSprite.h"
#include "SpriteCommon.h"

void LoadSprite::StaticInitialize(SpriteCommon* spriteCommon)
{
	// �f�o�b�O�e�L�X�g�p�e�N�X�`���ǂݍ���
	if (!spriteCommon->LoadTexture(debugTextTexNumber, L"Resources/debugfont.png")) {
		assert(0);
		return;
	}
	//�T���v���摜1
	if (!spriteCommon->LoadTexture(sample1, L"Resources/texture1.png")) {
		assert(0);
		return;
	}
	//�T���v���摜2
	if (!spriteCommon->LoadTexture(sample2, L"Resources/texture2.png")) {
		assert(0);
		return;
	}
}
