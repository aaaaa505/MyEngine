#pragma once
#include "WinApp.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "DebugText.h"
#include "LoadSprite.h"
#include "Camera.h"
#include "Object3d.h"
#include "Sprite.h"

class FrameWork
{

public:// �����o�֐�

	/// <summary>
	/// ������
	/// </summary>
	virtual void Initialize();

	/// <summary>
	/// �I��
	/// </summary>
	virtual void Finalize();

	/// <summary>
	/// �X�V
	/// </summary>
	virtual void Updata();

	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw() = 0;

	// getter
	bool Getter() { return endRequest; }

protected: // �����o�ϐ�
	bool endRequest = false;
	// �|�C���^�u����
	WinApp* winApp = nullptr;
	DirectXCommon* dxCommon = nullptr;
	SpriteCommon* spriteCommon = nullptr;
	Input* input = nullptr;
	DebugText* debugText = nullptr;
	Camera* camera = nullptr;
};

