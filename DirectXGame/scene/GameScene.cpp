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
}

void GameScene::Update() {
	player_->Update();
	if (player_->StartScroll()==true) {
		bomm_->Update(player_->GetSpeed());
	}
	stage_->Update(player_->GetScroll());
	ui_->Update(player_->GetPos());
	if (input_->TriggerKey(DIK_SPACE)) {
		isGameClear = true;
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

	//stage_->Draw();
	bomm_->Draw();
	player_->Draw();
	//bomm_->Draw();
	ui_->Draw();
	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}

void GameScene::SceneReset() { 
	isGameClear = false;
}

void GameScene::OnCollision() { 
	LeftTop.x = (player_->GetPlayerPos().x - player_->GetPlayerRad().x+player_->GetPlayerRad().y)/bomm_->MapSize();
	LeftTop.y = (player_->GetPlayerPos().y - player_->GetPlayerRad().x + player_->GetPlayerRad().y) / bomm_->MapSize();
	LeftBottom.x = (player_->GetPlayerPos().x - player_->GetPlayerRad().x + player_->GetPlayerRad().y) / bomm_->MapSize();
	LeftBottom.y = (player_->GetPlayerPos().x - player_->GetPlayerRad().x-1 + player_->GetPlayerRad().y-1) / bomm_->MapSize();
	RightTop.x = (player_->GetPlayerPos().x - player_->GetPlayerRad().x-1 + player_->GetPlayerRad().y-1) / bomm_->MapSize();
	RightTop.y = (player_->GetPlayerPos().x - player_->GetPlayerRad().x  + player_->GetPlayerRad().y) / bomm_->MapSize();
	RightBottom.x =(player_->GetPlayerPos().x - player_->GetPlayerRad().x-1 + player_->GetPlayerRad().y-1) / bomm_->MapSize();
	RightBottom.y = (player_->GetPlayerPos().x - player_->GetPlayerRad().x - 1 + player_->GetPlayerRad().y - 1) / bomm_->MapSize();
}
