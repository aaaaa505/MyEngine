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
	obj_Bike = Object3d::Create(model_Bike);
	// �����ʒu
	pos = { 0.0f, 0.0f, -100.0f };
	obj_Bike->SetPosition(pos);

	// ���f���ǂݍ���
	model_Dome = Model::LoadFromOBJ("skydome");
	// �I�u�W�F�N�g����
	obj_Dome = Object3d::Create(model_Dome);
	// �T�C�Y
	obj_Dome->SetScale({ 1.0f,	1.0f, 1.0f });

}

void Player::BesideMove()
{
	if (Input::GetInstacne()->PushKey(DIK_A))
	{
		pos.x -= 0.1f;
	}

	if (Input::GetInstacne()->PushKey(DIK_D))
	{
		pos.x += 0.1f;
	}
}

void Player::AutoSprint()
{
	pos.z += 0.5f;
	if (pos.z >= 0.0f)
	{
		pos.z = -90.0f;
	}
	obj_Bike->SetPosition(pos);
}

void Player::Update()
{
	// ���ړ�
	BesideMove();
	// �����ړ�
	AutoSprint();
	// �Ǐ]
	camera->SetEye({pos.x, pos.y + 3.0f, pos.z + 0.3f});
	camera->SetTarget({pos.x, pos.y + 3.0f, pos.z + 1.0f});
	//camera->SetEye({ pos.x, pos.y + 6.0f, pos.z - 10.0f });
	//camera->SetTarget({ pos.x, pos.y, pos.z });
	obj_Dome->SetPosition(pos);
	// �I�u�W�F�N�g�X�V
	obj_Bike->Update();
	// �J�����X�V
	camera->Update();
	obj_Dome->Update();
}

void Player::Draw()
{
	obj_Bike->Draw();
	obj_Dome->Draw();
}