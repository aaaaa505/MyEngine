#pragma once
#include <Windows.h>
#include <string>
#include "Sprite.h"

class DebugText
{
private:// エイリアス

	// DirectX::を省略
	using XMFLOAT2 = DirectX::XMFLOAT2;

public://定数の宣言
	static const int maxCharCount = 256;	//最大文字数
	static const int fontWidth = 9;			//フォント画像内1文字分の横幅
	static const int fontHeight = 18;		//フォント画像内1文字分の縦幅
	static const int fontLineCount = 14;	//フォント画像内1行分の文字数

public://メンバ関数

	/// <summary>
	/// インスタンスの取得
	/// </summary>
	/// <returns></returns>
	static DebugText* GetInstance();

	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="texnumber"></param>
	void Initialize(UINT texnumber);

	/// <summary>
	/// 終了
	/// </summary>
	void Finalize();

	/// <summary>
	/// 文字列更新
	/// </summary>
	/// <param name="text">文字格納用</param>
	/// <param name="pos">座標</param>
	/// <param name="size">大きさ</param>
	void Print(const std::string& text, const XMFLOAT2& pos, const float& size);

	/// <summary>
	/// 全描画
	/// </summary>
	void DrawAll();

private: //メンバ変数

	// スプライトデータの配列
	Sprite* spriteDatas[maxCharCount] = {};
	// スプライトデータ配列の添え字番号
	int32_t spriteIndex = 0;
};