#pragma once
#include "Sprite.h"
#include "TextureManager.h"
#include "Vector2.h"
#include "Input.h"
#include "compute.h"

#define MAX_IMAGE 240
class Player {
public:
	void Initialize();

	void Update();

	void Draw();

	float GetScroll() { return scrollY; }
	float GetSpeed() { return downSpeed; }

	bool StartScroll() { return scrollStart; }

	/*Vector2 GetPlayerPos() { return pos; };*/
	float GetPlayerRad() { return rad; };

	Vector2 GetPos() {return pos;}

	Vector2 GetLocalPos() { return localPos; }

	float GetPosY() { return pos.y; }

private:
	//スクロールをする関数
	void Scroll();
	//画像をアニメーションさせる
	void Animation();

	//クランプ
	void Clamp();


private:
	Input* input_ = nullptr;

	//死亡フラグ
	bool isEnd;

	#pragma region 画像読み込み

	//テクスチャハンドル
	uint32_t playerTexture_ = 0;
	//スプライト
	std::unique_ptr<Sprite> playerSprite_ = nullptr;

	// (範囲円)テクスチャハンドル
	uint32_t testCircleTexture_ = 0;
	// スプライト
	Sprite* TestCircleSprite_ = nullptr;

	uint32_t texture_[MAX_IMAGE] = {0};
	std::unique_ptr<Sprite> sprite_[MAX_IMAGE] = {nullptr};

	#pragma endregion

	#pragma region 座標関連

	Vector2 pos;
	Vector2 localPos;
	const float speed = 2.6f;
	const Vector2 center = {240, 360};
	float downSpeed = 4.0f;

	#pragma endregion

	//スクロールの値
	float scrollY = 0.0f;

	float kScroll;


	//アニメーション用変数
	int flame = MAX_IMAGE;


	//当たり判定
	float rad = 8;
	
	#pragma region 

	bool scrollStart;

	
	#pragma endregion

};