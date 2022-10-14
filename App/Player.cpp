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
	delete model;
	// �I�u�W�F�N�g���
	delete obj;
}

void Player::Initialize()
{
	// �J�����������Z�b�g
	camera = new Camera(WinApp::window_width, WinApp::window_height);
	Object3d::SetCamera(camera);
	camera->SetTarget({ 0.0f, 4.0f, 0.0f });
	camera->SetEye({ 0.0f, 4.0f, -2.8f });
	// ���f���ǂݍ���
	model = Model::LoadFromOBJ("bike");
	// �I�u�W�F�N�g����
	obj = Object3d::Create(model);
	obj->SetPosition({ 0.0f, 1.0f, 0.0f });
}


void Player::Update()
{
	if (Input::GetInstacne()->PushKey(DIK_LEFT))
	{
		XMFLOAT3 pos1 = obj->GetPosition();
		pos1.x += 0.1f;
		obj->SetPosition(pos1);
		const XMFLOAT3 pos2 = { +0.1f, 0.0f,0.0f };
		camera->MoveVector(pos2);
		
	}
	// �I�u�W�F�N�g�X�V
	obj->Update();
	// �J�����X�V
	camera->Update();
}

void Player::Draw()
{
	obj->Draw();
}