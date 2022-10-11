//#pragma once
//
//#include "FbxModel.h"
//#include "Camera.h"
//
//#include <Windows.h>
//#include <wrl.h>
//#include <d3d12.h>
//#include <d3dx12.h>
//#include <DirectXMath.h>
//#include <string>
//
//class FbxObject3d
//{
//
//private: // �G�C���A�X
//	// Microsoft::WRL::���ȗ�
//	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
//	// DirectX::���ȗ�
//	using XMFLOAT2 = DirectX::XMFLOAT2;
//	using XMFLOAT3 = DirectX::XMFLOAT3;
//	using XMFLOAT4 = DirectX::XMFLOAT4;
//	using XMMATRIX = DirectX::XMMATRIX;
//
//public://�萔
//	//�{�[���̍ő吔
//	static const int MAX_BONES = 32;
//
//public://�T�u�N���X
//	//�萔�o�b�t�@�p�f�[�^�\����(���W�ϊ��s��p)
//	struct ConstBufferDatatransform
//	{
//		XMMATRIX viewproj;//�r���[�v���W�F�N�V�����s��
//		XMMATRIX world;//���[���h�s��
//		XMFLOAT3 cameraPos;//�J�������W(���[���h�s��)
//	};
//
//	//�萔�o�b�t�@�p�f�[�^�\����(�X�L�j���O)
//	struct ConstBufferDataSkin
//	{
//		XMMATRIX bones[MAX_BONES];
//	};
//
//public://�����o�֐�
//	/// <summary>
//	/// ������
//	/// </summary>
//	void initialize();
//
//protected://�����o�ϐ�
//	ComPtr<ID3D12Resource> constBuffTransform;
//	ComPtr<ID3D12Resource> constBuffSkin;
//
//public://�ÓI�����o�ϐ�
//	//setter
//	static void SetDevice(ID3D12Device* device) { FbxObject3d::device = device; }
//	static void SetCamera(Camera* camera) { FbxObject3d::camera = camera; }
//
//	/// <summary>
//	/// �O���t�B�b�N�X�p�C�v���C���̐���
//	/// </summary>
//	static void CreateGraphicsPipeline();
//
//	/// <summary>
//	/// ���t���[������
//	/// </summary>
//	void Updata();
//
//	/// <summary>
//	/// ���f���̃Z�b�g
//	/// </summary>
//	/// <param name="fbxmodel"></param>
//	void SetFbxModel(FbxModel* fbxmodel) { this->fbxmodel = fbxmodel; }
//
//	/// <summary>
//	/// �`��
//	/// </summary>
//	void Draw(ID3D12GraphicsCommandList* cmdList);
//
//	/// <summary>
//	/// �A�j���[�V�����J�n
//	/// </summary>
//	void PlayAnimation();
//
//	//setter
//	void SetRotaion(XMFLOAT3 rotation) { this->rotation = rotation; }
//	/// <summary>
//	/// �T�C�Y
//	/// </summary>
//	void SetScale(XMFLOAT3 scale) { this->scale = scale; }
//
//	/// <summary>
//	/// ���W
//	/// </summary>
//	/// <param name="position"></param>
//	void SetPosition(XMFLOAT3 position) { this->position = position; }
//
//
//private://�ÓI�����o�ϐ�
//	//�f�o�C�X
//	static ID3D12Device* device;
//	//�J����
//	static Camera* camera;
//	//���[�g�V�O�l�`��
//	static ComPtr<ID3D12RootSignature> rootsignature;
//	//�p�C�v���C���X�e�[�g�I�u�W�F�N�g
//	static ComPtr<ID3D12PipelineState> pipelinestate;
//
//protected://�����o�ϐ�
//	//���[�J���X�P�[��
//	XMFLOAT3 scale = { 1,1,1 };
//	//x,y,z�����̃��[�J����]�p
//	XMFLOAT3 rotation = { 0,0,0 };
//	//���[�J�����W
//	XMFLOAT3 position = { 0,0,0 };
//	//���[�J�����[���h�s��ϊ��s��
//	XMMATRIX matWorld;
//	//���f��
//	FbxModel* fbxmodel = nullptr;
//	//1�t���[���̎���
//	FbxTime frameTime;
//	//�A�j���[�V�����J�n����
//	FbxTime startTime;
//	//�A�j���[�V�����I������
//	FbxTime endTime;
//	//���ݎ���
//	FbxTime currentTime;
//	//�A�j���[�V�����Đ���
//	bool isPlay = false;
//
//};