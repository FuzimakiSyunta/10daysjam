#pragma once
#include "Sprite.h"
#include "TextureManager.h"
#include "Vector2.h"

class Stage {
public:

	void Initialize();

	void Update();

	void Draw();

private:

	Vector2 pos;

	//開始時の画像
	uint32_t startStageTexture_ = 0;
	std::unique_ptr<Sprite> startStageSprite_ = nullptr;
};