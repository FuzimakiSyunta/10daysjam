#pragma once
#include "Sprite.h"
#include "TextureManager.h"
#include "Scene.h"
class Hp {
public:
	void Initialize();

	void Update();

	void Draw();

	void DamegeDraw();

	void Damege();

	
	bool IsGameClear() { return isResult; }
	SceneType ClearScene() { return SceneType::kGameClear; }

private:
	//スプライト用変数
	Sprite* hpSprite;
	Sprite* DamegeSprite;
	//HPを管理する変数
	float playerHp = 400.0f;

	bool isDamege;
	float DamegeCoolTime;
	float DamegeingTime;
	bool isResult = false;
};