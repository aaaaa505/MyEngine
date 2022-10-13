#include "MyGame.h"

//Windowsアプリのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	MyGame game;
	// ゲームの初期化
	game.Initialize();
	while (true)// ゲームループ
	{
		// 毎フレーム更新
		game.Updata();
		// 終了リクエストが来たら抜ける
		if (game.Getter() == true)
		{
			break;
		}
		// 描画
		game.Draw();
	}
	// 終了処理
	game.Finalize();
	return 0;
}
