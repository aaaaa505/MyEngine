#include "Field.h"
#include "LevelLoader.h"

Field* Field::Create(const std::string& fileName)
{
    // �C���X�^���X����
    Field* instance = new Field();

    // �C���X�^���X�̏�����
    instance->Initialize(fileName);

    // �C���X�^���X��Ԃ�
    return instance;
}

Field::~Field()
{
    // �f�[�^���
    for (Object3d*& object : objects)
    {
        delete(object);
    }
}

void Field::Initialize(const std::string& fileName)
{
	// ���x���f�[�^�̓ǂݍ���
	levelData = LevelLoader::LoadFile(fileName);

	for (auto& objectData : levelData->objects)
	{
		// ���f�����w�肵��3D�I�u�W�F�N�g�𐶐�
		Object3d* newObject = Object3d::Create(objectData.model);
		// ���W
		DirectX::XMFLOAT3 pos;
		// MATRIX��XMFLOAT3�֕ϊ�
		DirectX::XMStoreFloat3(&pos, objectData.translation);
		// �ϊ��������W�𔽉f
		newObject->SetPosition(pos);
		// �ϊ�����̍��W��z��ɓo�^
		basePos.push_back(pos);
		// �I�u�W�F�N�g�z��ɓo�^
		objects.push_back(newObject);
	}

}

void Field::Update()
{
	for (auto& object : objects)
	{
		object->Update();
	}
	
}

void Field::Draw()
{
	for (auto& object : objects)
	{
		object->Draw();
	}
	
}

void Field::SetPosition(const XMFLOAT3 movePos)
{
	// objects�̃f�[�^�T�C�Y����
	for (int i = 0 ; i < objects.size(); i++)
	{
		// �X�V�������W�Ɍ��̍��W�����Z����
		objects[i]->SetPosition({movePos.x + basePos[i].x, movePos.y + basePos[i].y, movePos.z + basePos[i].z });
	}
}
