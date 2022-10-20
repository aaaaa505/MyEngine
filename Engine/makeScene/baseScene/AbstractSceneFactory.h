#pragma once
#include <string>

#include "BaseScene.h"

/// <summary>
/// シーン工場(概念)
/// </summary>
class AbstractSceneFactory
{
public: 

	/// <summary>
	/// 仮想デストラクタ
	/// </summary>
	virtual ~AbstractSceneFactory() = default;

	/// <summary>
	/// シーン生成
	/// </summary>
	/// <param name = "SceneName">シーン名</param>
	/// <returns>生成したシーン</returns>
	virtual BaseScene* CreateScene(const std::string& sceneName) = 0;
};

