#include "player.h"
#include "ImGuiManager.h"

void Player::Initialize() {
	input_ = Input::GetInstance();
	//座標
	pos = {center.x - 8 , 0 - 8};//円の中心を中央にするために8だけ少しずらしている
	localPos = pos;

	#pragma region 初期化

	isEnd = false;
	saveFlame = 0;

	reverseFlag = false;
	reverseFlame = 0;

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
	Loop();

	//ローカルと値を合わせる
	localPos.x = pos.x;

	//自動で下に進める
	pos.y += downSpeed;

	#pragma endregion


	//スクロール関数を呼ぶ
	Scroll();

	//座標保存関数を呼ぶ
	SavePos();
	Reverse();

	//画像の座標更新
	Animation();

	#pragma region デバッグ

		if (input_->PushKey(DIK_W)) {
			isEnd = true;
		}

	#pragma endregion

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

void Player::Loop() {
	if (pos.x <= -5) {
		pos.x = 470;
	} else if (pos.x >= 475) {
		pos.x = 0;
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

void Player::SavePos() {

	if (isEnd == false) {
		kScroll = 220;
		//毎フレームごとに配列に座標を保存
		saveFlame++;//タイマー
		savePos[saveFlame] = pos;
	} else {
		kScroll = 0;
		pos = savePos[saveFlame];
		saveFlame--;
		if (pos.y <= 0) {
			isEnd = false; // デバッグ用(初期に戻す)
		}
	}

}

void Player::Reverse() {
	
}
