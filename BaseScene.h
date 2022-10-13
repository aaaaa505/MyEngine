#pragma once

// �O���錾
class SceneManager;

class BaseScene
{
public:
	BaseScene(SceneManager* sceneManager);

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

protected:
	// �V�[���}�l�[�W���[
	SceneManager* sceneManager = nullptr;
};

