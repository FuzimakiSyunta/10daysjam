#include "Audio.h"
#include "AxisIndicator.h"
#include "DirectXCommon.h"
#include "GameScene.h"
#include "ImGuiManager.h"
#include "PrimitiveDrawer.h"
#include "TextureManager.h"
#include "WinApp.h"
#include "TitleScene.h"
#include "GameClear.h"
#include "Scene.h"
#include "Hp.h"
#include "Audio.h"
#include "Player.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	WinApp* win = nullptr;
	DirectXCommon* dxCommon = nullptr;
	// 汎用機能
	Input* input = nullptr;
	Audio* audio = nullptr;
	AxisIndicator* axisIndicator = nullptr;
	PrimitiveDrawer* primitiveDrawer = nullptr;
	GameScene* gameScene = nullptr;
	TitleScene* titleScene = nullptr;
	GameClear* gameClearScene = nullptr;
	Stage* stage = nullptr;
	Hp* hp = nullptr;
	Audio* audio_ = nullptr;

	uint32_t BGM_ = 0;
	uint32_t Sound_ = 0;

	// ゲームウィンドウの作成
	win = WinApp::GetInstance();
	win->CreateGameWindow();

	// DirectX初期化処理
	dxCommon = DirectXCommon::GetInstance();
	dxCommon->Initialize(win);

#pragma region 汎用機能初期化
	// ImGuiの初期化
	ImGuiManager* imguiManager = ImGuiManager::GetInstance();
	imguiManager->Initialize(win, dxCommon);

	// 入力の初期化
	input = Input::GetInstance();
	input->Initialize();

	// オーディオの初期化
	audio = Audio::GetInstance();
	audio->Initialize();

	// テクスチャマネージャの初期化
	TextureManager::GetInstance()->Initialize(dxCommon->GetDevice());
	TextureManager::Load("white1x1.png");

	// スプライト静的初期化
	Sprite::StaticInitialize(dxCommon->GetDevice(), WinApp::kWindowWidth, WinApp::kWindowHeight);

	// 3Dモデル静的初期化
	Model::StaticInitialize();

	// 軸方向表示初期化
	axisIndicator = AxisIndicator::GetInstance();
	axisIndicator->Initialize();

	primitiveDrawer = PrimitiveDrawer::GetInstance();
	primitiveDrawer->Initialize();
#pragma endregion

	// ゲームシーンの初期化
	gameScene = new GameScene();
	gameScene->Initialize();

	//ステージの初期化
	stage = new Stage();
	stage->Initialize();

	//HPの初期化
	hp = new Hp();
	hp->Initialize();

	//タイトルシーンの初期化
	titleScene = new TitleScene();
	titleScene->Initialize();

	//クリアシーンの初期化
	gameClearScene = new GameClear();
	gameClearScene->Initialize();


	SceneType sceneNo = SceneType::kTitle;

	//BGM
	audio_ = Audio::GetInstance();
	BGM_ = audio_->LoadWave("BGM.wav");
	Sound_ = audio_->PlayWave(BGM_, true);


	// メインループ
	while (true) {
		// メッセージ処理
		if (win->ProcessMessage()) {
			break;
		}

		// ImGui受付開始
		imguiManager->Begin();
		// 入力関連の毎フレーム処理
		input->Update();
		switch (sceneNo) { 
		case SceneType::kTitle:
			titleScene->Update();
			stage->StageReset();
			gameScene->SceneReset();

			if (titleScene->IsSceneEnd()) {
				//ゲームシーンの初期化
				gameScene->Initialize();
				stage->StageReset();
				//タイトルシーンの初期化、フラグリセット等
				titleScene->sceneReset();
				//次のシーンの値を代入してシーン切り替え
				sceneNo = titleScene->NextScene();
			}
			break;
		case SceneType::kGamePlay:
			//ゲームシーンの毎フレーム処理
			gameScene->Update();
			gameClearScene->SceneReset();
			if (gameScene->IsGameClear() || hp->IsGameClear()) {
				// ゲームシーンの初期化、フラグリセット等
				gameScene->SceneReset();
				stage->StageReset();
				// 次のシーンの値を代入してシーン切り替え
				sceneNo = stage->ClearScene();
			}
			break;
		case SceneType::kGameClear:
			gameClearScene->Update();
			stage->StageReset();
			titleScene->sceneReset();
			if (gameClearScene->IsSceneEnd()) {
				stage->StageReset();
				//タイトルシーンの初期化
				gameClearScene->SceneReset();
				//次のシーンの値を代入してシーン切り替え
				sceneNo = gameClearScene->NextScene();
			}
		}
		// 軸表示の更新
		axisIndicator->Update();
		// ImGui受付終了
		imguiManager->End();

		// 描画開始
		dxCommon->PreDraw();

		switch (sceneNo) { 
		case SceneType::kTitle:
			titleScene->Draw();
			break;
		case SceneType::kGamePlay:
			gameScene->Draw();
			break;
		case SceneType::kGameClear:
			gameClearScene->Draw();
		}
		// 軸表示の描画
		axisIndicator->Draw();
		// プリミティブ描画のリセット
		primitiveDrawer->Reset();
		// ImGui描画
		imguiManager->Draw();
		// 描画終了
		dxCommon->PostDraw();
	}

	// 各種解放
	delete gameScene;
	// 3Dモデル解放
	Model::StaticFinalize();
	audio->Finalize();
	// ImGui解放
	imguiManager->Finalize();

	// ゲームウィンドウの破棄
	win->TerminateGameWindow();

	return 0;
}