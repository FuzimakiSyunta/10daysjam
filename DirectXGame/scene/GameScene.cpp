#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>

GameScene::GameScene() {}

GameScene::~GameScene() {}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();

	//プレイヤー
	player_ = std::make_unique<Player>();
	player_->Initialize();
	//ステージ
	stage_ = std::make_unique<Stage>();
	stage_->Initialize();
	// 地雷
	bomm_ = std::make_unique<Bomm>();
	bomm_->Initialize();
	//UI
	ui_ = std::make_unique<UI>();
	ui_->Initialize();
	//HP
	hp_ = std::make_unique<Hp>();
	hp_->Initialize();
}

void GameScene::Update() {
	player_->Update();
	hp_->Update();
	if (hp_->IsGameClear()) {
		isGameClear = true;
	}
	switch (levelNo) {
	case StageLevel::kLevel1:
		stage_->Stage1Update();
		if (stage_->IsLevel1Clear() == true) {
			levelNo = stage_->Level1Clear();
		}
		break;
	case StageLevel::kLevel2:
		stage_->Stage2Update();
		if (stage_->IsLevel2Clear() == true) {
			isGameClear = true;
		}
	}
	if (player_->StartScroll()==true) {
		bomm_->Update(player_->GetSpeed());
	}
	stage_->Update(player_->GetScroll());
	ui_->Update(player_->GetPos());

	bool result = bomm_->Collision(player_->GetLocalPos(),player_->GetPlayerRad());
	if (result==true) {
		hp_->Damege();
	}
}

void GameScene::Draw() {

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

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);


	switch (levelNo) {
	case StageLevel::kLevel1:
		stage_->Stage1Draw();
		break;
	case StageLevel::kLevel2:
		stage_->Stage2Draw();
		break;
	}
	
	bomm_->Draw();
	player_->Draw();
	ui_->Draw();
	hp_->Draw();
	hp_->DamegeDraw();
	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}

void GameScene::SceneReset() { 
	isGameClear = false;
	levelNo = StageLevel::kLevel1;
}

int GameScene::GetScore() { 
	number_ = (int)player_->GetPosY();
	return number_; }
