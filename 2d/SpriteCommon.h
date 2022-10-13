#pragma once
#include <Windows.h>
#include <wrl.h>
#include <d3d12.h>
#include <DirectXMath.h>
class SpriteCommon
{
public:
	static SpriteCommon* GetInstance();

private: // エイリアス
	// Microsoft::WRL::を省略
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::を省略
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

public://メンバ関数
	// 初期化
	void Initialize(ID3D12Device* device, ID3D12GraphicsCommandList* cmdList,int window_width, int window_height);
	// 描画前
	void PreDraw();
	// 描画後
	void PostDraw();
	// 共通テクスチャの読み込み
	bool LoadTexture(UINT texnumber, const wchar_t* filename);
	//ルートデスクリプタテーブルの設定
	void SetGraphicsRootDescriptorTable(UINT rootParmeterIndex, UINT texNumber);

	//getter
	ID3D12Resource* GetTexBuff(UINT texNumber);

	ID3D12Device* GetDevice() { return device; }

	ID3D12GraphicsCommandList* GetCmdList() { return cmdList; }

	const XMMATRIX& GetMatProjection() { return matProjection; }

private://メンバ関数
	//パイプライン生成
	void CreateGraphicsPipeline();

public://サブクラス
	struct PipelineSet
	{
		//パイプラインステートオブジェクト
		ComPtr<ID3D12PipelineState> pipelinestate;
		//ルートシグネチャ
		ComPtr<ID3D12RootSignature> rootsignature;
	};

public://静的メンバ変数
	static const int spriteSRVCount = 512;
	//デバイス
	static ID3D12Device* device;

private://メンバ変数
	//パイプラインセット
	PipelineSet pipelineSet;
	//射影行列
	XMMATRIX matProjection{};
	//テクスチャリソース(テクスチャバッファ)の配列
	ComPtr<ID3D12Resource> texBuff[spriteSRVCount] = {};
	//テクスチャ用デスクリプタヒープの生成
	ComPtr<ID3D12DescriptorHeap> descHeap = nullptr;
	//コマンドリスト
	ID3D12GraphicsCommandList* cmdList = nullptr;

};

