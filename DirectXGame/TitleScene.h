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
	//タイトル画像の切り替えカウント用変数
	int spriteNo;
	int spriteCount;
};
