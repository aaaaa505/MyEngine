#include "Scroll.h"

Scroll* Scroll::Create()
{
	// �C���X�^���X����
	Scroll* instance = new Scroll();

	// �C���X�^���X������
	instance->Initialize();

	// �C���X�^���X��Ԃ�
	return instance;
}

Scroll::~Scroll()
{
	for (int i = 0; i < MAX_PLATE; i++)
	{
		delete(plate[i]);
	}
}

void Scroll::Initialize()
{
	// �l�N�X�g
	plate[first] = Field::Create("plateSetthing");
	basePos[first] = { 0.0f, 0.0f, radius };
	plate[first]->SetPosition(basePos[first]);

	// �g�b�v
	plate[second] = Field::Create("plateSetthing");
	basePos[second] = { 0.0f, 0.0f, radius + diameter};
	plate[second]->SetPosition(basePos[second]);

	// �ړ��Ώۃv���[�g�Ɉ�ԃv���[�g�̔z��ԍ�����
	next = first;
	// �őO��v���[�g��2�v���[�g�̔z��ԍ�����
	top = second;
}

void Scroll::Update(XMFLOAT3 playerPos)
{
	// �Z�J���h�v���[�g�̒��S���W��ʉ߂����ꍇ
	if (basePos[top].z <= playerPos.z)
	{
		// �t�@�[�X�g�v���[�g���őO��ɔz�u
		basePos[next] = { 0.0f, 0.0f, basePos[top].z + diameter };
		plate[next]->SetPosition(basePos[next]);
		// �őO��̔z��ԍ����ړ�����obj�̔ԍ��ɂ���
		top = next;
		// ���̈ړ��Ώ�obj�ɃJ�E���g��i�߂�
		next++;
		// �z��̍ő�l�ɂȂ����ꍇ
		if (next == MAX_PLATE)
		{
			next = first;
		}
	}

	for (int i = 0; i < MAX_PLATE; i++)
	{
		plate[i]->Update();
	}
}

void Scroll::Draw()
{
	for (int i = 0; i < MAX_PLATE; i++)
	{
		plate[i]->Draw();
	}
}