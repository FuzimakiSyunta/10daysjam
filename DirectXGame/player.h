#pragma once
#include "Sprite.h"
#include "TextureManager.h"
#include "Vector2.h"
#include "Input.h"

class Player {
public:
	void Initialize();

	void Update();

	void Draw();

	float GetScroll() { return scrollY; }

private:
	//スクロールをする関数
	void Scroll();

	//通った座標を保存しておく関数
	void SavePos();

	//画像をアニメーションさせる
	void Animation();

private:
	Input* input_ = nullptr;

	#pragma region 画像読み込み

	//テクスチャハンドル
	uint32_t playerTexture_ = 0;
	//スプライト
	std::unique_ptr<Sprite> playerSprite_ = nullptr;

	uint32_t texture_[30] = {0};
	std::unique_ptr<Sprite> sprite_[30] = {nullptr};

	#pragma endregion

	#pragma region 座標関連

	Vector2 pos;
	Vector2 localPos;
	const float speed = 3.0f;
	const Vector2 center = {240, 360};
	float downSpeed = 3.0f;

	#pragma endregion

	//スクロールの値
	float scrollY = 0.0f;

	#pragma region SavePosに使う変数

	// タイマー用変数
	int i = 0;
	// デバッグ用
	int count = 0;

	
	// 座標を保存しておく配列
	Vector2 bPos[100] = {};

	#pragma endregion

	//アニメーション用変数
	int flame = 0;

};