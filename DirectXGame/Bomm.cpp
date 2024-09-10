#include "Bomm.h"
#include <TextureManager.h>
#include "ImGuiManager.h"

void Bomm::Initialize() { 
	
	// テクスチャ
	BomsTexture_ = TextureManager::Load("Landmine.png");
	bomsSprite_.reset(Sprite::Create(BomsTexture_, pos[i]));
	
}

void Bomm::Update() { 
	 
}
	

void Bomm::Draw() { 
	for (int i = 0; i  easymap; i++) {
	}
		bomsSprite_[]->Draw();
	
}


