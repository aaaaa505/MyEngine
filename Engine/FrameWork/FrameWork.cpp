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

	// �I�[�f�B�I�̏�����
	audio = Audio::GetInstance();
	if (!audio->Initialize())
	{
		assert(0);
	}

	// �m�ۂ����X�v���C�g���ʕ����C���X�^���X��������
	spriteCommon = SpriteCommon::GetInstance();
	spriteCommon->Initialize(dxCommon->Getdev(), dxCommon->GetCmdList(), WinApp::window_width, WinApp::window_height);

	// ���[�h�X�v���C�g�ÓI������
	LoadSprite::StaticInitialize(spriteCommon);

	// �f�o�b�O�e�L�X�g����
	debugText = DebugText::GetInstance();
	debugText->Initialize(debugTextTexNumber);

	// Draw�i���o�[����
	drawNumber = DrawNumber::GetInstance();
	drawNumber->Initialize(NumberNumber);

	// �I�u�W�F�N�g3D�̐ÓI������
	Object3d::StaticInitialize(dxCommon->Getdev(), dxCommon->GetCmdList());

}

void FrameWork::Finalize()
{
	// �V�[���t�@�N�g���[���
	delete sceneFactory;
	// DirectX��ՃN���X���
	delete dxCommon;
	// �f�o�b�O�e�L�X�g�̏I������
	debugText->Finalize();
	// DrawNumber�̏I������
	drawNumber->Finalize();
	// WindowsAPI�̏I������
	winApp->Finalize();
	// WindowsAPI�N���X���
	delete winApp;
}

void FrameWork::Run()
{
	// ������
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
	// Windows���b�Z�[�W�̏���
	if (winApp->ProcessMessage()) {
		// �Q�[�����[�v���甲����
		endRequest = true;
		return;
	}

	// ���͂̍X�V
	input->Updata();

	// �V�[���̍X�V
	SceneManager::GetInstance()->Updata();
}

void FrameWork::Draw()
{
	// �`��O����
	dxCommon->PreDraw();

	// �V�[���`��
	SceneManager::GetInstance()->Draw();

	// �f�o�b�O�e�L�X�g�`��
	debugText->DrawAll();

	//�`��㏈��
	dxCommon->PostDraw();
}
