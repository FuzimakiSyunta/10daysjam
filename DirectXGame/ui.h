#pragma once
#include "Sprite.h"
#include "TextureManager.h"
#include "Vector2.h"
#include "Input.h"

class UI {

	public:

	void Initialize();

	void Update(Vector2 pos);

	void Draw();

	int GetScore() { return number; }

	private:


	#pragma region スコア描画用変数

	uint32_t scoreTexture = 0;
	std::unique_ptr<Sprite> scoreSprite[4] = {nullptr};

	uint32_t mTexture = 0;
	std::unique_ptr<Sprite> mSprite = nullptr;

	std::unique_ptr<Sprite> scoreSprite2[4] = {nullptr};
	
	int number = 0;

	#pragma endregion

};