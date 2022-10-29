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
	delete model_Car;
	//�@�I�u�W�F�N�g���
	for (int i = 0; i < objects.size(); i++)
	{
		delete objects[i];
	}
}

void Enemy::Initialize()
{
	// ���f���ǂݍ���
	model_Car = Model::LoadFromOBJ("car");
	model_Track = Model::LoadFromOBJ("track");
	// ��������
	createTimer = 180;
	// ���݃t���b�O
	existenceFlag = false;
}

void Enemy::Update(XMFLOAT3 playerPos)
{	
	// �^�C�}�[
	createTimer--;
	if (createTimer <= 0)
	{
		createTimer = 180;
		objects.push_back(Object3d::Create({-6.0f, 0.0f, playerPos.z + 900.0f}, model_Track));
	}


	if (!objects.empty())
	{
		for (int i = 0; i < objects.size(); i++)
		{
			//�@�v���C���[���G�l�~�[��ǂ��z������
			if (objects[i]->GetPosition().z < playerPos.z)
			{
				//�@�f�[�^�O���
				objects.erase(objects.begin());
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
