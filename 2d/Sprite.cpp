#include "Sprite.h"
#include <cassert>
#include <d3dx12.h>
#include <d3dcompiler.h>
#include <DirectXTex.h>

#pragma comment(lib, "d3dcompiler.lib")

using namespace DirectX;
using namespace Microsoft::WRL;

Sprite* Sprite::Create(UINT texNumber, XMFLOAT2 position, XMFLOAT4 color, XMFLOAT2 anchorpoint, bool isFlipX, bool isFlipY)
{
	SpriteCommon* spriteCommon = SpriteCommon::GetInstance();

	//���T�C�Y
	XMFLOAT2 size = { 0.0f, 0.0f };

	if (spriteCommon->GetTexBuff(texNumber))
	{
		// �e�N�X�`�����擾
		D3D12_RESOURCE_DESC resDesc = spriteCommon->GetTexBuff(texNumber)->GetDesc();
		// �X�v���C�g�̃T�C�Y���e�N�X�`���̃T�C�Y�ɐݒ�
		size = { (float)resDesc.Width, (float)resDesc.Height };
	}

	//Sprite�̃C���X�^���X�𐶐�
	Sprite* sprite = new Sprite(texNumber, position, size, color, anchorpoint, isFlipX, isFlipY);
	if (sprite == nullptr) {
		return nullptr;
	}

	if (!sprite->Initialize())
	{
		delete sprite;
		assert(0);
		return nullptr;
	}


	return sprite;
}

Sprite::Sprite(UINT texNumber, XMFLOAT2 position, XMFLOAT2 size, XMFLOAT4 color, XMFLOAT2 anchorpoint, bool isFlipX, bool isFlipY)
{
	this->position = position;
	this->size = size;
	this->anchorpoint = anchorpoint;
	this->matWorld = XMMatrixIdentity();
	this->color = color;
	this->texNumber = texNumber;
	this->isFlipX = isFlipX;
	this->isFlipY = isFlipY;
	this->texSize = size;
}

bool Sprite::Initialize()
{
	HRESULT result = S_FALSE;

	SpriteCommon* spriteCommon = SpriteCommon::GetInstance();

	//���_�o�b�t�@����
	result = spriteCommon->GetDevice()->CreateCommittedResource(
		&CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD),
		D3D12_HEAP_FLAG_NONE,
		&CD3DX12_RESOURCE_DESC::Buffer(sizeof(VertexPosUv) * vertNum),
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS(&vertBuff));
	if (FAILED(result)) {
		assert(0);
		return false;
	}

	//���_�o�b�t�@�f�[�^�]��
	TransferVertexBuffer();

	//���_�o�b�t�@�r���[�̍쐬
	vbView.BufferLocation = vertBuff->GetGPUVirtualAddress();
	vbView.SizeInBytes = sizeof(VertexPosUv) * 4;
	vbView.StrideInBytes = sizeof(VertexPosUv);

	//�萔�o�b�t�@�̐���
	result = spriteCommon->GetDevice()->CreateCommittedResource(
		&CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD),
		D3D12_HEAP_FLAG_NONE,
		&CD3DX12_RESOURCE_DESC::Buffer((sizeof(ConstBufferData) + 0xff) & ~0xff),
		D3D12_RESOURCE_STATE_GENERIC_READ, nullptr,
		IID_PPV_ARGS(&constBuff));
	if (FAILED(result)) {
		assert(0);
		return false;
	}


	//�萔�o�b�t�@�Ƀf�[�^�]��
	ConstBufferData* constMap = nullptr;
	result = constBuff->Map(0, nullptr, (void**)&constMap);
	constMap->color = color; //�F�w��iRGBA�j
	constMap->mat = spriteCommon->GetMatProjection();
		constBuff->Unmap(0, nullptr);

	return true;
}

void Sprite::TransferVertexBuffer()
{
	SpriteCommon* spriteCommon = SpriteCommon::GetInstance();

	HRESULT result = S_FALSE;
	//�����A����A�E���A�E��
	enum { LB, LT, RB, RT };

	float left = (0.0f - anchorpoint.x) * size.x;
	float right = (1.0f - anchorpoint.x) * size.x;
	float top = (0.0f - anchorpoint.y) * size.y;
	float bottom = (1.0f - anchorpoint.y) * size.y;

	if (isFlipX)
	{//���E����ւ�
		left = -left;
		right = -right;
	}

	if (isFlipY)
	{//���E����ւ�
		top = -top;
		bottom = -bottom;
	}

	VertexPosUv vertices[vertNum];

	vertices[LB].pos = { left, bottom,  0.0f }; // ����
	vertices[LT].pos = { left, top,     0.0f }; // ����
	vertices[RB].pos = { right, bottom, 0.0f }; // �E��
	vertices[RT].pos = { right, top,    0.0f }; // �E��

	//�w��ԍ��̉摜���ǂݍ��ݍς݂Ȃ�
	if (spriteCommon->GetTexBuff(this->texNumber)) {
		//�e�N�X�`�����擾
		D3D12_RESOURCE_DESC resDesc = spriteCommon->GetTexBuff(this->texNumber)->GetDesc();

		float tex_left = texLeftTop.x / resDesc.Width;
		float tex_right = (texLeftTop.x + texSize.x) / resDesc.Width;
		float tex_top = texLeftTop.y / resDesc.Height;
		float tex_bottom = (texLeftTop.y + texSize.y) / resDesc.Height;

		vertices[LB].uv = { tex_left,   tex_bottom }; //����
		vertices[LT].uv = { tex_left,   tex_top }; //����
		vertices[RB].uv = { tex_right,  tex_bottom }; //�E��
		vertices[RT].uv = { tex_right,  tex_top }; //�E��
	}

	//���_�o�b�t�@�ւ̃f�[�^�]��
	VertexPosUv* vertMap = nullptr;
	result = vertBuff->Map(0, nullptr, (void**)&vertMap);
	memcpy(vertMap, vertices, sizeof(vertices));
	vertBuff->Unmap(0, nullptr);
}

void Sprite::Updata()
{
	SpriteCommon* spriteCommon = SpriteCommon::GetInstance();
	//���[���h�s��̍X�V
	matWorld = XMMatrixIdentity();
	//Z����]
	matWorld *= XMMatrixRotationZ(XMConvertToRadians(rotation));
	//���s�ړ�
	matWorld *= XMMatrixTranslation(position.x, position.y, 0.0f);

	//�萔�o�b�t�@�̓]��
	ConstBufferData* constMap = nullptr;
	HRESULT result = constBuff->Map(0, nullptr, (void**)&constMap);
	constMap->mat = matWorld * spriteCommon->GetMatProjection();
	constMap->color = color;
	constBuff->Unmap(0, nullptr);
}

void Sprite::Draw()
{
	SpriteCommon* spriteCommon = SpriteCommon::GetInstance();

	if (isInvisible) {
		return;
	}

	ID3D12GraphicsCommandList* cmdList = spriteCommon->GetCmdList();

	//���_�o�b�t�@���Z�b�g
	cmdList->IASetVertexBuffers(0, 1, &vbView);

	//���[�g�p�����[�^0�Ԃɒ萔�o�b�t�@���Z�b�g
	cmdList->SetGraphicsRootConstantBufferView(0, constBuff->GetGPUVirtualAddress());

	//���[�g�p�����[�^1�ԂɃV�F�[�_�[���\�[�X�r���[���Z�b�g
	spriteCommon->SetGraphicsRootDescriptorTable(1, texNumber);

	//�|���S���̕`��i4���_�Ŏl�p�`�j
	cmdList->DrawInstanced(4, 1, 0, 0);
}
