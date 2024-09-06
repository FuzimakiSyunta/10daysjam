#include "stage.h"

void Stage::Initialize() {
	// 座標
	pos = {0, 0};

#pragma region 画像

	startStageTexture_ = TextureManager::Load("stage/stagestart.png");
	startStageSprite_.reset(Sprite::Create(startStageTexture_, pos));

#pragma endregion
}

void Stage::Update() {

}

void Stage::Draw() {
	startStageSprite_->Draw();
}