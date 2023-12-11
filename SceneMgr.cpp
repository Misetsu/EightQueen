#include "DxLib.h"
#include "SceneMgr.h"
#include "Menu.h"
#include "Select.h"
#include "Answer.h"
#include "GameSelect.h"
#include "Game.h"
#include "Output.h"
#include "EightQueen.h"

static eScene mScene = eScene::eScene_Menu;
static eScene mNextScene = eScene::eScene_None;
static void SceneMgr_InitializeModule(eScene scene);
static void SceneMgr_FinalizeModule(eScene scene);

void SceneMgr_Initialize() {
    SceneMgr_InitializeModule(mScene);
}

void SceneMgr_Update() {
    if (mNextScene != eScene::eScene_None) {
        SceneMgr_FinalizeModule(mScene);
        mScene = mNextScene;
        mNextScene = eScene::eScene_None;
        SceneMgr_InitializeModule(mScene);
    }

    switch (mScene) {
    case eScene::eScene_Menu:
        Menu_Update();
        break;
    case eScene::eScene_Select:
        Select_Update();
        break;
    case eScene::eScene_Answer:
        Answer_Update();
        break;
    case eScene::eScene_GameSelect:
        GameSelect_Update();
        break;
    case eScene::eScene_Game:
        Game_Update();
        break;
    case eScene::eScene_Output:
        Output_Update();
        break;
    default:
        break;
    }
}

void SceneMgr_Draw() {
    switch (mScene) {
    case eScene::eScene_Menu:
        Menu_Draw();
        break;
    case eScene::eScene_Select:
        Select_Draw();
        break;
    case eScene::eScene_Answer:
        Answer_Draw();
        break;
    case eScene::eScene_GameSelect:
        GameSelect_Draw();
        break;
    case eScene::eScene_Game:
        Game_Draw();
        break;
    case eScene::eScene_Output:
        Output_Draw();
        break;
    default:
        break;
    }
}

void SceneMgr_ChangeScene(eScene NextScene) {
    mNextScene = NextScene;
}

void SceneMgr_Finalize() {
    SceneMgr_FinalizeModule(mScene);
}

static void SceneMgr_InitializeModule(eScene scene) {
    switch (scene) {
    case eScene::eScene_Menu:
        Menu_Initialize();
        break;
    case eScene::eScene_Select:
        Select_Initialize();
        break;
    case eScene::eScene_Answer:
        Answer_Initialize();
        break;
    case eScene::eScene_GameSelect:
        GameSelect_Initialize();
        break;
    case eScene::eScene_Game:
        Game_Initialize();
        break;
    case eScene::eScene_Output:
        Output_Initialize();
        break;
    }
}

static void SceneMgr_FinalizeModule(eScene scene) {
    switch (scene) {
    case eScene::eScene_Menu:
        Menu_Finalize();
        break;
    case eScene::eScene_Select:
        Select_Finalize();
        break;
    case eScene::eScene_Answer:
        Answer_Finalize();
        break;
    case eScene::eScene_GameSelect:
        GameSelect_Finalize();
        break;
    case eScene::eScene_Game:
        Game_Finalize();
        break;
    case eScene::eScene_Output:
        Output_Finalize();
        break;
    }
}