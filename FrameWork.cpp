#include "FrameWork.h"

void FrameWork::Initialize()
{
	// �ėp�N���X������
	winApp = new WinApp();
	winApp->Initialize();

	dxCommon = new DirectXCommon();
	dxCommon->initialize(winApp);

	input = new Input();
	input->Initialize(winApp);

	//�m�ۂ����X�v���C�g���ʕ����C���X�^���X��������
	spriteCommon = new SpriteCommon();
	spriteCommon->Initialize(dxCommon->Getdev(), dxCommon->GetCmdList(), WinApp::window_width, WinApp::window_height);

	// ���[�h�X�v���C�g�ÓI������
	LoadSprite::StaticInitialize(spriteCommon);

	//�f�o�b�O�e�L�X�g����
	debugText = DebugText::Create(spriteCommon, debugTextTexNumber);
	debugText->Initialize(spriteCommon, debugTextTexNumber);

	// �I�u�W�F�N�g3D�̐ÓI������
	Object3d::StaticInitialize(dxCommon->Getdev());

	//�J�����������Z�b�g
	camera = new Camera(WinApp::window_width, WinApp::window_height);
	Object3d::SetCamera(camera);

}

void FrameWork::Finalize()
{
	//�N���X�̉��
	delete dxCommon;
	delete input;
	delete spriteCommon;
	delete debugText;
	delete camera;
	winApp->Finalize();
	delete winApp;
}

void FrameWork::Updata()
{
	if (winApp->ProcessMessage()) {
		//�Q�[�����[�v���甲����
		endRequest = true;
		return;
	}

	input->Updata();
	camera->Update();
}

void FrameWork::Draw()
{
}
