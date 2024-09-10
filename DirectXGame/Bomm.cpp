#include "Bomm.h"
#include "ImGuiManager.h"
#include <TextureManager.h>

void Bomm::Initialize() {
	srand((unsigned int)time(nullptr));
	// 座標
	pos = {center.x - 8, center.y - 160};

	BomsTexture_ = TextureManager::Load("Landmine.png");
	bomsSprite_.reset(Sprite::Create(BomsTexture_, pos));
}

void Bomm::Update(float scroll_) {
	scroll = scroll_ * -1;
	pos.y = scroll;
	// これだと1から6の間
	number = rand() % 6 + 1;
	// 画像の座標更新
	bomsSprite_->SetPosition(pos);
	////これだと1から6の間
	// number = rand() % 6 + 1;
}

void Bomm::Draw() {

	bomsSprite_->Draw(); 
}