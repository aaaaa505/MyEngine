#include "LoadSprite.h"
#include "SpriteCommon.h"

void LoadSprite::StaticInitialize(SpriteCommon* spriteCommon)
{
	// デバッグテキスト用テクスチャ読み込み
	if (!spriteCommon->LoadTexture(debugTextTexNumber, L"Resources/debugfont.png")) {
		assert(0);
		return;
	}
	if (!spriteCommon->LoadTexture(NumberNumber, L"Resources/drawNumber.png")) {
		assert(0);
		return;
	}
#pragma region タイトル関連画像
	if (!spriteCommon->LoadTexture(title_None_Number, L"Resources/title/none.png")) {
		assert(0);
		return;
	}
	if (!spriteCommon->LoadTexture(title_Start_Number, L"Resources/title/start.png")) {
		assert(0);
		return;
	}
	if (!spriteCommon->LoadTexture(title_Manual_Number, L"Resources/title/manual.png")) {
		assert(0);
		return;
	}
#pragma endregion

	// マニュアル画像
	if (!spriteCommon->LoadTexture(manual_Number, L"Resources/manual.png")) {
		assert(0);
		return;
	}
#pragma region カウントダウン画像
	if (!spriteCommon->LoadTexture(third_Number, L"Resources/countDown/third.png")) {
		assert(0);
		return;
	}
	if (!spriteCommon->LoadTexture(second_Number, L"Resources/countDown/second.png")) {
		assert(0);
		return;
	}
	if (!spriteCommon->LoadTexture(first_Number, L"Resources/countDown/first.png")) {
		assert(0);
		return;
	}
	if (!spriteCommon->LoadTexture(zero_Number, L"Resources/countDown/zero.png")) {
		assert(0);
		return;
	}
#pragma endregion

	// エンド画像
	if (!spriteCommon->LoadTexture(scoreBar_Number, L"Resources/scoreBar.png")) {
		assert(0);
		return;
	}
	// エンド画像
	if (!spriteCommon->LoadTexture(crash_Number, L"Resources/crash.png")) {
		assert(0);
		return;
	}
	// エンド画像
	if (!spriteCommon->LoadTexture(result_Number, L"Resources/result.png")) {
		assert(0);
		return;
	}
}
