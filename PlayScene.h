#pragma once
#include "Object3d.h"
#include "Sprite.h"
#include "LoadSprite.h"
#include "Camera.h"

class PlayScene
{
public:
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


private:// �����o�ϐ�
	Model* model = nullptr;
	Object3d* object3d = nullptr;
	Sprite* sprite = nullptr;
	Camera* camera = nullptr;

	char strDebug[100];
};

