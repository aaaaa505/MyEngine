#include "FrameWork.h"

void FrameWork::Initialize()
{
	// �ėp�N���X������
	winApp = new WinApp();
	winApp->Initialize();

	// DirectX��ՃN���X������
	dxCommon = new DirectXCommon();
	dxCommon->initialize(winApp);

	// ���̓N���X������
	input = Input::GetInstacne();
	input->Initialize(winApp);

	// �m�ۂ����X�v���C�g���ʕ����C���X�^���X��������
	spriteCommon = SpriteCommon::GetInstance();
	spriteCommon->Initialize(dxCommon->Getdev(), dxCommon->GetCmdList(), WinApp::window_width, WinApp::window_height);

	// ���[�h�X�v���C�g�ÓI������
	LoadSprite::StaticInitialize(spriteCommon);

	// �f�o�b�O�e�L�X�g����
	debugText = DebugText::GetInstance();
	debugText->Initialize(debugTextTexNumber);

	// �I�u�W�F�N�g3D�̐ÓI������
	Object3d::StaticInitialize(dxCommon->Getdev(), dxCommon->GetCmdList());
}

void FrameWork::Finalize()
{
	// �N���X�̉��
	delete dxCommon;
	debugText->Finalize();
	winApp->Finalize();
	delete winApp;
}

void FrameWork::Run()
{
	// �Q�[���̏�����
	Initialize();

	while (true)// �Q�[�����[�v
	{
		// ���t���[���X�V
		Updata();
		// �I�����N�G�X�g�������甲����
		if (endRequest)
		{
			break;
		}
		// �`��
		Draw();
	}

	// �I������
	Finalize();
}

void FrameWork::Updata()
{
	if (winApp->ProcessMessage()) {
		// �Q�[�����[�v���甲����
		endRequest = true;
		return;
	}

	input->Updata();
}

void FrameWork::Draw()
{
}
