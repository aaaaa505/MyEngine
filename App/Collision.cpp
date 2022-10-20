#include "Collision.h"

bool Collision::SphereSphere(XMFLOAT3 targetA, float radiusA, XMFLOAT3 targetB, float radiusB)
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
