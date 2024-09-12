#include "player.h"
#include "ImGuiManager.h"

void Player::Initialize() {
	input_ = Input::GetInstance();
	//座標
	pos = {center.x - 8 , 0 - 8};//円の中心を中央にするために8だけ少しずらしている
	localPos = pos;

	#pragma region 初期化

	kScroll = 220.0f;

	#pragma endregion

	#pragma region 画像

	//画像の読み込み
	playerTexture_ = TextureManager::Load("player/root.png");
	// 画像の読み込み
	testCircleTexture_ = TextureManager::Load("EN.png");


	//生成
	for (int j = 0; j < MAX_IMAGE; j++) {
		sprite_[j].reset(Sprite::Create(playerTexture_, pos));
		//sprite_[j]->SetAnchorPoint({0.8f, 0.8f});
	}
	TestCircleSprite_->Sprite::Create(testCircleTexture_, pos);

	#pragma endregion

	scrollStart = false;
}

void Player::Update() {
	#pragma region プレイヤーの移動

	if (input_->PushKey(DIK_A)) {
		pos.x -= speed;
	} else if (input_->PushKey(DIK_D)) {
		pos.x += speed;
	}
	
	//画面外のループ関数

	Clamp();

	//ローカルと値を合わせる
	localPos.x = pos.x;

	//自動で下に進める
	pos.y += downSpeed;

	#pragma endregion


	//スクロール関数を呼ぶ
	Scroll();


	//画像の座標更新
	Animation();

	/*ImGui::Begin("player");
	ImGui::Text("X:%f Y:%f", pos.x, pos.y);
	ImGui::End();*/

}

void Player::Draw() {
	for (int j = 0; j < MAX_IMAGE ; j++) {
		sprite_[j]->Draw();
	}
	
}

void Player::Animation() {

	flame--;

	if (flame < 0) {
		flame = MAX_IMAGE - 1;
	}
	if (isEnd == false) {
		for (int j = 0; j < MAX_IMAGE; j++) {
			if (pos.y >= kScroll) {
				//画像の座標を速度の数値分ずらす
				Vector2 p = sprite_[j]->GetPosition();
				p.y -= downSpeed; 
				sprite_[j]->SetPosition(p);
			}
		}
	} else {
		for (int j = 0; j < MAX_IMAGE; j++) {
			if (pos.y >= kScroll) {
				// 画像の座標を速度の数値分ずらす
				Vector2 p = sprite_[j]->GetPosition();
				p.y += downSpeed;
				sprite_[j]->SetPosition(p);
			}
		}
	}
	//ずらした座標をセット！
	sprite_[flame]->SetPosition(localPos);
}

void Player::Clamp() {
	if (pos.x <= 10) {
		pos.x = 10;
	} else if (pos.x >= 435) {
		pos.x = 435;
	}
}

void Player::Scroll() {

	if (pos.y >= kScroll) {
		scrollStart = true;
		scrollY = pos.y - kScroll;
	}


	//ローカルの座標更新
	localPos.y = pos.y - scrollY;
	

	/*ImGui::Begin("scroll");
	ImGui::Text("%f,%f", localPos.x, localPos.y);
	ImGui::End();*/
}

