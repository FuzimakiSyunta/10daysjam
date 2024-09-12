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

#include "StageLevel.h"

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

	//リセット用の関数
	void SceneReset();

	bool isGameClear = false;
	bool IsGameClear() { return isGameClear; }
	SceneType ClearScene() { return SceneType::kGameClear; }

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	std::unique_ptr<Player> player_;
	std::unique_ptr<Stage> stage_;
	std::unique_ptr<Bomm> bomm_;

	// ステージレベルの初期化
	StageLevel levelNo = StageLevel::kLevel1;
	std::unique_ptr<UI> ui_;
	/// <summary>
	/// ゲームシーン用
	/// </summary>
};
