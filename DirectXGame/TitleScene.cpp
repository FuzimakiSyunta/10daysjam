#include "TitleScene.h"

void TitleScene::Initialize() { 
	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	//テクスチャ
	uint32_t textureTitle1 = TextureManager::Load("Scene/TitleScene1.png "); 
	uint32_t textureTitle2 = TextureManager::Load("Scene/TitleScene2.png");
	uint32_t stageSoil = TextureManager::Load("Scene/StageSoil.png");
	//スプライト生成
	spriteTitle_[0] = Sprite::Create(textureTitle1, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});
	spriteTitle_[1] = Sprite::Create(textureTitle2, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});
	stageSprite = Sprite::Create(stageSoil, { 0.0f, 720.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});
}

void TitleScene::Update() {
	spriteCount++;
	if (spriteCount >= 30) {
		spriteCount = 0;
	}
	if (input_->TriggerKey(DIK_RETURN)) {
		titlePlay = true;
	}
	if (titlePlay == true) {
		stageSpritePos.y -= 3.0f;
		spriteTitlePos.y -= 3.0f;
	}

	spriteTitle_[0]->SetPosition(spriteTitlePos);
	spriteTitle_[1]->SetPosition(spriteTitlePos);
	stageSprite->SetPosition(stageSpritePos);

	if (spriteTitlePos.y <= -730) {
		isSceneEnd = true;
	}
}

void TitleScene::Draw() { 
	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	if (0 <= spriteCount && spriteCount <= 15) {
		spriteTitle_[0]->Draw();
	} else if (16 <= spriteCount && spriteCount <= 30) {
		spriteTitle_[1]->Draw();
	}
	stageSprite->Draw();

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}

void TitleScene::sceneReset() { 
	spriteCount = 0;
	isSceneEnd = false; 
}
