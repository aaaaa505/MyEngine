#pragma once
#include<d3d12.h>
#include<d3dx12.h>
#include<dxgi1_6.h>
#include<wrl.h>
#include"WinApp.h"

//DirectX���
class DirectXCommon
{

private://�����o�֐�

	//�f�o�C�X�̏�����
	void InitializeDevice();

	//�R�}���h�֘A�̏�����
	void InitializeCommand();

	//�X���b�v�`���[���̏�����
	void InitializeSwapchain();

	//�����_�[�^�[�Q�b�g�r���[�̏�����
	void InitializeRenderTargetView();

	//�[�x�o�b�t�@�̏�����
	void InitializeDepthBuffer();

	//�t�F���X�̏�����
	void InitializeFence();

public://�����o�֐�
	//������
	void initialize(WinApp* winApp);

	//�`��O����
	void PreDraw();

	//�`��㏈��
	void PostDraw();

	//�f�o�C�X�擾
	ID3D12Device* Getdev() { return dev.Get(); }

	//�R�}���h���X�g�擾
	ID3D12GraphicsCommandList* GetCmdList() { return cmdList.Get(); }



private:
	//�f�o�C�X
	Microsoft::WRL::ComPtr<ID3D12Device> dev;
	//DXGI�t�@�N�g���[
	Microsoft::WRL::ComPtr<IDXGIFactory6> dxgiFactory;
	//�R�}���h�A���P�[�^�[
	Microsoft::WRL::ComPtr<ID3D12CommandAllocator> cmdAllocator;
	//�R�}���h���X�g
	Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> cmdList;
	//�R�}���h�L���[
	Microsoft::WRL::ComPtr<ID3D12CommandQueue> cmdQueue;
	//�X���b�v�`���[��
	Microsoft::WRL::ComPtr<IDXGISwapChain4> swapchain;
	//�f�X�N���v�^�q�[�v
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> rtvHeaps;
	//�o�b�N�o�b�t�@
	std::vector<Microsoft::WRL::ComPtr<ID3D12Resource>> backBuffers;
	//�[�x�o�b�t�@
	Microsoft::WRL::ComPtr<ID3D12Resource> depthBuffer;
	//�t�F���X
	Microsoft::WRL::ComPtr<ID3D12Fence> fence;
	//
	Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> dsvHeap;

	//�t�F���X�l
	UINT64 fenceVal = 0;

	//windowsAPI
	WinApp* winApp = nullptr;

};

