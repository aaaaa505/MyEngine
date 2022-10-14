#include "Player.h"
#include "Input.h"

Player* Player::Create()
{
	// インスタンス生成
	Player* instance = new Player();
	// インスタンス初期化
	instance->Initialize();

	return instance;
}

Player::~Player()
{
	// カメラ解放
	delete camera;
	// モデル解放
	delete model;
	// オブジェクト解放
	delete obj;
}

void Player::Initialize()
{
	// カメラ生成＆セット
	camera = new Camera(WinApp::window_width, WinApp::window_height);
	Object3d::SetCamera(camera);
	camera->SetTarget({ 0.0f, 4.0f, 0.0f });
	camera->SetEye({ 0.0f, 4.0f, -2.8f });
	// モデル読み込み
	model = Model::LoadFromOBJ("bike");
	// オブジェクト生成
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
	// オブジェクト更新
	obj->Update();
	// カメラ更新
	camera->Update();
}

void Player::Draw()
{
	obj->Draw();
}