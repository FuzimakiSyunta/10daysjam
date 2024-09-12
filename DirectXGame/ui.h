#pragma once
#include "Sprite.h"
#include "TextureManager.h"
#include "Vector2.h"
#include "Input.h"
#include "player.h"

class UI {

	public:

	void Initialize();

	void Update(Vector2 pos);

	void Draw();

	private:

	uint32_t scoreTexture = 0;
	std::unique_ptr<Sprite> scoreSprite[4] = {nullptr};

	std::unique_ptr<Player> player_;

	#pragma region スコア描画用変数

	float pY = 0;

	#pragma endregion
};