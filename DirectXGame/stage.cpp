#include "stage.h"

void Stage::Initialize() {
	// スタート地点の画像座標
	pos = {0, 0};

#pragma region 画像の読み込み

	startStageTexture_ = TextureManager::Load("stage/stagestart.png");
	startStageSprite_.reset(Sprite::Create(startStageTexture_, pos));

#pragma endregion
}

void Stage::Update(float scroll) { 
	//スクロールの値の更新
	scrollY = scroll * -1;
	pos.y = scrollY;

	//スタート地点の画像更新
	startStageSprite_->SetPosition(pos);
}

void Stage::Draw() {
	//スタート地点の描画
	startStageSprite_->Draw();
}