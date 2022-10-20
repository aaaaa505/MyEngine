#pragma once
#include <DirectXMath.h>

class Collision
{
private://�G�C���A�X
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;

public:
	//�P�̂ƒP��
	static bool SphereSphere(XMFLOAT3 targetA, float radiusA, XMFLOAT3 targetB, float radiusB);

};

