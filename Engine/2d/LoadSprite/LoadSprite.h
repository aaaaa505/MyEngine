#pragma once
#include "SpriteCommon.h"

enum  SpriteNumber
{
	// デバックテキスト
	debugTextTexNumber,
	
	// タイトルナンバー
	title_Number,

};

class LoadSprite
{
public:// 静的メンバ関数
	/// <summary>
	/// 静的初期化
	/// </summary>
	static void StaticInitialize(SpriteCommon* spriteCommon);
};

