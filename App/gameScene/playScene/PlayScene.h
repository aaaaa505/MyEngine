#pragma once
#include "BaseScene.h"
#include "Object3d.h"
#include "LoadSprite.h"
#include "Camera.h"
#include "Player.h"
#include "Enemy.h"
#include "Scroll.h"

class PlayScene : public BaseScene
{
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
	// �f�o�b�O�e�L�X�g�p
	char strDebug[100];
};

