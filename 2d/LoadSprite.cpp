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
	if (!spriteCommon->LoadTexture(sample1, L"Resources/texture1.png")) {
		assert(0);
		return;
	}
	//サンプル画像2
	if (!spriteCommon->LoadTexture(sample2, L"Resources/texture2.png")) {
		assert(0);
		return;
	}
}
