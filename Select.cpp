#include "Select.h"
#include "SceneMgr.h"
#include "DxLib.h"

extern int Queen;
extern int cnt;

void Select_Initialize() {

}

void Select_Update() {
    int posX, posY;

    GetMousePoint(&posX, &posY);

    if (290 < posX && posX < 390 && 425 < posY && posY < 525) {
        if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
            Queen = 1;
            cnt = 0;
            SceneMgr_ChangeScene(eScene::eScene_Answer);
        }
    } else if (490 < posX && posX < 590 && 425 < posY && posY < 525) {
        if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
            Queen = 2;
            cnt = 0;
            SceneMgr_ChangeScene(eScene::eScene_Answer);
        }
    } else if (690 < posX && posX < 790 && 425 < posY && posY < 525) {
        if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
            Queen = 3;
            cnt = 0;
            SceneMgr_ChangeScene(eScene::eScene_Answer);
        }
    } else if (890 < posX && posX < 990 && 425 < posY && posY < 525) {
        if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
            Queen = 4;
            cnt = 0;
            SceneMgr_ChangeScene(eScene::eScene_Answer);
        }
    } else if (290 < posX && posX < 390 && 600 < posY && posY < 700) {
        if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
            Queen = 5;
            cnt = 0;
            SceneMgr_ChangeScene(eScene::eScene_Answer);
        }
    } else if (490 < posX && posX < 590 && 600 < posY && posY < 700) {
        if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
            Queen = 6;
            cnt = 0;
            SceneMgr_ChangeScene(eScene::eScene_Answer);
        }
    } else if (690 < posX && posX < 790 && 600 < posY && posY < 700) {
        if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
            Queen = 7;
            cnt = 0;
            SceneMgr_ChangeScene(eScene::eScene_Answer);
        }
    } else if (890 < posX && posX < 990 && 600 < posY && posY < 700) {
        if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
            Queen = 8;
            cnt = 0;
            SceneMgr_ChangeScene(eScene::eScene_Answer);
        }
    }
}

void Select_Draw() {
    int White, Black;
    int Btn1, Btn2, Btn3, Btn4, Btn5, Btn6, Btn7, Btn8, Exit;

    White = GetColor(255, 255, 255);
    Black = GetColor(0, 0, 0);

    Exit = LoadGraph("graphic/Cross.png");
    Btn1 = LoadGraph("graphic/Button1.png");
    Btn2 = LoadGraph("graphic/Button2.png");
    Btn3 = LoadGraph("graphic/Button3.png");
    Btn4 = LoadGraph("graphic/Button4.png");
    Btn5 = LoadGraph("graphic/Button5.png");
    Btn6 = LoadGraph("graphic/Button6.png");
    Btn7 = LoadGraph("graphic/Button7.png");
    Btn8 = LoadGraph("graphic/Button8.png");

    DrawBox(0, 0, 1280, 1024, White, TRUE);
    DrawBox(10, 10, 1270, 1014, Black, FALSE);
    DrawString(460, 325, "—‰¤‚Ì”‚ð‘I‚ñ‚Å‚­‚¾‚³‚¢", Black);
    DrawExtendGraph(1200, 30, 1250, 80, Exit, TRUE);

    DrawExtendGraph(265, 400, 415, 550, Btn1, TRUE);
    DrawExtendGraph(465, 400, 615, 550, Btn2, TRUE);
    DrawExtendGraph(665, 400, 815, 550, Btn3, TRUE);
    DrawExtendGraph(865, 400, 1015, 550, Btn4, TRUE);

    DrawExtendGraph(265, 575, 415, 725, Btn5, TRUE);
    DrawExtendGraph(465, 575, 615, 725, Btn6, TRUE);
    DrawExtendGraph(665, 575, 815, 725, Btn7, TRUE);
    DrawExtendGraph(865, 575, 1015, 725, Btn8, TRUE);
}

void Select_Finalize() {
}