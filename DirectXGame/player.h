#pragma once
#include "Sprite.h"
#include "TextureManager.h"
#include "Vector2.h"
#include "Input.h"

class Player {
public:
	void Initialize();

	void Update();

	void Draw();

private:
	//std::unique_ptr<Input> input_ = nullptr;
	Input* input_ = nullptr;
	//テクスチャハンドル
	uint32_t playerTexture_ = 0;
	//スプライト
	std::unique_ptr<Sprite> playerSprite_ = nullptr;

	//プレイヤー座標
	Vector2 pos;
	const float speed = 3.0f;
	const Vector2 center = {240, 360};
};