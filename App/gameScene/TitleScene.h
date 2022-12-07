#pragma once
#include "BaseScene.h"
#include "Sprite.h"
#include "LoadSprite.h"
#include "Camera.h"

class TitleScene : public BaseScene
{
public:// �萔
	static const int maxTex = 3;// �^�C�g���摜�̍ő吔

public:
	enum Select
	{
		start = 1,
		manual,
	};

public:
	/// <summary>
	/// ������
	/// </summary>
	void Initialize() override;

	/// <summary>
	/// �I��
	/// </summary>
	void Finalize() override;

	/// <summary>
	/// �X�V
	/// </summary>
	void Updata() override;

	/// <summary>
	/// �`��
	/// </summary>
	void Draw() override;

private:// �����o�ϐ�
	Sprite* sprites[maxTex];
	USHORT texFlag = 0;
};

