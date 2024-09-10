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

	float GetScroll() { return scrollY; }


private:

	void Scroll();

private:
	//std::unique_ptr<Input> input_ = nullptr;
	Input* input_ = nullptr;
	//テクスチャハンドル
	uint32_t playerTexture_ = 0;
	//スプライト
	std::unique_ptr<Sprite> playerSprite_ = nullptr;

	#pragma region 座標関連

	Vector2 pos;
	Vector2 localPos;
	const float speed = 3.0f;
	const Vector2 center = {240, 360};
	float growSpeed = 3.0f;

	////デバック
	//const float speed = 0.0f;
	//float growSpeed = 0.0f;

	#pragma endregion

	//スクロールの値
	float scrollY = 0.0f;
};