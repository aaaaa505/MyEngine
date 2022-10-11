#pragma once
#include "WinApp.h"
#include <Windows.h>
#include <wrl.h>
#include <d3d12.h>
#include <DirectXMath.h>

class PostEffect
{
private: // �G�C���A�X
	// Microsoft::WRL::���ȗ�
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

public://�T�u�N���X
//���_�f�[�^
	struct VertexPosUv
	{
		XMFLOAT3 pos;//xyz���W
		XMFLOAT2 uv;//uv���W
	};

	//�萔�o�b�t�@�p�f�[�^�\����
	struct ConstBufferData
	{
		XMFLOAT4 color;//�F(RGBA)
		XMMATRIX mat;//3D�ϊ��s��
	};


public://�����o�֐�
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	PostEffect();

	/// <summary>
	/// ������
	/// </summary>
	void Initialize(ID3D12Device* device);

	/// <summary>
	/// �V�[���`��O����
	/// </summary>
	void PreDrawScene(ID3D12GraphicsCommandList* cmdList);

	/// <summary>
	/// �V�[���`��㏈��
	/// </summary>
	/// <param name="cmdList"></param>
	void PostDrawScene(ID3D12GraphicsCommandList* cmdList);

	/// <summary>
	/// �`��R�}���h�̔��s
	/// </summary>
	void Draw(ID3D12GraphicsCommandList* cmdList);

private://�����o�֐�
	/// <summary>
	/// �p�C�v���C������
	/// </summary>
	void CreateGrapthicsPipelineState();

private://�ÓI�����o�ϐ�
	//��ʃN���A�J���[
	static const float clearColor[4];
	//�f�o�C�X
	static ID3D12Device* device;
	// ���_��
	static const int vertNum = 4;

private://�����o�ϐ�
	//�e�N�X�`���o�b�t�@
	ComPtr<ID3D12Resource> texBuff[2];
	//SRV�p�f�X�N���v�^�q�[�v
	ComPtr<ID3D12DescriptorHeap> descHeapSRV;
	//�[�x�o�b�t�@
	ComPtr<ID3D12Resource> depthBuff;
	//RTV�p�̃f�X�N���v�^�q�[�v
	ComPtr<ID3D12DescriptorHeap> descHeapRTV;
	//DSV�p�̃f�X�N���v�^�q�[�v
	ComPtr<ID3D12DescriptorHeap> descHeapDSV;
	//�O���t�B�b�N�X�p�C�v���C��
	ComPtr<ID3D12PipelineState> pipelineState;
	//���[�g�V�O�l�`��
	ComPtr<ID3D12RootSignature> rootSignature;
	//���_�o�b�t�@
	ComPtr<ID3D12Resource> vertBuff;
	//�萔�o�b�t�@
	ComPtr<ID3D12Resource> constBuff;
	//���_�o�b�t�@�r���[
	D3D12_VERTEX_BUFFER_VIEW vbView{};
	//���[���h�s��
	XMMATRIX matWorld;
	//���W
	XMFLOAT2 position = { 0,0 };
	//�F(RGBA)
	XMFLOAT4 color = { 1,1,1,1 };
	//Z�����̉�]�p
	float rotation = 0.0f;
};

