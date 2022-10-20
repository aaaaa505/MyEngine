#include "Enemy.h"
#include <stdlib.h>
#include <time.h>
#include "Input.h"

Enemy* Enemy::Create()
{
	// �C���X�^���X�̐���
	Enemy* instance = new Enemy();

	// �C���X�^���X�̏�����
	instance->Initialize();

	// �C���X�^���X��Ԃ�
	return instance;
}

Enemy::~Enemy()
{
	//�@�I�u�W�F�N�g���
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		delete obj[i];
	}
	// ���f�����
	delete model;
}

void Enemy::Initialize()
{
	// ��������
	srand(time(NULL));
	// ���f���ǂݍ���
	model = Model::LoadFromOBJ("enemy");
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		// ����
		obj[i] = Object3d::Create();
		// ���f���Z�b�g
		obj[i]->SetModel(model);
		// �X�P�[��
		obj[i]->SetScale({0.5f, 0.5f, 0.5f});
		// ���W
		pos[i] = {0.0f, 100.0f, 0.0f};
		// �����^�C�}�[�l
		settingTimer[i] = (rand() % 120) + 120;
		existenceFlag[i] = false;
	}
	// ���x
	speed = { 0.0f, 0.0f, 0.9f };
}

float Enemy::LaneSetthing()
{
	float x;
	randam = rand() % 4;
	if (randam == 0)
	{
		x = -4.0f;
	}
	else if (randam == 1)
	{
		x = -1.3f;
	}
	else if (randam == 2)
	{
		x = 1.3f;
	}
	else
	{
		x = 4.0f;
	}

	return x;
}

void Enemy::ReSetthing(XMFLOAT3 playerPos, int i)
{
	if (existenceFlag[i] == false)
	{
		settingTimer[i] -= 1;
	}

	if (settingTimer[i] <= 0)
	{
		pos[i] = {LaneSetthing() ,0.0f, playerPos.z + 50.0f};

		existenceFlag[i] = true;
		settingTimer[i] = (rand() % 120) + 120;
	}
}

void Enemy::AutoSprint(int i)
{
	pos[i].z += speed.z;
	obj[i]->SetPosition(pos[i]);
}

void Enemy::Update(XMFLOAT3 playerPos)
{	
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		// �Ĕz�u
		ReSetthing(playerPos, i);
		// �v���C���[�ɂʂ����ꂽ�ꍇ
		if (playerPos.z - 10.0f >= pos[i].z)
		{
			existenceFlag[i] = false;
			pos[i] = {0.0f, 100.0f, 0.0f};
		}

		if (existenceFlag[i])
		{
			AutoSprint(i);
			// �X�V
			obj[i]->Update();
		}
	}
}

void Enemy::Draw()
{
	for (int i = 0; i < MAX_ENEMY; i++)
	{
		if (existenceFlag[i])
		{
			// �`��
			obj[i]->Draw();
		}
	}
}
