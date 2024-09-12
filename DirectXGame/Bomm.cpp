#include "Bomm.h"
#include <TextureManager.h>
#include "ImGuiManager.h"

void Bomm::Initialize() { 
	sizeY =(int) map.size();
	sizeX = (int)map[0].size();
	// テクスチャ
	BomsTexture_ = TextureManager::Load("Landmine.png");
	bomsSprite_.reset(Sprite::Create(BomsTexture_, pos[i]));
	
}

void Bomm::Update() {
	for (int y = 0; y < easymap.size(); y++) {
		// 列の描画
		for (int x = 0; x < nomalmap.size(); x++) {
			if (map[y][x] == NORMAL) {
			}
		}
	}
}
	

void Bomm::Draw() { 
	for (int i = 0; i  easymap; i++) {
	}
		bomsSprite_[]->Draw();
	
}


