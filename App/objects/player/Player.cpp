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
	obj_Bike = Object3d::Create(pos, model_Bike);
	// 初期回転
	rot = { 0.0f, 0.0f, 0.0f };
	// スケール
	obj_Bike->SetScale({ 0.5f, 0.5f, 0.5f });
	// 初速度
	speed = { 0.1f, 0.0f, 0.1f };
	// モデル読み込み
	model_Dome = Model::LoadFromOBJ("skydome");
	// オブジェクト生成
	obj_Dome = Object3d::Create({0.0f, 0.0f, 0.0f}, model_Dome);
}

void Player::BesideMove()
{
	// パッド操作
	if (Input::GetInstacne()->CheckPad())
	{
		// 左移動
		if (Input::GetInstacne()->TiltLeftStick(StickLeft))
		{
			rot.z += 0.1f;
			pos.x -= rot.z / 15.0f;
		}
		// 右移動
		else if (Input::GetInstacne()->TiltLeftStick(StickRight))
		{
			rot.z -= 0.1f;
			pos.x -= rot.z / 15.0f;
		}
		// キーを離した時
		else
		{
			rot.z = 0.0f;
		}
	}
	// キーボード操作
	else
	{
		// 左移動
		if (Input::GetInstacne()->PushKey(DIK_A))
		{
			rot.z += 0.1f;
			pos.x -= rot.z / 15.0f;
		}

		// 右移動
		if (Input::GetInstacne()->PushKey(DIK_D))
		{
			rot.z -= 0.1f;
			pos.x -= rot.z / 15.0f;
		}

		// キーを離した時
		if (Input::GetInstacne()->AwayKey(DIK_A) || Input::GetInstacne()->AwayKey(DIK_D))
		{
			rot.z = 0.0f;
		}
	}

}

float Player::Fluctuation()
{
	// 加速
	if (speed.z <= 1.5f)
	{
		if (Input::GetInstacne()->TiltRightStick(StickUp) ||
			Input::GetInstacne()->PushKey(DIK_W))
		{
			speed.z += 0.01f;
		}
	}

	// 規定値より上なら
	if (speed.z >= 0.12f)
	{
		// 惰性走行
		if (Input::GetInstacne()->TiltLeftStick(StickUp) == false ||
			Input::GetInstacne()->PushKey(DIK_W) == false)
		{
			speed.z -= 0.005f;
		}
		// ブレーキ
		if (Input::GetInstacne()->TiltRightStick(StickDown) ||
			Input::GetInstacne()->PushKey(DIK_S))
		{
			speed.z -= 0.01f;
		}
	}

	return speed.z;
}

void Player::AutoSprint()
{
	// 座標に速度を加算
	pos.z += Fluctuation();
	// 更新した座標をセット
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
	// 横移動
	BesideMove();
	// 自動移動
	AutoSprint();
	//DebugMove();
	// カメラ追従
	camera->SetEye({pos.x, pos.y + 1.7f, pos.z - 0.3f});
	camera->SetTarget({pos.x, pos.y + 1.7f, pos.z + 1.0f});

	// カメラ更新
	camera->Update();

	// 回転を反映
	obj_Bike->SetRotation(rot);
	// 座標を反映
	obj_Bike->SetPosition(pos);
	// バイク更新
	obj_Bike->Update();

	// 座標反映
	obj_Dome->SetPosition({ pos.x, pos.y, pos.z + 150.0f });
	// スカイドーム更新
	obj_Dome->Update();
}

void Player::Draw()
{
	// バイク更新
	obj_Bike->Draw();
	// スカイドーム更新
	obj_Dome->Draw();
}