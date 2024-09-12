#pragma once
#include "Sprite.h"
#include "TextureManager.h"
class Hp {
public:
	void Initialize();

	void Update();

	void Draw();

private:
	//スプライト用変数
	Sprite* hpSprite;
	//HPを管理する変数
	float playerHp = 400.0f;
	//HPが自然に減るスピード
	float hpSpeed = 0.2f;
};