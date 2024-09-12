#include "Bomm.h"
#include "ImGuiManager.h"
#include <TextureManager.h>

void Bomm::Initialize() {
	BomsTexture_ = TextureManager::Load("Landmine.png");
	bomsSprite_ = Sprite::Create(BomsTexture_, {100,500});

}

void Bomm::Update() {
	
	

	
}

void Bomm::Draw() {
	for (int y = 0; y < MapCountY; y++) {
		for (int x = 0; x < MapCountX; x++) {
			if (map[y][x] == 1) {
				pos.x = pos.x * blockSize;
				pos.y = pos.y * blockSize;
				bomsSprite_->SetPosition(pos);
				bomsSprite_->Draw();
			}
		}
	}
}