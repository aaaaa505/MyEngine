#pragma once
#include "AbstractSceneFactory.h"
/// <summary>
/// �V�[���H��(�)
/// </summary>
class SceneFactory : public AbstractSceneFactory
{
public:

	/// <summary>
	/// �V�[������
	/// </summary>
	/// <param name = "SceneName">�V�[����</param>
	/// <returns>���������V�[��</returns>
	BaseScene* CreateScene(const std::string& sceneName) override;
};

