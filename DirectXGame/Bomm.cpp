#include "Bomm.h"
#include "ImGuiManager.h"
#include <TextureManager.h>

void Bomm::Initialize() {
	BomsTexture_ = TextureManager::Load("Landmine.png");
	TransparentTexture_ = TextureManager::Load("Transparent.png");
	HealTexture_ = TextureManager::Load("Landmine.png");
	for (int y = 0; y < 112; y++) {
		for (int x = 0; x < 7; x++) {
			pos.x = (float)x * blockSize;
			pos.y = (float)y * blockSize;
			bomsSprite_[y][x] = Sprite::Create(TransparentTexture_,pos);
			if (map[y][x] == 1) {
				bomsSprite_[y][x]->SetTextureHandle(BomsTexture_);
			}
			if (map[y][x] == 2) {
				bomsSprite_[y][x]->SetTextureHandle(HealTexture_);
			}
		}
	}

	

}

void Bomm::Update(float speed) {

	for (int y = 0; y < MapCountY; y++) {
		for (int x = 0; x < MapCountX; x++) {
			Vector2 p = bomsSprite_[y][x]->GetPosition();
			p.y -= speed;//ここやばい
			bomsSprite_[y][x]->SetPosition(p);
		}
	}

	ImGui::Begin("scroll");
	ImGui::Text("X:%f", scrollY);
	ImGui::End();

}

void Bomm::Draw() {
	for (int y = 0; y < MapCountY; y++) {
		for (int x = 0; x < MapCountX; x++) {
			bomsSprite_[y][x]->Draw();

		}
	}
}