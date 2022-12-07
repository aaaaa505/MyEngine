#include "Collision.h"

bool Collision::SphereToSphere(XMFLOAT3 targetA, float radiusA, XMFLOAT3 targetB, float radiusB)
{
    //2つの球の中心座標を結ぶベクトルを求める
    XMFLOAT3 vec{};
    vec.x = targetA.x - targetB.x;
    vec.y = targetA.y - targetB.y;
    vec.z = targetA.z - targetB.z;

    //ベクトルの長さの2乗(2点間の距離の 2乗)を求める
    float sqLength = vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;

    //2つの球の半径の合計を求める
    float r = radiusA + radiusB;

    //2点間の距離の2乗 < 半径の合計の2乗なら2つの球は交差している
    return sqLength < r* r;
}

bool Collision::BoxToBox(const XMFLOAT3& targetA, const XMFLOAT2& radiusA, const XMFLOAT3& targetB, const XMFLOAT2& radiusB)
{
    float distance{};
    // 二つのオブジェクトの距離の差を求める
    distance = targetB.z - targetA.z;
    if (distance < 10.0f)
    {
        XMFLOAT2 max_TargetA{};
        max_TargetA.x = targetA.x + radiusA.x;
        max_TargetA.y = targetA.z + radiusA.y;

        XMFLOAT2 max_TargetB{};
        max_TargetB.x = targetB.x + radiusB.x;
        max_TargetB.y = targetB.z + radiusB.y;

        XMFLOAT2 mini_TargetA{};
        mini_TargetA.x = targetA.x - radiusA.x;
        mini_TargetA.y = targetA.z - radiusA.y;


        XMFLOAT2 mini_TargetB{};
        mini_TargetB.x = targetB.x - radiusB.x;
        mini_TargetB.y = targetB.z - radiusB.y;

        return max_TargetA.x >= mini_TargetB.x && mini_TargetA.x <= max_TargetB.x &&
            max_TargetA.y >= mini_TargetB.y && mini_TargetA.y <= max_TargetB.y;
    }
    else
    {
        return false;
    }
}
