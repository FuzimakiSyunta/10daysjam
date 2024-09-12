#include "Hp.h"
void Hp::Initialize() { 
	uint32_t textureHp = TextureManager::Load("player/Hp.png "); 
	hpSprite = Sprite::Create(textureHp, {40.0f, 50.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});
	playerHp = 90.0f;
}

void Hp::Update() { 
	hpSprite->SetSize({playerHp, 90.0f});
	if (playerHp <= 0) {
		isResult = true;
	}
}

void Hp::Damege() { playerHp = playerHp - 30.0f; }

void Hp::Draw() { 
	hpSprite->Draw(); 
}