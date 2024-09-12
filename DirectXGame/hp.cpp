#include "Hp.h"
void Hp::Initialize() { 
	uint32_t textureHp = TextureManager::Load("player/Hp.png "); 
	hpSprite = Sprite::Create(textureHp, {40.0f, 50.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});
}

void Hp::Update() { 
	if (playerHp >= 0) {
		playerHp -= hpSpeed;
	}
	hpSprite->SetSize({playerHp, 50.0f});
}

void Hp::Draw() { 
	hpSprite->Draw(); 
}