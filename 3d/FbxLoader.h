//#pragma once
//
//#include "fbxsdk.h"
//#include "FbxModel.h"
//#include <d3d12.h>
//#include <d3dx12.h>
//#include <string>
//
//class FbxLoader
//{
//private://エイリアス
//	using string = std::string;
//
//public://定数
//	//モデル格納ルートパス
//	static const string baseDirectory;
//	//テクスチャがない場合の標準テクスチャファイル名
//	static const string defaultTextureFileName;
//
//public:
//	/// <summary>
//	/// シングルトンインスタンスの取得
//	/// </summary>
//	/// <returns>インスタンス</returns>
//	static FbxLoader* GetInstance();
//
//	/// <summary>
//	/// 初期化
//	/// </summary>
//	/// <param name="device"></param>
//	void Initialize(ID3D12Device* device);
//
//	/// <summary>
//	/// 後始末
//	/// </summary>
//	void Finalize();
//
//	/// <summary>
//	/// ファイルからFBXモデル読み込み
//	/// </summary>
//	/// <param name="modelName"></param>
//	FbxModel* LoadModelFromFile(const string& modelName);
//
//	/// <summary>
//	/// FBXの行列をXMMatrixに変換
//	/// </summary>
//	/// <param name="dst"></param>
//	/// <param name="src"></param>
//	static void ConvertMatrixFromFbx(DirectX::XMMATRIX* dst, const FbxAMatrix& src);
//
//	
//private://メンバ変数
//	//D3D12デバイス
//	ID3D12Device* device = nullptr;
//	//FBXマネージャー
//	FbxManager* fbxManager = nullptr;
//	//FBXインポータ
//	FbxImporter* fbxImporter = nullptr;
//
//private:
//	// privateなコンストラクタ（シングルトンパターン）
//	FbxLoader() = default;
//	// privateなデストラクタ（シングルトンパターン）
//	~FbxLoader() = default;
//	// コピーコンストラクタを禁止（シングルトンパターン）
//	FbxLoader(const FbxLoader& obj) = delete;
//	// コピー代入演算子を禁止（シングルトンパターン）
//	void operator=(const FbxLoader& obj) = delete;
//	/// <summary>
//	/// 再帰的のノード構成を解析
//	/// </summary>
//	/// <param name="model"></param>
//	/// <param name="fbxNode"></param>
//	void ParseNodeRecursive(FbxModel* fbxmodel, FbxNode* fbxNode, Node* parent = nullptr);
//
//	/// <summary>
//	/// メッシュ読み取り
//	/// </summary>
//	/// <param name="fbxmodel"></param>
//	/// <param name="fbxNode"></param>
//	void ParseMesh(FbxModel* fbxmodel, FbxNode* fbxNode);
//
//	//頂点座標読み取り
//	void ParseMeshVertices(FbxModel* fbxmodel, FbxMesh* fbxMesh);
//	//面積情報読み取り
//	void ParseMeshFaces(FbxModel* fbxmodel, FbxMesh* fbxMesh);
//	//マテリアル読み込み
//	void ParseMaterial(FbxModel* fbxmodel, FbxNode* fbxNode);
//	//テクスチャ読み込み
//	void LoadTexture(FbxModel* fbxmodel, const std::string& fullpath);
//	//ディレクトリを含んだファイルパスからファイル名を抽出する
//	std::string ExtractFileName(const std::string& path);
//	//スキニング情報の読み取り
//	void ParseSkin(FbxModel* fbxmodel, FbxMesh* fbxMesh);
//};