#pragma once

// 前方宣言
class SceneManager;

class BaseScene
{
public:
	/// <summary>
	/// 仮想デストラクタ
	/// </summary>
	virtual ~BaseScene() = default;

	/// <summary>
	/// 初期化
	/// </summary>
	virtual void Initialize() = 0;

	/// <summary>
	/// 終了
	/// </summary>
	virtual void Finalize() = 0;

	/// <summary>
	/// 更新
	/// </summary>
	virtual void Updata() = 0;

	/// <summary>
	/// 描画
	/// </summary>
	virtual void Draw() = 0;

	// シーンマネージャーsetter
	virtual void SetSceneManager(SceneManager* sceneManager) { this->sceneManager = sceneManager; }
protected:
	// シーンマネージャー
	SceneManager* sceneManager = nullptr;
};

