#pragma once
#include "FrameWork.h"

/// <summary>
/// �Q�[���ŗL�N���X
/// </summary>
class MyGame : public FrameWork
{
public:// �����o�֐�

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
	Sprite* sprite = nullptr;
};

