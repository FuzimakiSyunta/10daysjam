#include "TitleScene.h"

void TitleScene::Initialize() { 
	//テクスチャ
	uint32_t textureTitle = TextureManager::Load("TitleScene/TitleScene.png "); 
	//スプライト生成
	spriteTitle_ = Sprite::Create(textureTitle, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});
}

void TitleScene::Draw() { spriteTitle_->Draw(); }
