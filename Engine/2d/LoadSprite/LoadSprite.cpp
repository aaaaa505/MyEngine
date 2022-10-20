#include "LoadSprite.h"
#include "SpriteCommon.h"

void LoadSprite::StaticInitialize(SpriteCommon* spriteCommon)
{
	// デバッグテキスト用テクスチャ読み込み
	if (!spriteCommon->LoadTexture(debugTextTexNumber, L"Resources/debugfont.png")) {
		assert(0);
		return;
	}
	// タイトル画像
	if (!spriteCommon->LoadTexture(title_Number, L"Resources/title.png")) {
		assert(0);
		return;
	}
	// エンド画像
	if (!spriteCommon->LoadTexture(end_Number, L"Resources/end.png")) {
		assert(0);
		return;
	}
}
