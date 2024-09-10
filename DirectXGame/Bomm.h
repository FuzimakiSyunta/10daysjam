#pragma once
#include <time.h>
#include <stdlib.h>
#include "Sprite.h"
#include <TextureManager.h>
#include "Input.h"

class Bomm {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update(float scroll_);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();


private:
	// ランダム変数
	int number = 0;
	// テクスチャハンドル
	uint32_t BomsTexture_ = 0;
	// スプライト
	Sprite* spriteBoms_ = nullptr;

	float scroll;

	std::unique_ptr<Sprite> bomsSprite_ = nullptr;
	// 地雷座標
	Vector2 pos;
	const Vector2 center = {240, 360};

};
