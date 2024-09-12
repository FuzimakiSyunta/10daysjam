#pragma once
#include "Sprite.h"
#include "TextureManager.h"
#include "Vector2.h"
#include "StageLevel.h"
#include "Scene.h"
#include "Player.h"

class Stage {
public:

	void Initialize();

	void Update(float scroll);

	void Stage1Draw();
	void Stage2Draw();
	void Stage3Draw();

	void Stage1Update();
	void Stage2Update();
	void Stage3Update();

	// 難易度移行用の変数、関数
	bool isLevel1Clear = false;
	bool isLevel2Clear = false;
	bool isLevel3Clear = false;
	bool IsLevel1Clear() { return isLevel1Clear; }
	bool IsLevel2Clear() { return isLevel2Clear; }
	bool IsLevel3Clear() { return isLevel3Clear; }
	StageLevel Level1Clear() { return StageLevel::kLevel2; }
	StageLevel Level2Clear() { return StageLevel::kLevel3; }
	//ゲームクリア用の関数
	bool isGameClear = false;
	bool IsGameClear() { return isGameClear; }
	SceneType ClearScene() { return SceneType::kGameClear; }

	//リセット用の関数
	void StageReset();


private:

	StageLevel levelNo = StageLevel::kLevel1;

	Vector2 pos1;
	Vector2 pos2;
	//プレイヤーの座標を入れる用の変数
	float posY;
	float scrollY;

	//開始時の画像
	Sprite* startStageSprite_[2];
	Sprite* startStageSprite2_[2];
	Sprite* startStageSprite3_[2];
	//uint32_t startStageTexture_1;
	//uint32_t startStageTexture_2;
	/*std::unique_ptr<Sprite> startStageSprite_[2];*/
	
};