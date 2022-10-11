#pragma once
#include <Windows.h>
#include <string>
#include "Sprite.h"

class DebugText
{
public: //定数の宣言    
	static const int maxCharCount = 256;//最大文字数
	static const int fontWidth = 9;//フォント画像内1文字分の横幅
	static const int fontHeight = 18;//フォント画像内1文字分の縦幅
	static const int fontLineCount = 14;//フォント画像内1行分の文字数

public: //メンバ関数
	// コンストラクタ
	DebugText();
	// デストラクタ
	~DebugText();
	// 生成
	static DebugText* Create(SpriteCommon* spriteCommon, UINT texnumber);
	// 初期化
	void Initialize(SpriteCommon* spriteCommon, UINT texnumber);
	// 
	void Print(const std::string& text, float x, float y, float size);
	// 描画
	void DrawAll();

private: //メンバ変数   
	//スプライト共通部分
	SpriteCommon* spriteCommon;
	//スプライトデータの配列
	Sprite* spriteDatas[maxCharCount] = {};
	//スプライトデータ配列の添え字番号
	int spriteIndex = 0;
};