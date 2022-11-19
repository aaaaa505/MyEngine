#include "DrawNumber.h"

DrawNumber* DrawNumber::GetInstance()
{
	static DrawNumber instance;
	return &instance;
}

void DrawNumber::Initialize(UINT texnumber)
{
	//�S�ẴX�v���C�g�f�[�^�ɂ���
	for (int i = 0; i < _countof(spriteDatas); i++)
	{
		// �X�v���C�g�𐶐�����
		spriteDatas[i] = Sprite::Create(texnumber, { 0, 0 });
	}
}

void DrawNumber::Finalize()
{
	for (int i = 0; i < _countof(spriteDatas); i++) {
		delete spriteDatas[i];
	}
}

void DrawNumber::Updata(const std::string& text, const XMFLOAT2& pos, const float& size)
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
		int fontIndex = character - 48;//32
		if (character >= 0x7f) {
			fontIndex = 0;
		}

		int fontIndexY = fontIndex / fontLineCount;
		int fontIndexX = fontIndex % fontLineCount;

		//���W�v�Z
		spriteDatas[spriteIndex]->SetPosition({ pos.x + fontWidth * size * i, pos.y });
		spriteDatas[spriteIndex]->SetTextureRect({ (float)fontIndexX * fontWidth, (float)fontIndexY * fontHeight }, { (float)fontWidth, (float)fontHeight });
		spriteDatas[spriteIndex]->SetSize({ fontWidth * size, fontHeight * size });
		spriteDatas[spriteIndex]->SetAlpha(100.0f);
		//�X�V
		spriteDatas[spriteIndex]->Updata();

		//�������P�i�߂�
		spriteIndex++;
	}
}

void DrawNumber::DrawAll() 
{
	//�S�Ă̕����̃X�v���C�g�ɂ���
	for (int i = 0; i < spriteIndex; i++)
	{
		//�X�v���C�g�`��
		spriteDatas[i]->Draw();
	}

	spriteIndex = 0;
}
