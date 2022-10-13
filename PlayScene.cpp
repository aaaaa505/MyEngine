#include "PlayScene.h"
#include "TitleScene.h"
#include "Input.h"
#include "DebugText.h"
#include "SceneManager.h"

void PlayScene::Initialize()
{
#pragma region �I�u�W�F�N�g
	// �J�����������Z�b�g
	camera = new Camera(WinApp::window_width, WinApp::window_height);
	Object3d::SetCamera(camera);
	// �J�����ݒ�
	camera->SetTarget({ 0.0f, 0.5f, 0.1f });
	camera->SetEye({ 0.0f, 4.0f, -10.0f });
	// OBJ���烂�f���f�[�^��ǂݍ���
	model = Model::LoadFromOBJ("player_N");
	// 3D�I�u�W�F�N�g�̐���
	object3d = Object3d::Create();
	// �I�u�W�F�N�g�Ƀ��f�����Ђ��t����
	object3d->SetModel(model);
#pragma endregion
}

void PlayScene::Finalize()
{
	// �J�������
	delete camera;
	// �I�u�W�F�N�g���
	delete object3d;
	// ���f�����
	delete model;
}

void PlayScene::Updata()
{
	Input* input = Input::GetInstacne();
	if (input->Triggerkey(DIK_SPACE))
	{
		// �V�[���؂�ւ�
		SceneManager::GetInstance()->ChangeScene("TITLE");
	}

	camera->MoveCamera(input, 0.5f);

	//�X�V
	object3d->Update();
	camera->Update();
}

void PlayScene::Draw()
{
	// 3D�I�u�W�F�N�g�`��O����
	Object3d::PreDraw();

	// 3D�I�u�W�F�N�g�`��
	object3d->Draw();

	// �X�v���C�g�O����
	SpriteCommon::GetInstance()->PreDraw();
	//�f�o�b�O�e�L�X�g�`��
	DebugText::GetInstance()->Print("Test", 0, 0, 2);
	DebugText::GetInstance()->DrawAll();

}