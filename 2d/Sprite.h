#pragma once
#include <Windows.h>
#include <wrl.h>
#include <d3d12.h>
#include <DirectXMath.h>
#include "SpriteCommon.h"

class Sprite
{
private: // �G�C���A�X
// Microsoft::WRL::���ȗ�
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;
	// DirectX::���ȗ�
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


public://�ÓI�����o�֐�
	//�X�v���C�g����
	static Sprite* Create(SpriteCommon* spriteCommon,
						  UINT texNumber,
						  XMFLOAT2 position,
						  XMFLOAT4 color = {1,1,1,1},
						  XMFLOAT2 anchorpoint = { 0.0f,0.0f },
						  bool isFlipX = false, bool isFlipY = false);

private:// �ÓI�����o�ϐ�
	static SpriteCommon* spriteCommon;
	// ���_��
	static const int vertNum = 4;

public://�����o�֐�
	//�R���X�g���N�^
	Sprite(UINT texNumber, XMFLOAT2 position, XMFLOAT2 size, XMFLOAT4 color, XMFLOAT2 anchorpoint, bool isFlipX, bool isFlipY);
	//������
	bool Initialize(SpriteCommon* spriteCommon);
	//�`��
	void Draw();
	//�X�V
	void Updata();

#pragma region setter
	/// <summary>
	/// ���W�̐ݒ�
	/// </summary>
	/// <param name="position">���W</param>
	void SetPosition(XMFLOAT2 position) { this->position = position; }

	/// <summary>
	/// �p�x�̐ݒ�
	/// </summary>
	/// <param name="rotation">�p�x</param>
	void SetRotation(float rotation) { this->rotation = rotation; }

	/// <summary>
	/// �T�C�Y�̐ݒ�
	/// </summary>
	/// <param name="size">�T�C�Y</param>
	void SetSize(XMFLOAT2 size) { this->size = size; TransferVertexBuffer(); }

	/// <summary>
	/// �e�N�X�`���ύX
	/// </summary>
	/// <param name="number"></param>
	void SetTexture(UINT textureNumber)
	{
		this->texNumber = textureNumber;

		if (spriteCommon->GetTexBuff(texNumber))
		{
			// �e�N�X�`�����擾
			D3D12_RESOURCE_DESC resDesc = spriteCommon->GetTexBuff(texNumber)->GetDesc();
			// �X�v���C�g�̃T�C�Y���e�N�X�`���̃T�C�Y�ɐݒ�
			size = { (float)resDesc.Width, (float)resDesc.Height };
		}
	}

	/// <summary>
	/// �����x�̐ݒ�
	/// </summary>
	void SetAlpha(float alpha) { this->color.w = alpha; };

	/// <summary>
	/// �A���J�[�|�C���g�̐ݒ�
	/// </summary>
	/// <param name="anchorpoint">�A���J�[�|�C���g</param>
	void SetAnchorPoint(XMFLOAT2 anchorpoint) { this->anchorpoint = anchorpoint; TransferVertexBuffer(); }

	/// <summary>
	/// ���E���]�̐ݒ�
	/// </summary>
	/// <param name="isFlipX">���E���]</param>
	void SetIsFlipX(bool isFlipX) { this->isFlipX = isFlipX; TransferVertexBuffer(); }

	/// <summary>
	/// �㉺���]�̐ݒ�
	/// </summary>
	/// <param name="isFlipX">�㉺���]</param>
	void SetIsFlipY(bool isFlipY) { this->isFlipY = isFlipY; TransferVertexBuffer(); }

	/// <summary>
	/// �e�N�X�`���͈͐ݒ�
	/// </summary>
	/// <param name="texBase">�e�N�X�`��������W</param>
	/// <param name="texSize">�e�N�X�`���T�C�Y</param>
	void SetTextureRect(XMFLOAT2 texLeftTop, XMFLOAT2 texSize)
	{
		this->texLeftTop = texLeftTop;
		this->texSize = texSize;

		TransferVertexBuffer();
	}

	void SetColor(XMFLOAT4 color) { this->color = color; }

#pragma endregion

private:// �����o�֐�
	void TransferVertexBuffer();

private://�����o�ϐ�
	//���_�o�b�t�@
	ComPtr<ID3D12Resource> vertBuff;
	//���_�o�b�t�@�r���[
	D3D12_VERTEX_BUFFER_VIEW vbView{};
	//�萔�o�b�t�@
	ComPtr<ID3D12Resource> constBuff;
	//Z�����̉�]�p
	float rotation = 0.0f;
	//���W
	XMFLOAT2 position = { 0,0  };
	//���[���h�s��
	XMMATRIX matWorld;
	//�F(RGBA)
	XMFLOAT4 color = { 1,1,1,1 };
	//�e�N�X�`���ԍ�
	UINT texNumber = 0;
	//�傫��
	XMFLOAT2 size = { 100,100 };
	//�A���J�[�|�C���g
	XMFLOAT2 anchorpoint = { 0.5f, 0.5f };
	//���E���]
	bool isFlipX = false;
	//�㉺���]
	bool isFlipY = false;
	//�e�N�X�`��������W
	XMFLOAT2 texLeftTop = { 0,0 };
	//�e�N�X�`���؂�o���T�C�Y
	XMFLOAT2 texSize = { 100,100 };
	//��\��
	bool isInvisible = false;
	
};

