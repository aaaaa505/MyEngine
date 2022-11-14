#pragma once
#include "WinApp.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Audio.h"
#include "DebugText.h"
#include "DrawNumber.h"
#include "LoadSprite.h"
#include "Object3d.h"
#include "Sprite.h"
#include "SceneManager.h"
#include "AbstractSceneFactory.h"

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
	/// ���s
	/// </summary>
	void Run();

	/// <summary>
	/// �X�V
	/// </summary>
	virtual void Updata();

	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw();

protected:
	// �I���t���b�O
	bool endRequest = false;
	// �|�C���^�u����
	WinApp* winApp = nullptr;
	DirectXCommon* dxCommon = nullptr;
	SpriteCommon* spriteCommon = nullptr;
	Input* input = nullptr;
	Audio* audio = nullptr;
	DebugText* debugText = nullptr;
	DrawNumber* drawNumber = nullptr;
	AbstractSceneFactory* sceneFactory = nullptr;

};

