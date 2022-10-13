#pragma once

// �O���錾
class SceneManager;

class BaseScene
{
public:
	/// <summary>
	/// ���z�f�X�g���N�^
	/// </summary>
	virtual ~BaseScene() = default;

	/// <summary>
	/// ������
	/// </summary>
	virtual void Initialize() = 0;

	/// <summary>
	/// �I��
	/// </summary>
	virtual void Finalize() = 0;

	/// <summary>
	/// �X�V
	/// </summary>
	virtual void Updata() = 0;

	/// <summary>
	/// �`��
	/// </summary>
	virtual void Draw() = 0;

	// �V�[���}�l�[�W���[setter
	virtual void SetSceneManager(SceneManager* sceneManager) { this->sceneManager = sceneManager; }
protected:
	// �V�[���}�l�[�W���[
	SceneManager* sceneManager = nullptr;
};

