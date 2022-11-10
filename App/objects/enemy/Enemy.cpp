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
	// �I�u�W�F�N�g���
	for (auto& object : objects)
	{
		delete object;
	}
	// �X�s�[�h�����
	speeds.clear();
	// ���f���t���b�O���
	modelFlags.clear();
}

void Enemy::Initialize()
{
	srand(time(NULL));
	// ���f���ǂݍ���
	model[car] = Model::LoadFromOBJ("car");
	model[track] = Model::LoadFromOBJ("track");
	// ��������
	for (int i = 0; i < MAX_TIMER; i++)
	{
		createTimer[i] = (rand() % RANDTIMER_MAX) + RANDTIMER_MINI;
	}
	// ���݃t���b�O
	existenceFlag = false;
}

void Enemy::AutoSprint(int number)
{
	XMFLOAT3 pos = objects[number]->GetPosition();
	pos.z += speeds[number];
	objects[number]->SetPosition(pos);
}

DirectX::XMFLOAT3 Enemy::RandPos(int number)
{
	if (number == left_Second)
	{
		return { -SIDELINE, 0.0f, player_Pos.z + BASEPOS };
	}
	else if (number == left_First)
	{
		return { -CENTERLINER, 0.0f, player_Pos.z + BASEPOS };
	}
	else if (number == right_First)
	{
		return { CENTERLINER, 0.0f, player_Pos.z + BASEPOS };
	}
	else
	{
		return { SIDELINE, 0.0f, player_Pos.z + BASEPOS };
	}
}

short Enemy::RandModel()
{
	modelFlags.push_back(rand() % MAX_MODEL);
	return modelFlags[objects.size()];
}

float Enemy::RandSpeed()
{
	int randFlag = rand() % MAX_SPEED;
	if (randFlag == First)
	{
		return BottonSpeed;
	}
	else if (randFlag == Second)
	{
		return MiddleSpeed;
	}
	else
	{
		return TopSpeed;
	}
	
}

void Enemy::Update(const XMFLOAT3& playerPos, const float& playerSpeed)
{	
	// �v���C���[�̍��W���i�[
	player_Pos = playerPos;
	player_Speed = playerSpeed;

	// �^�C�}�[
	for (int i = 0; i < MAX_TIMER; i++)
	{
		createTimer[i]--;
		if (createTimer[i] <= 0)
		{
			createTimer[i] = (rand() % RANDTIMER_MAX) + RANDTIMER_MINI;
			speeds.push_back(RandSpeed());
			objects.push_back(Object3d::Create(RandPos(i), model[RandModel()]));
		}
	}


	
	for (int i = 0; i < objects.size(); i++)
	{
		// �������s
		AutoSprint(i);
		//�@�v���C���[���G�l�~�[��ǂ��z������
		if (objects[i]->GetPosition().z < playerPos.z - 20.0f)
		{
			// �f�[�^�����
			objects.erase(objects.begin() + i);
			speeds.erase(speeds.begin() + i);
			modelFlags.erase(modelFlags.begin() + i);
			break;
		}
		// �I�u�W�F�N�g�f�[�^�X�V
		objects[i]->Update();
	}
}

void Enemy::Draw()
{
	
	for (int i = 0; i < objects.size(); i++)
	{
		// �I�u�W�F�N�g�f�[�^�X�V
		objects[i]->Draw();
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
	if (!modelFlags.empty())
	{
		return modelFlags[number];
	}
	else
	{
		return false;
	}
}
