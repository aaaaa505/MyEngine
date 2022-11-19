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

	// ドームモデル
	delete model_Dome;
	// ドームオブジェクト
	delete obj_Dome;
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
	// 初速度
	speed = { 0.0f, 0.0f, 0.1f };
	// モデル読み込み
	model_Dome = Model::LoadFromOBJ("skydome");
	// オブジェクト生成
	obj_Dome = Object3d::Create({0.0f, 0.0f, 0.0f}, model_Dome);

	//audio = Audio::GetInstance();
	//audio->LoadWave("bike.wav");
	//audio->SetVolume("bike.wav", volume);
}

void Player::BesideMove()
{
	// 左移動
	if (Input::GetInstacne()->PushKey(DIK_A) && rot.z <= MAX_ROT)
	{
		rot.z += MAX_ROTSPEED;
	}

	// 右移動
	if (Input::GetInstacne()->PushKey(DIK_D) && rot.z >= -MAX_ROT)
	{
		rot.z -= MAX_ROTSPEED;
	}

	// 回転角によるX軸のスピード変動
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
	if (!startFlag)
	{
		return 0.1f;
	}
	else
	{
		// 加速
		if (speed.z < MAX_SPEED)
		{
			if (Input::GetInstacne()->PushKey(DIK_W))
			{
				speed.z += ACC_POWER;
				volume += 0.001f;
			}
		}

		// 減速
		if (speed.z >= MINI_SPEED)
		{
			// 惰性走行
			if (Input::GetInstacne()->PushKey(DIK_W) == false && Input::GetInstacne()->PushKey(DIK_S) == false)
			{
				speed.z -= INE_POWER;
				volume -= INE_POWER;
			}
			// ブレーキ
			else if (Input::GetInstacne()->PushKey(DIK_S))
			{
				speed.z -= BRA_POWER;
				volume -= BRA_POWER;
			}
		}

		return speed.z;
	}
}

void Player::AutoSprint()
{
	// 座標に速度を加算
	pos.z += Fluctuation();
	// 更新した座標をセット
	obj_Bike->SetPosition(pos);
}

void Player::Update(bool startFlag)
{
	if (!hitFlag)
	{
		this->startFlag = startFlag;
		// 横移動
		BesideMove();

		// 自動移動
		AutoSprint();

		// カメラ追従
		camera->SetEye({ pos.x, pos.y + 1.7f, pos.z - 0.3f });
		camera->SetTarget({ pos.x, pos.y + 1.7f, pos.z + 1.0f });

		//audio->SetVolume("bike.wav",volume);
		//audio->PlayWave("bike.wav", true);

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
	else
	{
		//audio->StopWave("bike.wav");
	}

	
}

void Player::Draw()
{
	// バイク更新
	obj_Bike->Draw();
	// スカイドーム更新
	obj_Dome->Draw();
}