#include "DxLib.h"
#include "SceneMgr.h"

int Queen = 0;
int Solution[100][9];
int cnt;
int Selecti, Selectj;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    int posX, posY;
    
    if (DxLib_Init() < 0) {
        return -1;
    }
    
    SetGraphMode(1280, 1024, 16);
    SetDrawScreen(DX_SCREEN_BACK);
    SetMouseDispFlag(TRUE);
    SetFontSize(30);

    SceneMgr_Initialize();
    
    while (ProcessMessage() == 0) {
        SceneMgr_Update();
        ClearDrawScreen();
        SceneMgr_Draw();
        ScreenFlip();
        GetMousePoint(&posX, &posY);
        if (1200 < posX && posX < 1250 && 30 < posY && posY < 80 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
            break;
        }
    }

    SceneMgr_Finalize();

    DxLib_End();

    return 0;
}