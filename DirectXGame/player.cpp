#include "player.h"
#include "ImGuiManager.h"


void Player::Initialize() {
	input_ = Input::GetInstance();
	//座標
	pos = {center.x - 8, center.y - 148};//円の中心を中央にするために8だけ少しずらしている

	#pragma region 画像

	playerTexture_ = TextureManager::Load("player/root.png");
	playerSprite_.reset(Sprite::Create(playerTexture_, pos));

	#pragma endregion
}

void Player::Update() {
	#pragma region プレイヤーの左右移動

	if (input_->PushKey(DIK_A)) {
		pos.x -= speed;
	} else if (input_->PushKey(DIK_D)) {
		pos.x += speed;
	}

	#pragma endregion

	//画像の座標更新
	playerSprite_->SetPosition(pos);

	ImGui::Begin("player");
	ImGui::Text("X:%f Y:%f", pos.x, pos.y);
	ImGui::End();


}

void Player::Draw() {
	playerSprite_->Draw(); 
}