#pragma once
#include <DirectXMath.h>

class Collision
{
private:// �G�C���A�X
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;

public:
	//�P�̂ƒP��
	static bool SphereToSphere(XMFLOAT3 targetA, float radiusA, XMFLOAT3 targetB, float radiusB);

	/// <summary>
	/// AABB�̂����蔻��
	/// </summary>
	/// <param name="targetA">�Ώە�A�̍��W</param>
	/// <param name="radiusA">�Ώە�A�̔��a</param>
	/// <param name="targetB">�Ώە�B�̍��W</param>
	/// <param name="radiusB">�Ώە�B�̔��a</param>
	/// <returns></returns>
	static bool BoxToBox(const XMFLOAT3& targetA, const XMFLOAT2& radiusA, const XMFLOAT3& targetB, const XMFLOAT2& radiusB);
};

