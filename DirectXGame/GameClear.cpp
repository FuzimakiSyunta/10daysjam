#include "GameClear.h"

void GameClear::Initialize() { 
	input_ = Input::GetInstance();
	uint32_t clearTexture = TextureManager::Load("Scene/GameClearScene.png ");
	clearSprite_ = Sprite::Create(clearTexture, {0, 0});
	clearSprite_ = Sprite::Create(clearTexture, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});
}

void GameClear::Update() { 
	if (input_->TriggerKey(DIK_RETURN)) {
		isSceneEnd = true;
	}
}

void GameClear::Draw() { clearSprite_->Draw(); }

void GameClear::SceneReset() { isSceneEnd = false; }
