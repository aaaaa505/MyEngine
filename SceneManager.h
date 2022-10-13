#pragma once
#include "BaseScene.h"

class SceneManager
{
public:
	~SceneManager();

	/// <summary>
	/// �X�V
	/// </summary>
	void Updata();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	// ���V�[���\��
	void SetNextScene(BaseScene* nextScene) { this->nextScene = nextScene; }

private:
	// ���̃V�[��
	BaseScene* nowScene = nullptr;
	// ���̃V�[��
	BaseScene* nextScene = nullptr;
};

