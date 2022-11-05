#include "Collision.h"

bool Collision::SphereToSphere(XMFLOAT3 targetA, float radiusA, XMFLOAT3 targetB, float radiusB)
{
    //2�̋��̒��S���W�����ԃx�N�g�������߂�
    XMFLOAT3 vec{};
    vec.x = targetA.x - targetB.x;
    vec.y = targetA.y - targetB.y;
    vec.z = targetA.z - targetB.z;

    //�x�N�g���̒�����2��(2�_�Ԃ̋����� 2��)�����߂�
    float sqLength = vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;

    //2�̋��̔��a�̍��v�����߂�
    float r = radiusA + radiusB;

    //2�_�Ԃ̋�����2�� < ���a�̍��v��2��Ȃ�2�̋��͌������Ă���
    return sqLength < r* r;
}

bool Collision::BoxToBox(const XMFLOAT3& targetA, const XMFLOAT2& radiusA, const XMFLOAT3& targetB, const XMFLOAT2& radiusB)
{
    float distance{};
    // ��̃I�u�W�F�N�g�̋����̍������߂�
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
