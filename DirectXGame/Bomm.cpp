#include "Bomm.h"
#include <TextureManager.h>

void Bomm::Initialize() { 
	srand((unsigned int)time(nullptr));
	// テクスチャ
	uint32_t textureTitle = TextureManager::Load("Landmine.png");
	
}

void Bomm::Update() {
	//これだと1から6の間
	number = rand() % 6 + 1;
}

void Bomm::Draw() {
	
}
