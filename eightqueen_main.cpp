#include "DxLib.h"

int Background, Bgcolor;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int MouseX, MouseY;
	int scene;

	SetGraphMode(1280, 1024, 24);

	if (DxLib_Init() == -1)	
	{
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);
	SetMouseDispFlag(TRUE);

	Bgcolor = GetColor(255, 255, 255);
	Background = LoadGraph("graphic/Eightqueen_Title.png");
	scene = 0;

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		if ( scene == 0 ) {
			ClearDrawScreen();
			DrawBox(0, 0, 801, 601, Bgcolor, TRUE);
			DrawExtendGraph(120, -10, 120 + 400, -10 + 400, Background, TRUE);
			DrawBox(190, 380, 450, 460, GetColor(255, 100, 255), TRUE);
			DrawString(300, 410, "PLAY", Bgcolor);
			ScreenFlip();

			if (CheckHitKey(KEY_INPUT_RETURN) == 1) {
				scene = 1;
			}
		} else if (scene == 1) {
			ClearDrawScreen();
			DrawBox(0, 0, 801, 601, Bgcolor, TRUE);
			DrawString(150, 250, "Enter No. of queen", GetColor(0, 0, 0));
			ScreenFlip;
		}
	}

	DxLib_End();

	return 0;
}