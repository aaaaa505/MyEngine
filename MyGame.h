#pragma once
#include "WinApp.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "DebugText.h"
#include "Object3d.h"
#include "LoadSprite.h"
#include "Sprite.h"
#include "Camera.h"
#include "PostEffect.h"

/// <summary>
/// �Q�[���ŗL�N���X
/// </summary>
class MyGame
{
public:// �����o�֐�

	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �I��
	/// </summary>
	void Finalize();

	/// <summary>
	/// �X�V
	/// </summary>
	void Updata();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	bool Getter() { return endRequest; }

private:// �����o�ϐ�
	bool endRequest = false;
	// �|�C���^�u����
	WinApp* winApp = nullptr;
	DirectXCommon* dxCommon = nullptr;
	SpriteCommon* spriteCommon = nullptr;
	Input* input = nullptr;
	DebugText* debugText = nullptr;
	Camera* camera = nullptr;

	Model* model = nullptr;
	Object3d* object3d = nullptr;
	Sprite* sprite = nullptr;
};

