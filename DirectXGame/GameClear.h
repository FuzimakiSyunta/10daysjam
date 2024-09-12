#pragma once
#include "DirectXCommon.h"
#include "Scene.h"
#include "Sprite.h"
#include "TextureManager.h"
#include "Input.h"
class GameClear {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	void SceneReset();

	bool isSceneEnd = false;

	bool IsSceneEnd() { return isSceneEnd; }
	SceneType NextScene() { return SceneType::kTitle; }

	//セッター
	int SetScore(int gameScore) { return gameScore_ = gameScore; };

private:
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Sprite* clearSprite_ = nullptr;

	// スコア
	uint32_t scoreTexture = 0;
	std::unique_ptr<Sprite> scoreSprite[4] = {nullptr};
	int gameScore_ = 0;
};
