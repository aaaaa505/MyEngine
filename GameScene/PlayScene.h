#pragma once
#include "BaseScene.h"
#include "Object3d.h"
#include "LoadSprite.h"
#include "Camera.h"
#include "Player.h"

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
	// �O�����h
	Model* model = nullptr;
	Object3d* obj = nullptr;
	// �f�o�b�O�e�L�X�g�p
	char strDebug[100];
};

