#include "DebugText.h"

DebugText::DebugText()
{
}

DebugText::~DebugText()
{
	for (int i = 0; i < _countof(spriteDatas); i++) {
		delete spriteDatas[i];
	}
}

DebugText* DebugText::Create(SpriteCommon* spriteCommon, UINT texnumber)
{
	DebugText* instance = new DebugText();

	instance->Initialize(spriteCommon, texnumber);

	return instance;
}

//�f�o�b�O�����񏉊���
void DebugText::Initialize(SpriteCommon* spriteCommon, UINT texnumber)
{
	assert(spriteCommon);

	this->spriteCommon = spriteCommon;

	//�S�ẴX�v���C�g�f�[�^�ɂ���
	for (int i = 0; i < _countof(spriteDatas); i++)
	{
		// �X�v���C�g�𐶐�����
		spriteDatas[i] = Sprite::Create(this->spriteCommon, texnumber, { 0, 0 });
	}
}

//�f�o�b�O������̕`��
void DebugText::Print(const std::string& text, float x, float y, float size)
{
	//�S�Ă̕����ɂ���
	for (int i = 0; i < text.size(); i++)
	{
		// �ő啶��������
		if (spriteIndex >= maxCharCount) {
			break;
		}

		//1�������o��(��ASCII�R�[�h�ł������藧���Ȃ�)
		const unsigned char& character = text[i];

		//ASCII�R�[�h��2�i����΂����ԍ����v�Z
		int fontIndex = character - 32;
		if (character >= 0x7f) {
			fontIndex = 0;
		}

		int fontIndexY = fontIndex / fontLineCount;
		int fontIndexX = fontIndex % fontLineCount;

		//���W�v�Z
		spriteDatas[spriteIndex]->SetPosition({ x + fontWidth * size * i, y});
		spriteDatas[spriteIndex]->SetTextureRect({ (float)fontIndexX * fontWidth, (float)fontIndexY * fontHeight }, { (float)fontWidth, (float)fontHeight });
		spriteDatas[spriteIndex]->SetSize({ fontWidth * size, fontHeight * size });
		spriteDatas[spriteIndex]->SetAlpha(100.0f);
		//�X�V
		spriteDatas[spriteIndex]->Updata();

		//�������P�i�߂�
		spriteIndex++;
	}
}

//�܂Ƃ߂ĕ`��
void DebugText::DrawAll()
{
	//�S�Ă̕����̃X�v���C�g�ɂ���
	for (int i = 0; i < spriteIndex; i++)
	{
		//�X�v���C�g�`��
		spriteDatas[i]->Draw();
	}

	spriteIndex = 0;
}