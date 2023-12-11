#ifndef DEF_SCENEMGR_H
#define DEF_SCENEMGR_H

enum class eScene {
    eScene_Menu,
    eScene_Select,
    eScene_Answer,
    eScene_GameSelect,
    eScene_Game,
    eScene_Output,
    eScene_None,
};

void SceneMgr_Initialize();
void SceneMgr_Finalize();
void SceneMgr_Update();
void SceneMgr_Draw();

void SceneMgr_ChangeScene(eScene nextScene);

#endif