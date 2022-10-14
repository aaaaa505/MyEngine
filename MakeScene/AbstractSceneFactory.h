#pragma once
#include <string>

#include "BaseScene.h"

/// <summary>
/// �V�[���H��(�T�O)
/// </summary>
class AbstractSceneFactory
{
public: 

	/// <summary>
	/// ���z�f�X�g���N�^
	/// </summary>
	virtual ~AbstractSceneFactory() = default;

	/// <summary>
	/// �V�[������
	/// </summary>
	/// <param name = "SceneName">�V�[����</param>
	/// <returns>���������V�[��</returns>
	virtual BaseScene* CreateScene(const std::string& sceneName) = 0;
};

