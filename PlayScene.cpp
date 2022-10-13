#include "PlayScene.h"
#include "Input.h"
#include "DebugText.h"
#include "SpriteCommon.h"

void PlayScene::Initialize()
{
#pragma region �I�u�W�F�N�g
	// �J�����������Z�b�g
	camera = new Camera(WinApp::window_width, WinApp::window_height);
	Object3d::SetCamera(camera);


	// OBJ���烂�f���f�[�^��ǂݍ���
	model = Model::LoadFromOBJ("player_N");
	// 3D�I�u�W�F�N�g�̐���
	object3d = Object3d::Create();
	// �I�u�W�F�N�g�Ƀ��f�����Ђ��t����
	object3d->SetModel(model);

	camera->SetTarget({ 0.0f, 0.5f, 0.1f });
	camera->SetEye({ 0.0f, 4.0f, -10.0f });
#pragma endregion

#pragma region �X�v���C�g
	// �X�v���C�g����
	sprite = Sprite::Create(title_Number, { 0.0f, 0.0f });
#pragma endregion
}

void PlayScene::Finalize()
{
	// �J�������
	delete camera;
	// �X�v���C�g���
	delete sprite;
	// �I�u�W�F�N�g���
	delete object3d;
	// ���f�����
	delete model;
}

void PlayScene::Updata()
{
#pragma region DirectX���t���[������
	Input* input = Input::GetInstacne();

	//DirectX���t���[�������@��������
	camera->MoveCamera(input, 0.5f);

	//�X�V
	object3d->Update();
	sprite->Updata();
	camera->Update();
	//DirectX���t���[�������@�����܂�
#pragma endregion DirectX���t���[������
}

void PlayScene::Draw()
{
	// 3D�I�u�W�F�N�g�`��O����
	Object3d::PreDraw();

	// 3D�I�u�W�F�N�g�`��
	object3d->Draw();

	// �X�v���C�g�O����
	SpriteCommon::GetInstance()->PreDraw();

	sprite->Draw();
	//�f�o�b�O�e�L�X�g�`��
	sprintf_s(strDebug, "Test");
	DebugText::GetInstance()->Print(strDebug, 0, 0, 2);
	DebugText::GetInstance()->DrawAll();

}