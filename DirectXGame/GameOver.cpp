#include "GameOver.h"

void GameOver::Initialize() { 
	input_ = Input::GetInstance();
	uint32_t gameOverTexture = TextureManager::Load("Scene/GameOverScene.png "); 
	gameOverSprite_ = Sprite::Create(gameOverTexture, {0, 0});
	gameOverSprite_ = Sprite::Create(gameOverTexture, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});
}

void GameOver::Update() {
	if (input_->TriggerKey(DIK_RETURN)) {
		isSceneEnd = true;
	}
}

void GameOver::Draw() { gameOverSprite_->Draw(); }

void GameOver::SceneReset() { 
	isSceneEnd = false; 
}
