#pragma once
#include<d3d12.h>
#include<d3dx12.h>
#include<dxgi1_6.h>
#include<wrl.h>
#include"WinApp.h"

//DirectX基盤
class DirectXCommon
{

private://メンバ関数

	//デバイスの初期化
	void InitializeDevice();

	//コマンド関連の初期化
	void InitializeCommand();

	//スワップチューンの初期化
	void InitializeSwapchain();

	//レンダーターゲットビューの初期化
	void InitializeRenderTargetView();

	//深度バッファの初期化
	void InitializeDepthBuffer();

	//フェンスの初期化
	void InitializeFence();

public://メンバ関数
	//初期化
	void initialize(WinApp* winApp);

	//描画前処理
	void PreDraw();

	//描画後処理
	void PostDraw();

	//デバイス取得
	ID3D12Device* Getdev() { return dev.Get(); }

	//コマンドリスト取得
	ID3D12GraphicsCommandList* GetCmdList() { return cmdList.Get(); }



private:
	//デバイス
	Microsoft::WRL::ComPtr<ID3D12Device> dev;
	//DXGIファクトリー
	Microsoft::WRL::ComPtr<IDXGIFactory6> dxgiFactory;
	//コマンドアロケーター
	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> cmdAllocator;
	//コマンドリスト
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> cmdList;
	//コマンドキュー
	Microsoft::WRL::ComPtr<ID3D12CommandQueue> cmdQueue;
	//スワップチューン
	Microsoft::WRL::ComPtr<IDXGISwapChain4> swapchain;
	//デスクリプタヒープ
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtvHeaps;
	//バックバッファ
	std::vector<Microsoft::WRL::ComPtr<ID3D12Resource>> backBuffers;
	//深度バッファ
	Microsoft::WRL::ComPtr<ID3D12Resource> depthBuffer;
	//フェンス
	Microsoft::WRL::ComPtr<ID3D12Fence> fence;
	//
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> dsvHeap;

	//フェンス値
	UINT64 fenceVal = 0;

	//windowsAPI
	WinApp* winApp = nullptr;

};

