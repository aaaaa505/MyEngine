#include "LoadSprite.h"
#include "SpriteCommon.h"

void LoadSprite::StaticInitialize(SpriteCommon* spriteCommon)
{
	// �f�o�b�O�e�L�X�g�p�e�N�X�`���ǂݍ���
	if (!spriteCommon->LoadTexture(debugTextTexNumber, L"Resources/debugfont.png")) {
		assert(0);
		return;
	}
	// �^�C�g���摜
	if (!spriteCommon->LoadTexture(title_Number, L"Resources/title.png")) {
		assert(0);
		return;
	}
	// �G���h�摜
	if (!spriteCommon->LoadTexture(end_Number, L"Resources/end.png")) {
		assert(0);
		return;
	}
}
