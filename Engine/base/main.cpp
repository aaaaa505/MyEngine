#include "MyGame.h"

//Windowsアプリのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	FrameWork* game = new MyGame();
	
	game->Run();

	delete game;

	return 0;
}
