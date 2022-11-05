#pragma once
#include <DirectXMath.h>

class Collision
{
private:// エイリアス
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;

public:
	//単体と単体
	static bool SphereToSphere(XMFLOAT3 targetA, float radiusA, XMFLOAT3 targetB, float radiusB);

	/// <summary>
	/// AABBのあたり判定
	/// </summary>
	/// <param name="targetA">対象物Aの座標</param>
	/// <param name="radiusA">対象物Aの半径</param>
	/// <param name="targetB">対象物Bの座標</param>
	/// <param name="radiusB">対象物Bの半径</param>
	/// <returns></returns>
	static bool BoxToBox(const XMFLOAT3& targetA, const XMFLOAT2& radiusA, const XMFLOAT3& targetB, const XMFLOAT2& radiusB);
};

