#pragma once
#include <Windows.h>
#include <wrl.h>
#include <d3d12.h>
#include <DirectXMath.h>
class SpriteCommon
{
public:
	static SpriteCommon* GetInstance();

private: // �G�C���A�X
	// Microsoft::WRL::���ȗ�
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::���ȗ�
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;
	using XMMATRIX = DirectX::XMMATRIX;

public://�����o�֐�
	// ������
	void Initialize(ID3D12Device* device, ID3D12GraphicsCommandList* cmdList,int window_width, int window_height);
	// �`��O
	void PreDraw();
	// �`���
	void PostDraw();
	// ���ʃe�N�X�`���̓ǂݍ���
	bool LoadTexture(UINT texnumber, const wchar_t* filename);
	//���[�g�f�X�N���v�^�e�[�u���̐ݒ�
	void SetGraphicsRootDescriptorTable(UINT rootParmeterIndex, UINT texNumber);

	//getter
	ID3D12Resource* GetTexBuff(UINT texNumber);

	ID3D12Device* GetDevice() { return device; }

	ID3D12GraphicsCommandList* GetCmdList() { return cmdList; }

	const XMMATRIX& GetMatProjection() { return matProjection; }

private://�����o�֐�
	//�p�C�v���C������
	void CreateGraphicsPipeline();

public://�T�u�N���X
	struct PipelineSet
	{
		//�p�C�v���C���X�e�[�g�I�u�W�F�N�g
		ComPtr<ID3D12PipelineState> pipelinestate;
		//���[�g�V�O�l�`��
		ComPtr<ID3D12RootSignature> rootsignature;
	};

public://�ÓI�����o�ϐ�
	static const int spriteSRVCount = 512;
	//�f�o�C�X
	static ID3D12Device* device;

private://�����o�ϐ�
	//�p�C�v���C���Z�b�g
	PipelineSet pipelineSet;
	//�ˉe�s��
	XMMATRIX matProjection{};
	//�e�N�X�`�����\�[�X(�e�N�X�`���o�b�t�@)�̔z��
	ComPtr<ID3D12Resource> texBuff[spriteSRVCount] = {};
	//�e�N�X�`���p�f�X�N���v�^�q�[�v�̐���
	ComPtr<ID3D12DescriptorHeap> descHeap = nullptr;
	//�R�}���h���X�g
	ID3D12GraphicsCommandList* cmdList = nullptr;

};

