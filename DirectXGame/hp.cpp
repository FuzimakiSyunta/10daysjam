#include "Hp.h"
void Hp::Initialize() { 
	//HPバー
	uint32_t textureHp = TextureManager::Load("player/Hp.png "); 
	hpSprite = Sprite::Create(textureHp, {0.0f, 50.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});
	//Damege
	uint32_t textureDamege = TextureManager::Load("Damege.png ");
	DamegeSprite = Sprite::Create(textureDamege, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});

	playerHp = 400.0f;
	isDamege = false;
	DamegeCoolTime = 0;
	DamegeingTime = 0;
}

void Hp::Update() { 
	hpSprite->SetSize({playerHp, 50.0f});
	if (playerHp <= 0) {
		isResult = true;
	}
	DamegeCoolTime--;
	if (isDamege == true) {
		DamegeingTime++;
		if (DamegeingTime >= 5) {
			isDamege = false;
			DamegeingTime = 0;
		}
	}
}

void Hp::Damege() {
	
	if (DamegeCoolTime<=0) {
		playerHp = playerHp - 100.0f;
		isDamege = true;
		DamegeCoolTime = 30;
	}
	
}

void Hp::Draw() { 
	hpSprite->Draw(); 
	
}

void Hp::DamegeDraw() {
	if (isDamege == true) {
		DamegeSprite->Draw();
	}
}
