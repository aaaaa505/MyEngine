#include "Player.h"
#include "Input.h"

Player* Player::Create()
{
	// �C���X�^���X����
	Player* instance = new Player();
	// �C���X�^���X������
	instance->Initialize();

	return instance;
}

Player::~Player()
{
	// �J�������
	delete camera;
	// ���f�����
	delete model_Bike;
	// �I�u�W�F�N�g���
	delete obj_Bike;
}

void Player::Initialize()
{
	// �J�����������Z�b�g
	camera = new Camera(WinApp::window_width, WinApp::window_height);
	Object3d::SetCamera(camera);

	// ���f���ǂݍ���
	model_Bike = Model::LoadFromOBJ("bike", true);
	// �I�u�W�F�N�g����
	obj_Bike = Object3d::Create(pos, model_Bike);
	// �����x
	speed = { 0.0f, 0.0f, 0.1f };
	// ���f���ǂݍ���
	model_Dome = Model::LoadFromOBJ("skydome");
	// �I�u�W�F�N�g����
	obj_Dome = Object3d::Create({0.0f, 0.0f, 0.0f}, model_Dome);
}

void Player::BesideMove()
{
	// ���ړ�
	if (Input::GetInstacne()->PushKey(DIK_A) && rot.z <= MAX_ROT)
	{
		rot.z += MAX_ROTSPEED;
	}

	// �E�ړ�
	if (Input::GetInstacne()->PushKey(DIK_D) && rot.z >= -MAX_ROT)
	{
		rot.z -= MAX_ROTSPEED;
	}

	// ��]�p�ɂ��X���̃X�s�[�h�ϓ�
	if (rot.z <= PARTITION_ROT && rot.z >= -PARTITION_ROT)
	{
		speed.x = 0.0f;
	}
	if (rot.z > PARTITION_ROT)
	{
		speed.x -= speed.z / MITIGATIONVALUE;
	}
	if (rot.z < -PARTITION_ROT)
	{
		speed.x += speed.z / MITIGATIONVALUE;
	}

	pos.x += speed.x;
}

float Player::Fluctuation()
{
	// ����
	if (speed.z < MAX_SPEED)
	{
		if (Input::GetInstacne()->PushKey(DIK_W))
		{
			speed.z += ACC_POWER;
		}
	}

	// ����
	if (speed.z >= MINI_SPEED)
	{
		// �Đ����s
		if (Input::GetInstacne()->PushKey(DIK_W) == false && Input::GetInstacne()->PushKey(DIK_S) == false)
		{
			speed.z -= INE_POWER;
		}
		// �u���[�L
		else if (Input::GetInstacne()->PushKey(DIK_S))
		{
			speed.z -= BRA_POWER;
		}
	}

	return speed.z;
}

void Player::AutoSprint()
{
	// ���W�ɑ��x�����Z
	pos.z += Fluctuation();
	// �X�V�������W���Z�b�g
	obj_Bike->SetPosition(pos);
}

void Player::DebugMove()
{
	if (Input::GetInstacne()->PushMoveKey())
	{
		if (Input::GetInstacne()->PushKey(DIK_W))
		{
			pos.z += 0.1f;
		}

		if (Input::GetInstacne()->PushKey(DIK_A))
		{
			pos.x -= 0.1f;
		}

		if (Input::GetInstacne()->PushKey(DIK_S))
		{
			pos.z -= 0.1f;
		}

		if (Input::GetInstacne()->PushKey(DIK_D))
		{
			pos.x += 0.1f;
		}
	}
}

void Player::Update()
{
	// ���ړ�
	BesideMove();
	// �����ړ�
	AutoSprint();
	//DebugMove();
	// �J�����Ǐ]
	camera->SetEye({pos.x, pos.y + 1.7f, pos.z - 0.3f});
	camera->SetTarget({pos.x, pos.y + 1.7f, pos.z + 1.0f});

	// �J�����X�V
	camera->Update();

	// ��]�𔽉f
	obj_Bike->SetRotation(rot);
	// ���W�𔽉f
	obj_Bike->SetPosition(pos);
	// �o�C�N�X�V
	obj_Bike->Update();

	// ���W���f
	obj_Dome->SetPosition({ pos.x, pos.y, pos.z + 150.0f });
	// �X�J�C�h�[���X�V
	obj_Dome->Update();
}

void Player::Draw()
{
	// �o�C�N�X�V
	obj_Bike->Draw();
	// �X�J�C�h�[���X�V
	obj_Dome->Draw();
}