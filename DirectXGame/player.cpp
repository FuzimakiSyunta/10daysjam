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

	for (int j = 0; j < 30; j++) {
		texture_[j] = TextureManager::Load("player/root.png");
		sprite_[j].reset(Sprite::Create(texture_[j], pos));
	}

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
	//自動で下に進める
	pos.y += downSpeed;

	//スクロール関数を呼ぶ
	Scroll();
	//座標保存関数を呼ぶ
	//SavePos();

	//画像の座標更新
	playerSprite_->SetPosition(localPos);
	Animation();

	ImGui::Begin("player");
	ImGui::Text("X:%f Y:%f", pos.x, pos.y);
	ImGui::Text("X:%f", scrollY);
	ImGui::End();


}

void Player::Animation() {

	flame++;

	if (flame >= 30) {
		flame = 0;
	}

	sprite_[flame]->SetPosition(Subtract(pos,localPos));
}

void Player::Draw() {
	playerSprite_->Draw();
	for (int j = 0; j < 30; j++) {
		sprite_[j]->Draw();
	}
}

void Player::Scroll() {
	const float kScroll = 220.0f;
	if (pos.y >= kScroll) {
		scrollY = pos.y - kScroll;
	}
	//ローカルの座標更新
	localPos.y = pos.y - scrollY;
}

void Player::SavePos() {
	

	#pragma region

	i++;
	if (i >= 5) {
		count++;
		//bPos[count] = pos;
	}

	#pragma endregion

	ImGui::Begin("SavePos");
	ImGui::Text("count:%d i:%d", count,i);
	ImGui::Text("bPos[50] X:%f,Y:%f", bPos[30].x, bPos[30].y);
	ImGui::End();

}