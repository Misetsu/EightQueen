#include "GameSelect.h"
#include "SceneMgr.h"
#include "DxLib.h"

extern int Queen;
extern int cnt;

void GameSelect_Initialize() {

}

void GameSelect_Update() {
    int posX, posY;

    GetMousePoint(&posX, &posY);

    if (190 < posX && posX < 290 && 525 < posY && posY < 625) {
        while ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
            Queen = 4;
            cnt = 0;
            SceneMgr_ChangeScene(eScene::eScene_Game);
        }
    }
    else if (390 < posX && posX < 490 && 525 < posY && posY < 625) {
        while ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
            Queen = 5;
            cnt = 0;
            SceneMgr_ChangeScene(eScene::eScene_Game);
        }
    }
    else if (590 < posX && posX < 690 && 525 < posY && posY < 625) {
        while ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
            Queen = 6;
            cnt = 0;
            SceneMgr_ChangeScene(eScene::eScene_Game);
        }
    }
    else if (790 < posX && posX < 890 && 525 < posY && posY < 625) {
        while ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
            Queen = 7;
            cnt = 0;
            SceneMgr_ChangeScene(eScene::eScene_Game);
        }
    }
    else if (990 < posX && posX < 1090 && 525 < posY && posY < 625) {
        while ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
            Queen = 8;
            cnt = 0;
            SceneMgr_ChangeScene(eScene::eScene_Game);
        }
    }
}

void GameSelect_Draw() {
    int White, Black;
    int Btn4, Btn5, Btn6, Btn7, Btn8, Exit;

    White = GetColor(255, 255, 255);
    Black = GetColor(0, 0, 0);

    Exit = LoadGraph("graphic/Cross.png");

    Btn4 = LoadGraph("graphic/Button4.png");
    Btn5 = LoadGraph("graphic/Button5.png");
    Btn6 = LoadGraph("graphic/Button6.png");
    Btn7 = LoadGraph("graphic/Button7.png");
    Btn8 = LoadGraph("graphic/Button8.png");

    DrawBox(0, 0, 1280, 1024, White, TRUE);
    DrawBox(10, 10, 1270, 1014, Black, FALSE);
    DrawString(415, 375, "”Õ–Ê‚Ì‘å‚«‚³‚ð‘I‚ñ‚Å‚­‚¾‚³‚¢", Black);
    DrawExtendGraph(1200, 30, 1250, 80, Exit, TRUE);


    DrawExtendGraph(165, 500, 315, 650, Btn4, TRUE);
    DrawExtendGraph(365, 500, 515, 650, Btn5, TRUE);
    DrawExtendGraph(565, 500, 715, 650, Btn6, TRUE);
    DrawExtendGraph(765, 500, 915, 650, Btn7, TRUE);
    DrawExtendGraph(965, 500, 1115, 650, Btn8, TRUE);
}

void GameSelect_Finalize() {
}