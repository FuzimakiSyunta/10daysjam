#include "GameClear.h"

void GameClear::Initialize() { 
	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	uint32_t clearTexture = TextureManager::Load("Scene/GameClearScene.png ");
	clearSprite_ = Sprite::Create(clearTexture, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}, {0.0f, 0.0f});
	
	scoreTexture = TextureManager::Load("score/num.png");
	for (int i = 0; i < 4; i++) {
		scoreSprite[i].reset(Sprite::Create(scoreTexture, {45.0f + i * 90, 100}));
	}
}

void GameClear::Update() { 
	if (input_->TriggerKey(DIK_RETURN)) {
		isSceneEnd = true;
	}

	#pragma region スコア更新

	int eachNumber[4] = {};
	int number = gameScore_ / 10;

	int keta = 1000;
	for (int i = 0; i < 4; i++) {
		eachNumber[i] = number / keta;
		number = number % keta;
		keta = keta / 10;
	}
	for (int i = 0; i < 4; i++) {
		scoreSprite[i]->SetSize({128, 256});
		scoreSprite[i]->SetTextureRect({64.0f * eachNumber[i], 0}, {64, 128});
	}

#pragma endregion

}

void GameClear::Draw() { 
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

	clearSprite_->Draw(); 
	for (int i = 0; i < 4; i++) {
		scoreSprite[i]->Draw();
	}
	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}

void GameClear::SceneReset() { isSceneEnd = false; }
