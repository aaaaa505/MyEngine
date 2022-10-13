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
	if (!spriteCommon->LoadTexture(title_Number, L"Resources/title.png")) {
		assert(0);
		return;
	}
}
