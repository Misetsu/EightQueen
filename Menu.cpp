#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"

void Menu_Initialize() {

}

void Menu_Update() {
    int posX, posY;

    GetMousePoint(&posX, &posY);

    if (290 < posX && posX < 590 && 750 < posY && posY < 900) {
        if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
            SceneMgr_ChangeScene(eScene::eScene_Select);
        }
    }
    if (690 < posX && posX < 990 && 750 < posY && posY < 900) {
        if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
            SceneMgr_ChangeScene(eScene::eScene_GameSelect);
        }
    }
    
}

void Menu_Draw() {
    int Background, White, Black, Exit;
    int posX, posY;

    White = GetColor(255, 255, 255);
    Black = GetColor(0, 0, 0);
    Background = LoadGraph("graphic/Eightqueen_Title.png");
    Exit = LoadGraph("graphic/Cross.png");

    DrawBox(0, 0, 1280, 1024, White, TRUE);
    DrawBox(10, 10, 1270, 1014, Black, FALSE);
    DrawExtendGraph(340, 100, 940, 700, Background, TRUE);
    DrawBox(290, 750, 590, 900, GetColor(232, 86, 86), TRUE);
    DrawBox(690, 750, 990, 900, GetColor(232, 86, 86), TRUE);
    DrawExtendGraph(1200, 30, 1250, 80, Exit, TRUE);

    GetMousePoint(&posX, &posY);

    if (290 < posX && posX < 590 && 750 < posY && posY < 900) {
        DrawString(315, 810, "ｎ女王の解を出力", White);
    }
    else {
        DrawString(335, 810, "アンサーモード", White);
    }
    
    if (690 < posX && posX < 990 && 750 < posY && posY < 900) {
        DrawString(720, 790, "駒の位置を選択し", White);
        DrawString(705, 830, "特定位置の解を出力", White);
    }
    else {
        DrawString(750, 810, "ゲームモード", White);
    }

}

void Menu_Finalize() {
}