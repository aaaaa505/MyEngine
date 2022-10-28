#include "Field.h"
#include "LevelLoader.h"

Field* Field::Create(const std::string& fileName)
{
    // インスタンス生成
    Field* instance = new Field();

    // インスタンスの初期化
    instance->Initialize(fileName);

    // インスタンスを返す
    return instance;
}

Field::~Field()
{
    // データ解放
    for (Object3d*& object : objects)
    {
        delete(object);
    }
}

void Field::Initialize(const std::string& fileName)
{
	// レベルデータの読み込み
	levelData = LevelLoader::LoadFile(fileName);

	for (auto& objectData : levelData->objects)
	{
		// モデルを指定して3Dオブジェクトを生成
		Object3d* newObject = Object3d::Create(objectData.model);
		// 座標
		DirectX::XMFLOAT3 pos;
		// MATRIXをXMFLOAT3へ変換
		DirectX::XMStoreFloat3(&pos, objectData.translation);
		// 変換した座標を反映
		newObject->SetPosition(pos);
		// 変換直後の座標を配列に登録
		basePos.push_back(pos);
		// オブジェクト配列に登録
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
	// objectsのデータサイズ分回す
	for (int i = 0 ; i < objects.size(); i++)
	{
		// 更新した座標に元の座標を加算する
		objects[i]->SetPosition({movePos.x + basePos[i].x, movePos.y + basePos[i].y, movePos.z + basePos[i].z });
	}
}
