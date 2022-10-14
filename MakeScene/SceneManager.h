#pragma once
#include "BaseScene.h"
#include "AbstractSceneFactory.h"

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

	/// <summary>
	/// ���V�[���\��
	/// </summary>
	/// <param name="sceneName">�V�[����</param>
	void ChangeScene(const std::string& sceneName);

	
	void SetSceneFactory(AbstractSceneFactory* sceneFactory) { this->sceneFactory = sceneFactory; }

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
	// �V�[���t�@�N�g���[
	AbstractSceneFactory* sceneFactory = nullptr;
};

