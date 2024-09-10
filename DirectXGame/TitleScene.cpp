#include "TitleScene.h"

void TitleScene::Initialize() { 
	input_ = Input::GetInstance();
	//テクスチャ
	uint32_t textureTitle = TextureManager::Load("Scene/TitleScene.png "); 
	//スプライト生成
	spriteTitle_ = Sprite::Create(textureTitle, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});
}

void TitleScene::Update() {
	if (input_->TriggerKey(DIK_RETURN)) {
		isSceneEnd = true;
	}
}

void TitleScene::Draw() { 
	spriteTitle_->Draw(); 
}

void TitleScene::sceneReset() { 
	isSceneEnd = false; 
}
