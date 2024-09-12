#pragma once
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "Scene.h"
#include "Sprite.h"
#include "TextureManager.h"

class TitleScene {
public:

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	void sceneReset();

	bool isSceneEnd = false;

	bool IsSceneEnd() { return isSceneEnd; }
	SceneType NextScene() { return SceneType::kGamePlay; }



private://メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	//スプライト
	Sprite* spriteTitle_[2];
	Sprite* stageSprite;
	//タイトル画像の切り替えカウント用変数
	int spriteCount = 0;
	//画像のy座標変更用の変数
	Vector2 spriteTitlePos = {0.0f, 0.0f};
	Vector2 stageSpritePos = {0.0f, 720.0f};
	bool titlePlay = false;
};
