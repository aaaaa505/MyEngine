#pragma once
#include "FrameWork.h"

class PlayScene;

/// <summary>
/// ゲーム固有クラス
/// </summary>
class MyGame : public FrameWork
{
public:// メンバ関数

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize() override;

	/// <summary>
	/// 終了
	/// </summary>
	void Finalize() override;

	/// <summary>
	/// 更新
	/// </summary>
	void Updata() override;

	/// <summary>
	/// 描画
	/// </summary>
	void Draw() override;

private:

	PlayScene* scene = nullptr;
};

