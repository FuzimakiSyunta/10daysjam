#pragma once
#include <time.h>
#include <stdlib.h>
#include "Sprite.h"

class Bomm {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private:
	//ランダム変数
	int number = 0;
	// スプライト
	Sprite* spriteBoms_ = nullptr;

};
