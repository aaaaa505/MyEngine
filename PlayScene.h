#pragma once
#include "BaseScene.h"
#include "Object3d.h"
#include "LoadSprite.h"
#include "Camera.h"

class PlayScene : public BaseScene
{
public:
	PlayScene(SceneManager* sceneManager);

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
	Model* model = nullptr;
	Object3d* object3d = nullptr;
	Camera* camera = nullptr;

	char strDebug[100];
};

