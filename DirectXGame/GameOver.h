#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "TextureManager.h"
#include "Input.h"
class GameOver {
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

private:
	Input* input_ = nullptr;
	Sprite* gameOverSprite_ = nullptr;
};
