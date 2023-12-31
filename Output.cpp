#include "Output.h"
#include "SceneMgr.h"
#include "EightQueen.h"
#include "DxLib.h"

extern int Queen;
extern int Solution[100][9];
extern int cnt;
extern int Selecti, Selectj;

void Output_Initialize() {

}

void Output_Update() {
    int posX, posY;

    GetMousePoint(&posX, &posY);

    if (70 < posX && posX < 170 && 900 < posY && posY < 1000) {
        if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
            SceneMgr_ChangeScene(eScene::eScene_Menu);
        }
    }
    if (1138 < posX && posX < 1210 && 900 < posY && posY < 995) {
        if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
            SceneMgr_ChangeScene(eScene::eScene_GameSelect);
        }
    }
}

void Output_Draw() {
    int White, Black, ChessBg1, ChessBg2;
    int BoxX, BoxY;
    int DisplayCnt, Length, i, j, k, l, QueenPos, Solve, TotalSolve;
    int Chess, Retry, Home, Next, Exit;
    int posX, posY, ClickFlg;
    int SolveNo[20];

    White = GetColor(255, 255, 255);
    Black = GetColor(0, 0, 0);
    ChessBg1 = GetColor(245, 217, 132);
    ChessBg2 = GetColor(163, 125, 10);

    if (Queen == 7) {
        BoxX = 74;
        BoxY = 106;
        Length = 238 / Queen;
        DisplayCnt = cnt;
    }
    else {
        BoxX = 70;
        BoxY = 100;
        Length = 240 / Queen;
        DisplayCnt = cnt;
    }

    Chess = LoadGraph("graphic/Queen.png");
    Retry = LoadGraph("graphic/Retry.png");
    Home = LoadGraph("graphic/Home.png");
    Next = LoadGraph("graphic/Next.png");
    Exit = LoadGraph("graphic/Cross.png");

    TotalSolve = eightqueen(Queen);

    for (i = 0; i < 20; i++) {
        SolveNo[i] = 0;
    }

    for (i = 0, k = 0, Solve = 0; i < TotalSolve; i++) {
        for (j = 1; j <= Queen; j++) {
            if (j == Selecti && Solution[i][j] == Selectj) {
                SolveNo[k] = i;
                Solve++;
                k++;
            }
        }
    }

    DrawBox(0, 0, 1280, 1024, White, TRUE);
    DrawBox(10, 10, 1270, 1014, Black, FALSE);
    DrawFormatString(70, 40, Black, "「%d」個の解があります。", Solve);
    DrawExtendGraph(70, 900, 170, 1000, Home, TRUE);
    DrawExtendGraph(1138, 900, 1210, 995, Retry, TRUE);
    DrawExtendGraph(1200, 30, 1250, 80, Exit, TRUE);

    for (i = 1; i <= (Solve - cnt < 12 ? Solve - cnt : 12); i++) {

        l = SolveNo[i - 1 + cnt];

        for (j = 1; j <= Queen; j++) {

            QueenPos = Solution[l][j];

            if (j % 2 == 1) {
                for (k = 1; k <= Queen; k++) {

                    if (k % 2 == 1) {
                        DrawBox(BoxX, BoxY, BoxX + Length, BoxY + Length, ChessBg1, TRUE);
                        BoxX = BoxX + Length;
                    }
                    else {
                        DrawBox(BoxX, BoxY, BoxX + Length, BoxY + Length, ChessBg2, TRUE);
                        BoxX = BoxX + Length;
                    }

                    if (k == QueenPos) {
                        DrawExtendGraph(BoxX - Length, BoxY, BoxX, BoxY + Length, Chess, TRUE);
                    }

                }
            }
            else {

                for (k = 1; k <= Queen; k++) {

                    if (k % 2 == 1) {
                        DrawBox(BoxX, BoxY, BoxX + Length, BoxY + Length, ChessBg2, TRUE);
                        BoxX = BoxX + Length;
                    }
                    else {
                        DrawBox(BoxX, BoxY, BoxX + Length, BoxY + Length, ChessBg1, TRUE);
                        BoxX = BoxX + Length;
                    }

                    if (k == QueenPos) {
                        DrawExtendGraph(BoxX - Length, BoxY, BoxX, BoxY + Length, Chess, TRUE);
                    }

                }

            }

            if (Queen == 7) {
                BoxX = BoxX - 238;
                BoxY = BoxY + Length;
            }
            else {
                BoxX = BoxX - 240;
                BoxY = BoxY + Length;
            }
        }

        if (Queen == 7) {

            BoxX = BoxX + 298;
            BoxY = BoxY - 238;
            if (++DisplayCnt % 4 == 0) {
                BoxX = BoxX - 1192;
                BoxY = BoxY + 268;
            }

        }
        else {

            BoxX = BoxX + 300;
            BoxY = BoxY - 240;
            if (++DisplayCnt % 4 == 0) {
                BoxX = BoxX - 1200;
                BoxY = BoxY + 270;
            }

        }
    }

    if (Solve > 12 && cnt + 12 < Solve) {

        ClickFlg = 0;

        DrawExtendGraph(975, 900, 1100, 1000, Next, TRUE);

        GetMousePoint(&posX, &posY);

        if (975 < posX && posX < 1100 && 900 < posY && posY < 1000) {
            while ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
                ClickFlg++;
            }
        }

        if (ClickFlg > 0) {
            cnt += 12;
        }
    }

}

void Output_Finalize() {

}