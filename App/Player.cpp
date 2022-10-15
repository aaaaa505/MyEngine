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
	delete model_Bike;
	// オブジェクト解放
	delete obj_Bike;
}

void Player::Initialize()
{
	// カメラ生成＆セット
	camera = new Camera(WinApp::window_width, WinApp::window_height);
	Object3d::SetCamera(camera);

	// モデル読み込み
	model_Bike = Model::LoadFromOBJ("bike", true);
	// オブジェクト生成
	obj_Bike = Object3d::Create(model_Bike);
	// 初期位置
	pos = { 0.0f, 0.0f, -100.0f };
	obj_Bike->SetPosition(pos);

	// モデル読み込み
	model_Dome = Model::LoadFromOBJ("skydome");
	// オブジェクト生成
	obj_Dome = Object3d::Create(model_Dome);
	// サイズ
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
	// 横移動
	BesideMove();
	// 自動移動
	AutoSprint();
	// 追従
	camera->SetEye({pos.x, pos.y + 3.0f, pos.z + 0.3f});
	camera->SetTarget({pos.x, pos.y + 3.0f, pos.z + 1.0f});
	//camera->SetEye({ pos.x, pos.y + 6.0f, pos.z - 10.0f });
	//camera->SetTarget({ pos.x, pos.y, pos.z });
	obj_Dome->SetPosition(pos);
	// オブジェクト更新
	obj_Bike->Update();
	// カメラ更新
	camera->Update();
	obj_Dome->Update();
}

void Player::Draw()
{
	obj_Bike->Draw();
	obj_Dome->Draw();
}