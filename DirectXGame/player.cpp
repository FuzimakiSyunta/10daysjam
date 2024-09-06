#include "player.h"
#include "ImGuiManager.h"


void Player::Initialize() {
	input_ = Input::GetInstance();
	//座標
	pos = {center.x - 8, center.y - 258};//円の中心を中央にするために8だけ少しずらしている
	localPos = pos;

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

	//ローカルと値を合わせる
	localPos.x = pos.x;

	#pragma endregion

	pos.y += growSpeed;

	//スクロール
	Scroll();

	//画像の座標更新
	playerSprite_->SetPosition(localPos);

	ImGui::Begin("player");
	ImGui::Text("X:%f Y:%f", pos.x, pos.y);
	ImGui::Text("X:%f", scrollY);
	ImGui::End();


}

void Player::Draw() {
	playerSprite_->Draw(); 
}

void Player::Scroll() {
	const float kScroll = 220.0f;
	if (pos.y >= kScroll) {
		scrollY = pos.y - kScroll;
	}
	//ローカルの座標更新
	localPos.y = pos.y - scrollY;
}