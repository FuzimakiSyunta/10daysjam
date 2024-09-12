#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "Scene.h"
#include "player.h"
#include "stage.h"
#include "Bomm.h"
#include "ui.h"


/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

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

	//シーンのリセット
	void SceneReset();

	bool isGameClear = false;

	bool IsGameClear() { return isGameClear; }
	SceneType ClearScene() { return SceneType::kGameClear; }

	void OnCollision();

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	std::unique_ptr<Player> player_;
	std::unique_ptr<Stage> stage_;
	std::unique_ptr<Bomm> bomm_;
	std::unique_ptr<UI> ui_;
	/// <summary>
	/// ゲームシーン用
	/// </summary>
	 
	/// 当たり判定用
	Vector2 LeftTop = {0,0};
	Vector2 LeftBottom = {0, 0};
	Vector2 RightTop = {0,0};
	Vector2 RightBottom = {0,0};
	
};
