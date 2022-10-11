#pragma once
#include "SpriteCommon.h"

enum  SpriteNumber
{
	// デバックテキスト
	debugTextTexNumber,
	
	sample1,
	sample2,

};

class LoadSprite
{
public:// 静的メンバ関数
	/// <summary>
	/// 静的初期化
	/// </summary>
	void static StaticInitialize(SpriteCommon* spriteCommon);
};

