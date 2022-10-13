#pragma once
#include "AbstractSceneFactory.h"
/// <summary>
/// シーン工場(具現)
/// </summary>
class SceneFactory : public AbstractSceneFactory
{
public:

	/// <summary>
	/// シーン生成
	/// </summary>
	/// <param name = "SceneName">シーン名</param>
	/// <returns>生成したシーン</returns>
	BaseScene* CreateScene(const std::string& sceneName) override;
};

