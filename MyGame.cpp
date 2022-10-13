#include "MyGame.h"

void MyGame::Initialize()
{
	//����&������
	winApp = new WinApp();
	winApp->Initialize();

	dxCommon = new DirectXCommon();
	dxCommon->initialize(winApp);

	input = new Input();
	input->Initialize(winApp);

	spriteCommon = new SpriteCommon();
	//�m�ۂ����X�v���C�g���ʕ����C���X�^���X��������
	spriteCommon->Initialize(dxCommon->Getdev(), dxCommon->GetCmdList(), WinApp::window_width, WinApp::window_height);


#pragma region �I�u�W�F�N�g
	//�J��������
	camera = new Camera(WinApp::window_width, WinApp::window_height);

	Object3d::StaticInitialize(dxCommon->Getdev());

	Object3d::SetCamera(camera);
	//OBJ���烂�f���f�[�^��ǂݍ���
	model = Model::LoadFromOBJ("player_N");
	//3D�I�u�W�F�N�g�̐���
	object3d = Object3d::Create();
	//�I�u�W�F�N�g�Ƀ��f�����Ђ��t����
	object3d->SetModel(model);

	camera->SetTarget({ 0.0f, 0.5f, 0.1f });
	camera->SetEye({ 0.0f, 4.0f, -10.0f });
#pragma endregion

#pragma region �X�v���C�g
	LoadSprite::StaticInitialize(spriteCommon);

	//�f�o�b�O�e�L�X�g����
	debugText = DebugText::Create(spriteCommon, debugTextTexNumber);
	debugText->Initialize(spriteCommon, debugTextTexNumber);

	//�X�v���C�g����
	sprite = Sprite::Create(spriteCommon, sample2, { 0.0f, 0.0f });
	sprite->SetSize({ 100.0f, 100.0f });

#pragma endregion
}

void MyGame::Finalize()
{
	//�N���X�̉��
	delete dxCommon;
	delete input;
	delete spriteCommon;
	delete sprite;
	delete object3d;
	delete model;
	delete debugText;
	delete camera;


#pragma region WindowsAPI��n��
	winApp->Finalize();
	delete winApp;
#pragma endregion WindowsAPI��n��
}

void MyGame::Updata()
{
#pragma region �E�B���h�E���b�Z�[�W����
	if (winApp->ProcessMessage()) {
		//�Q�[�����[�v���甲����
		endRequest = true;
		return;
	}
#pragma endregion �E�B���h�E���b�Z�[�W����

#pragma region DirectX���t���[������
	//DirectX���t���[�������@��������
	camera->MoveCamera(input, 0.5f);

	//�X�Vg
	object3d->Update();
	sprite->Updata();
	input->Updata();
	camera->Update();

	//DirectX���t���[�������@�����܂�
#pragma endregion DirectX���t���[������
}

void MyGame::Draw()
{
	dxCommon->PreDraw();
	//3D�I�u�W�F�N�g�`��O����
	Object3d::PreDraw(dxCommon->GetCmdList());

	//3D�I�u�W�F�N�g�`��
	object3d->Draw();

	//3D�I�u�W�F�N�g�㏈��
	Object3d::PostDraw();

	//�X�v���C�g���ʃR�}���h
	spriteCommon->PreDraw(dxCommon->GetCmdList());

	//sprite->Draw();
	//�f�o�b�O�e�L�X�g�`��
	/*XMFLOAT3 position = obj_Player->GetRotation();
	sprintf_s(strDebug, "%f  %f   %f", position.x, position.y, position.z);
	debugText->Print(strDebug, 0, 0, 2);
	debugText->DrawAll();*/

	spriteCommon->PostDraw();
	//�`��㏈��
	dxCommon->PostDraw();
}
