#include "stage.h"
#include "ImGuiManager.h"

void Stage::Initialize() {

	// スタート地点の画像座標
	pos1 = {0, 0};
	pos2 = {0, 720};

#pragma region 画像の読み込み

	uint32_t startStageTexture_ = TextureManager::Load("stage/StageSoil.png");
	uint32_t startStageTexture2_ = TextureManager::Load("stage/StageSoil2.png");
	startStageSprite_[0] = Sprite::Create(startStageTexture_, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});
	startStageSprite_[1] = Sprite::Create(startStageTexture_, {0.0f, 720.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});
	startStageSprite2_[0] = Sprite::Create(startStageTexture2_, {0.0f, -720.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});
	startStageSprite2_[1] = Sprite::Create(startStageTexture2_, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});
#pragma endregion
}

void Stage::Update(float scroll) { 
	//スクロールの値の更新
	scrollY = scroll * -1;
	pos1.y -= 3.0f;
	pos2.y -= 3.0f;
	if (pos1.y <= -720) {
		pos1.y = 720;
	}
	if (pos2.y <= -720) {
		pos2.y = 720;
	}
}

void Stage::Stage1Update() {
	//レベル１の更新
	startStageSprite_[0]->SetPosition(pos1);
	startStageSprite_[1]->SetPosition(pos2);
	if (0<=posY1&&posY1 <= 7200) {
		posY1 += 3.0f;
	}
	if (posY1 > 7200) {
		isLevel1Clear = true;
	}
}

void Stage::Stage2Update() {
	// レベル２の更新
	startStageSprite2_[0]->SetPosition(pos1);
	startStageSprite2_[1]->SetPosition(pos2);
	if (0 <= posY2 && posY2 <= 7200) {
		posY2 += 3.0f;
	}
	if (posY2 > 7200) {
		isLevel2Clear = true;
	}
}

void Stage::Stage1Draw() {
	//スタート地点の描画
	startStageSprite_[0]->Draw();
	startStageSprite_[1]->Draw();
}

void Stage::Stage2Draw() {
	// スタート地点の描画
	startStageSprite2_[0]->Draw();
	startStageSprite2_[1]->Draw();
}

void Stage::StageReset() { 
	posY1 = 0;
	posY2 = 0;
	isLevel1Clear = false;
	isLevel2Clear = false;
	levelNo = StageLevel::kLevel1;
}