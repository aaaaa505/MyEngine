#pragma once
#include "SpriteCommon.h"

enum  SpriteNumber
{
	// デバックテキスト
	debugTextTexNumber,
	// 数字テクスチャー
	NumberNumber,
	// タイトル 未選択ナンバー
	title_None_Number,
	// タイトル スタート選択ナンバー
	title_Start_Number,
	// タイトル マニュアル選択ナンバー
	title_Manual_Number,
	// マニュアルナンバー
	manual_Number,
	// エンドナンバー
	end_Number,
	// カウントダウン
	third_Number,
	second_Number,
	first_Number,
	zero_Number,


};

class LoadSprite
{
public:// 静的メンバ関数
	/// <summary>
	/// 静的初期化
	/// </summary>
	static void StaticInitialize(SpriteCommon* spriteCommon);
};

