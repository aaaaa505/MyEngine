#include "MyGame.h"

void MyGame::Initialize()
{
	// ���N���X�̏�����
	FrameWork::Initialize();

#pragma region �I�u�W�F�N�g
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
	//�X�v���C�g����
	sprite = Sprite::Create(spriteCommon, sample2, { 0.0f, 0.0f });
	sprite->SetSize({ 100.0f, 100.0f });

#pragma endregion
}

void MyGame::Finalize()
{
	delete sprite;
	delete object3d;
	delete model;

	// ���N���X�̏I������
	FrameWork::Finalize();
}

void MyGame::Updata()
{
	// ���N���X�̍X�V����
	FrameWork::Updata();

#pragma region DirectX���t���[������
	//DirectX���t���[�������@��������
	camera->MoveCamera(input, 0.5f);

	//�X�V
	object3d->Update();
	sprite->Updata();
	//DirectX���t���[�������@�����܂�
#pragma endregion DirectX���t���[������
}

void MyGame::Draw()
{
	// �`��O����
	dxCommon->PreDraw();
	// 3D�I�u�W�F�N�g�`��O����
	Object3d::PreDraw(dxCommon->GetCmdList());

	// 3D�I�u�W�F�N�g�`��
	object3d->Draw();

	// 3D�I�u�W�F�N�g�㏈��
	Object3d::PostDraw();

	// �X�v���C�g�O����
	spriteCommon->PreDraw(dxCommon->GetCmdList());

	//sprite->Draw();
	//�f�o�b�O�e�L�X�g�`��
	/*XMFLOAT3 position = obj_Player->GetRotation();
	sprintf_s(strDebug, "%f  %f   %f", position.x, position.y, position.z);
	debugText->Print(strDebug, 0, 0, 2);
	debugText->DrawAll();*/

	// �X�v���C�g�㏈��
	spriteCommon->PostDraw();
	//�`��㏈��
	dxCommon->PostDraw();
}
