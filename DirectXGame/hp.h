#pragma once
#include "Sprite.h"
#include "TextureManager.h"
#include "Scene.h"
class Hp {
public:
	void Initialize();

	void Update();

	void Draw();

	bool isGameClear = false;
	bool IsGameClear() { return isGameClear; }
	SceneType ClearScene() { return SceneType::kGameClear; }

private:
	//スプライト用変数
	Sprite* hpSprite;
	//HPを管理する変数
	float playerHp = 400.0f;
	//HPが自然に減るスピード
	float hpSpeed = 50.0f;
};