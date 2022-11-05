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
	// ���f�����
	for (int i = 0; i < MAX_MODEL; i++)
	{
		delete model[i];
	}
	//�@�I�u�W�F�N�g���
	for (int i = 0; i < objects.size(); i++)
	{
		delete objects[i];
	}
}

void Enemy::Initialize()
{
	// ���f���ǂݍ���
	model[car] = Model::LoadFromOBJ("car");
	model[track] = Model::LoadFromOBJ("track");
	// ��������
	createTimer = 90;
	// ���݃t���b�O
	existenceFlag = false;
}

void Enemy::AutoSprint(int i)
{
	XMFLOAT3 pos = objects[i]->GetPosition();
	pos.z += speeds[i];
	objects[i]->SetPosition(pos);
}

int Enemy::RandValue(const int maxValue, const int miniValue)
{
	if (miniValue == 0)
	{
		return rand() % maxValue;
	}
	else
	{
		return (rand() % maxValue) + miniValue;
	}
}

DirectX::XMFLOAT3 Enemy::RandPos()
{
	int randFlag = rand() % 4;
	if (randFlag == 0)
	{
		return { -5.3f, 0.0f, player_Pos.z + 310.0f };
	}
	else if (randFlag == 1)
	{
		return { -1.8f, 0.0f, player_Pos.z + 310.0f };
	}
	else if (randFlag == 2)
	{
		return { 1.8f, 0.0f, player_Pos.z + 310.0f };
	}
	else
	{
		return { 5.3f, 0.0f, player_Pos.z + 310.0f };
	}
}

short Enemy::RandModel()
{
	modelFlag.push_back(rand() % MAX_MODEL);
	return modelFlag[objects.size()];
}

int Enemy::RandTimer()
{
	if (player_Speed > 0.0f && player_Speed <= 0.5f)
	{
		return (rand() % 10) + 80;
	}
	else if (player_Speed > 0.5f && player_Speed <= 1.0f)
	{
		return (rand() % 10) + 40;
	}
	else
	{
		return (rand() % 10) + 20;
	}
}

void Enemy::Update(const XMFLOAT3& playerPos, const float& playerSpeed)
{	
	// �v���C���[�̍��W���i�[
	player_Pos = playerPos;
	player_Speed = playerSpeed;

	// �^�C�}�[
	createTimer--;
	if (createTimer <= 0)
	{
		// 0.1 90  1.5 20
		// ��
		createTimer = RandTimer();
		// ��
		speeds.push_back(0.5f);
		objects.push_back(Object3d::Create(RandPos(), model[RandModel()]));

	}


	if (!objects.empty())
	{
		for (int i = 0; i < objects.size(); i++)
		{
			// �������s
			AutoSprint(i);
			//�@�v���C���[���G�l�~�[��ǂ��z������
			if (objects[i]->GetPosition().z < playerPos.z - 20.0f)
			{
				//�@�f�[�^�O���
				objects.erase(objects.begin() + i);
				speeds.erase(speeds.begin() + i);
				modelFlag.erase(modelFlag.begin() + i);
			}
			// �I�u�W�F�N�g�f�[�^�X�V
			objects[i]->Update();
		}
	}
}

void Enemy::Draw()
{
	if (!objects.empty())
	{
		for (int i = 0; i < objects.size(); i++)
		{
			// �I�u�W�F�N�g�f�[�^�X�V
			objects[i]->Draw();
		}
	}
}

const DirectX::XMFLOAT3& Enemy::GetPos(const int& number)
{
	// �f�[�^�������
	if (!objects.empty())
	{
		return objects[number]->GetPosition();
	}
	else
	{
		return { 0.0f, 0.0f, 0.0 };
	}
}

const bool& Enemy::GetModelFlag(const int& number)
{
	// �f�[�^�������
	if (!modelFlag.empty())
	{
		return modelFlag[number];
	}
	else
	{
		return false;
	}
}
