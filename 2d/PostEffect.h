#pragma once
#include "WinApp.h"
#include <Windows.h>
#include <wrl.h>
#include <d3d12.h>
#include <DirectXMath.h>

class PostEffect
{
private: // エイリアス
	// Microsoft::WRL::を省略
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
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


public://メンバ関数
	/// <summary>
	/// コンストラクタ
	/// </summary>
	PostEffect();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(ID3D12Device* device);

	/// <summary>
	/// シーン描画前処理
	/// </summary>
	void PreDrawScene(ID3D12GraphicsCommandList* cmdList);

	/// <summary>
	/// シーン描画後処理
	/// </summary>
	/// <param name="cmdList"></param>
	void PostDrawScene(ID3D12GraphicsCommandList* cmdList);

	/// <summary>
	/// 描画コマンドの発行
	/// </summary>
	void Draw(ID3D12GraphicsCommandList* cmdList);

private://メンバ関数
	/// <summary>
	/// パイプライン生成
	/// </summary>
	void CreateGrapthicsPipelineState();

private://静的メンバ変数
	//画面クリアカラー
	static const float clearColor[4];
	//デバイス
	static ID3D12Device* device;
	// 頂点数
	static const int vertNum = 4;

private://メンバ変数
	//テクスチャバッファ
	ComPtr<ID3D12Resource> texBuff[2];
	//SRV用デスクリプタヒープ
	ComPtr<ID3D12DescriptorHeap> descHeapSRV;
	//深度バッファ
	ComPtr<ID3D12Resource> depthBuff;
	//RTV用のデスクリプタヒープ
	ComPtr<ID3D12DescriptorHeap> descHeapRTV;
	//DSV用のデスクリプタヒープ
	ComPtr<ID3D12DescriptorHeap> descHeapDSV;
	//グラフィックスパイプライン
	ComPtr<ID3D12PipelineState> pipelineState;
	//ルートシグネチャ
	ComPtr<ID3D12RootSignature> rootSignature;
	//頂点バッファ
	ComPtr<ID3D12Resource> vertBuff;
	//定数バッファ
	ComPtr<ID3D12Resource> constBuff;
	//頂点バッファビュー
	D3D12_VERTEX_BUFFER_VIEW vbView{};
	//ワールド行列
	XMMATRIX matWorld;
	//座標
	XMFLOAT2 position = { 0,0 };
	//色(RGBA)
	XMFLOAT4 color = { 1,1,1,1 };
	//Z軸回りの回転角
	float rotation = 0.0f;
};

