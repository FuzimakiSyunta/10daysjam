#include "Bomm.h"
#include "ImGuiManager.h"
#include <TextureManager.h>

void Bomm::Initialize() {
	BomsTexture_ = TextureManager::Load("Landmine.png");
	
}

void Bomm::Update(float scroll_) {
	scroll = scroll_ * -1;
	
	

	
}

void Bomm::Draw() {
	for (int y = 0; y < MapCountX; y++) {
		for (int x = 0; x < MapCountX; x++) {
			if (map[y][x] == 0) {
				bomsSprite_->Draw();
			}
		}
	}
}