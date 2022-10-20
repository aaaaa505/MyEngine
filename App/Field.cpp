#include "Field.h"

Field* Field::Create()
{
	// �C���X�^���X�̐���
	Field* instance = new Field();

	// �C���X�^���X�̏�����
	instance->Initialize();
	
	// �C���X�^���X��Ԃ�
	return instance;
}

Field::~Field()
{
	// �I�u�W�F�N�g���
	for (int i = 0; i < ROAD_MAX; i++)
	{
		delete obj[i];
	}
	// ���f�����
	delete model;
}

void Field::Initialize()
{
	// ���f���ǂݍ���
	model = Model::LoadFromOBJ("road");
	for (int i = 0; i < ROAD_MAX; i++)
	{
		// ����
		obj[i] = Object3d::Create();	
		// ���f���Z�b�g
		obj[i]->SetModel(model);
		// �������W�Z�b�g(3���p)
		obj[i]->SetPosition({ 0.0f, 0.1f, 20.0f + i * 40.0f });
	}
	
	// �����őO�z��ԍ����i�[
	top = 2;
}

void Field::Update(XMFLOAT3 pos)
{
	// ��̒��S���W��ʉ߂�����
	if (obj[next]->GetPosition().z + 40 <= pos.z)
	{
		// �ړ��Ώ�obj���őO��ɔz�u
		obj[next]->SetPosition({ 0.0f, 0.1f, obj[top]->GetPosition().z + 40.0f});
		// �őO��̔z��ԍ����ړ�����obj�̔ԍ��ɂ���
		top = next;
		// ���̈ړ��Ώ�obj�ɃJ�E���g��i�߂�
		next += 1;
		// �z��̍ő�l�ɂȂ����ꍇ
		if (next == ROAD_MAX)
		{
			next = 0;
		}
	}

	for (int i = 0; i < ROAD_MAX; i++)
	{
		// �X�V
		obj[i]->Update();
	}
}

void Field::Draw()
{
	for (int i = 0; i < ROAD_MAX; i++)
	{
		// �`��
		obj[i]->Draw();
	}
}
