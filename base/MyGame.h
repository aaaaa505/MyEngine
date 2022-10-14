#pragma once
#include "FrameWork.h"

class MyGame : public FrameWork
{
public:
	/// <summary>
	/// ‰Šú‰»
	/// </summary>
	void Initialize() override;

	/// <summary>
	/// I—¹
	/// </summary>
	void Finalize() override;

	/// <summary>
	/// XV
	/// </summary>
	void Updata() override;

	/// <summary>
	/// •`‰æ
	/// </summary>
	void Draw() override;

};

