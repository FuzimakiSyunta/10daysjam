#include "ui.h"

void UI::Initialize() {
	scoreTexture = TextureManager::Load("score/num.png");

	for (int i = 0; i < 4; i++) {
		scoreSprite[i].reset(Sprite::Create(scoreTexture, {240.0f + i * 48, 100}));
	}


}

void UI::Update(Vector2 pos) {
	
	#pragma region スコア更新

	int eachNumber[4] = {};
	int number = (int)pos.y / 10;

	int keta = 1000;
	for (int i = 0; i < 4; i++) {
		eachNumber[i] = number / keta;
		number = number % keta;
		keta = keta / 10;
	}
	for (int i = 0; i < 4; i++) {
		scoreSprite[i]->SetSize({64, 128});
		scoreSprite[i]->SetTextureRect({64.0f * eachNumber[i], 0}, {64, 128});
	}

	#pragma endregion

}

void UI::Draw() {
	for (int i = 0; i < 4; i++) {
		scoreSprite[i]->Draw();
	}
}
