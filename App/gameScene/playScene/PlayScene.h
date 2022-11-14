#pragma once
#include "BaseScene.h"
#include "Object3d.h"
#include "LoadSprite.h"
#include "Sprite.h"
#include "Camera.h"
#include "Player.h"
#include "Enemy.h"
#include "Scroll.h"
#include "CountDown.h"

class PlayScene : public BaseScene
{
public:// �萔
	static const int maxCount = 4;
	static const int maxTimer = 60;

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


private:
	// �v���C���[
	Player* player = nullptr;
	// �G�l�~�[
	Enemy* enemy = nullptr;
	// �X�N���[��
	Scroll* scroll = nullptr;
	// �J�E���g�_�E��
	CountDown* countDown = nullptr;

	char str[100];
};

