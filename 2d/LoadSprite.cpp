#include "LoadSprite.h"
#include "SpriteCommon.h"

void LoadSprite::StaticInitialize(SpriteCommon* spriteCommon)
{
	// デバッグテキスト用テクスチャ読み込み
	if (!spriteCommon->LoadTexture(debugTextTexNumber, L"Resources/debugfont.png")) {
		assert(0);
		return;
	}
	//サンプル画像1
	if (!spriteCommon->LoadTexture(title_Number, L"Resources/title.png")) {
		assert(0);
		return;
	}
}
