#pragma once
#include <Windows.h>
#include <wrl.h>
#include <d3d12.h>
#include <DirectXMath.h>
#include "SpriteCommon.h"

class Sprite
{
private: // エイリアス
// Microsoft::WRL::を省略
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::を省略
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

public://サブクラス
//頂点データ
	struct VertexPosUv
	{
		XMFLOAT3 pos;//xyz座標
		XMFLOAT2 uv;//uv座標
	};

	//定数バッファ用データ構造体
	struct ConstBufferData
	{
		XMFLOAT4 color;//色(RGBA)
		XMMATRIX mat;//3D変換行列
	};


public://静的メンバ関数
	//スプライト生成
	static Sprite* Create(SpriteCommon* spriteCommon,
						  UINT texNumber,
						  XMFLOAT2 position,
						  XMFLOAT4 color = {1,1,1,1},
						  XMFLOAT2 anchorpoint = { 0.0f,0.0f },
						  bool isFlipX = false, bool isFlipY = false);

private:// 静的メンバ変数
	static SpriteCommon* spriteCommon;
	// 頂点数
	static const int vertNum = 4;

public://メンバ関数
	//コンストラクタ
	Sprite(UINT texNumber, XMFLOAT2 position, XMFLOAT2 size, XMFLOAT4 color, XMFLOAT2 anchorpoint, bool isFlipX, bool isFlipY);
	//初期化
	bool Initialize(SpriteCommon* spriteCommon);
	//描画
	void Draw();
	//更新
	void Updata();

#pragma region setter
	/// <summary>
	/// 座標の設定
	/// </summary>
	/// <param name="position">座標</param>
	void SetPosition(XMFLOAT2 position) { this->position = position; }

	/// <summary>
	/// 角度の設定
	/// </summary>
	/// <param name="rotation">角度</param>
	void SetRotation(float rotation) { this->rotation = rotation; }

	/// <summary>
	/// サイズの設定
	/// </summary>
	/// <param name="size">サイズ</param>
	void SetSize(XMFLOAT2 size) { this->size = size; TransferVertexBuffer(); }

	/// <summary>
	/// テクスチャ変更
	/// </summary>
	/// <param name="number"></param>
	void SetTexture(UINT textureNumber)
	{
		this->texNumber = textureNumber;

		if (spriteCommon->GetTexBuff(texNumber))
		{
			// テクスチャ情報取得
			D3D12_RESOURCE_DESC resDesc = spriteCommon->GetTexBuff(texNumber)->GetDesc();
			// スプライトのサイズをテクスチャのサイズに設定
			size = { (float)resDesc.Width, (float)resDesc.Height };
		}
	}

	/// <summary>
	/// 透明度の設定
	/// </summary>
	void SetAlpha(float alpha) { this->color.w = alpha; };

	/// <summary>
	/// アンカーポイントの設定
	/// </summary>
	/// <param name="anchorpoint">アンカーポイント</param>
	void SetAnchorPoint(XMFLOAT2 anchorpoint) { this->anchorpoint = anchorpoint; TransferVertexBuffer(); }

	/// <summary>
	/// 左右反転の設定
	/// </summary>
	/// <param name="isFlipX">左右反転</param>
	void SetIsFlipX(bool isFlipX) { this->isFlipX = isFlipX; TransferVertexBuffer(); }

	/// <summary>
	/// 上下反転の設定
	/// </summary>
	/// <param name="isFlipX">上下反転</param>
	void SetIsFlipY(bool isFlipY) { this->isFlipY = isFlipY; TransferVertexBuffer(); }

	/// <summary>
	/// テクスチャ範囲設定
	/// </summary>
	/// <param name="texBase">テクスチャ左上座標</param>
	/// <param name="texSize">テクスチャサイズ</param>
	void SetTextureRect(XMFLOAT2 texLeftTop, XMFLOAT2 texSize)
	{
		this->texLeftTop = texLeftTop;
		this->texSize = texSize;

		TransferVertexBuffer();
	}

	void SetColor(XMFLOAT4 color) { this->color = color; }

#pragma endregion

private:// メンバ関数
	void TransferVertexBuffer();

private://メンバ変数
	//頂点バッファ
	ComPtr<ID3D12Resource> vertBuff;
	//頂点バッファビュー
	D3D12_VERTEX_BUFFER_VIEW vbView{};
	//定数バッファ
	ComPtr<ID3D12Resource> constBuff;
	//Z軸回りの回転角
	float rotation = 0.0f;
	//座標
	XMFLOAT2 position = { 0,0  };
	//ワールド行列
	XMMATRIX matWorld;
	//色(RGBA)
	XMFLOAT4 color = { 1,1,1,1 };
	//テクスチャ番号
	UINT texNumber = 0;
	//大きさ
	XMFLOAT2 size = { 100,100 };
	//アンカーポイント
	XMFLOAT2 anchorpoint = { 0.5f, 0.5f };
	//左右反転
	bool isFlipX = false;
	//上下反転
	bool isFlipY = false;
	//テクスチャ左上座標
	XMFLOAT2 texLeftTop = { 0,0 };
	//テクスチャ切り出しサイズ
	XMFLOAT2 texSize = { 100,100 };
	//非表示
	bool isInvisible = false;
	
};

