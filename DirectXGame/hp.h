#pragma once
#include "Sprite.h"
#include "TextureManager.h"
#include "Scene.h"
class Hp {
public:
	void Initialize();

	void Update();

	void Draw();

	void Damege();

	
	bool IsGameClear() { return isResult; }
	SceneType ClearScene() { return SceneType::kGameClear; }

private:
	//スプライト用変数
	Sprite* hpSprite;
	//HPを管理する変数
	float playerHp = 400.0f;

	bool isDamege;
	bool isResult = false;
};