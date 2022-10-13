#pragma once
#include "FrameWork.h"

class PlayScene;

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

private:

	PlayScene* scene = nullptr;
};

