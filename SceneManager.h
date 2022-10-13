#pragma once
#include "BaseScene.h"

class SceneManager
{
public:

	/// <summary>
	/// �C���X�^���X�擾
	/// </summary>
	/// <returns></returns>
	static SceneManager* GetInstance();

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

private:// �O���ŐV���ȃC���X�^���X����点�Ȃ����߂ɉB��
	SceneManager() = default;
	~SceneManager();
	SceneManager(const SceneManager&) = delete;
	void operator= (const SceneManager&) = delete;

private:
	// ���̃V�[��
	BaseScene* nowScene = nullptr;
	// ���̃V�[��
	BaseScene* nextScene = nullptr;
};

