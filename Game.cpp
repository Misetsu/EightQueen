#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"

extern int Queen;
extern int cnt;
extern int Selecti, Selectj;

void Game_Initialize() {

}

void Game_Update() {
	int posX, posY;

	GetMousePoint(&posX, &posY);

	if (280 < posX && posX < 1000 && 240 < posY && posY < 960) {
		if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0) {
			cnt = 0;
			Selecti = (posY - 240) / (720 / Queen) + 1;
			Selectj = (posX - 280) / (720 / Queen) + 1;
			SceneMgr_ChangeScene(eScene::eScene_Output);
		}
	}
}

void Game_Draw() {
	int White, Black, ChessBg1, ChessBg2;
	int BoxX, BoxY;
	int Chess, Exit;
	int Length, i, j, Posi, Posj;
	int posX, posY;

	White = GetColor(255, 255, 255);
	Black = GetColor(0, 0, 0);
	ChessBg1 = GetColor(245, 217, 132);
	ChessBg2 = GetColor(163, 125, 10);
	BoxX = 280;
	BoxY = 240;
	if (Queen == 7) {
		Length = 721 / Queen;
	}
	else {
		Length = 720 / Queen;
	}
	

	Chess = LoadGraph("graphic/Queen.png");
	Exit = LoadGraph("graphic/Cross.png");

	DrawBox(0, 0, 1280, 1024, White, TRUE);
	DrawBox(10, 10, 1270, 1014, Black, FALSE);
	DrawExtendGraph(1200, 30, 1250, 80, Exit, TRUE);
	DrawString(445, 105, "—‰¤‚ÌˆÊ’u‚ð‘I‚ñ‚Å‚­‚¾‚³‚¢", Black);

	GetMousePoint(&posX, &posY);
	Posi = (posY - 240) / Length + 1;
	Posj = (posX - 280) / Length + 1;

	for (i = 1; i <= Queen; i++) {
		if (i % 2 == 1) {
			for (j = 1; j <= Queen; j++) {
				if (j % 2 == 1) {
					DrawBox(BoxX, BoxY, BoxX + Length, BoxY + Length, ChessBg1, TRUE);
					BoxX += Length;
				}
				else {
					DrawBox(BoxX, BoxY, BoxX + Length, BoxY + Length, ChessBg2, TRUE);
					BoxX += Length;
				}

				if (i == Posi && j == Posj) {
					DrawExtendGraph(BoxX - Length, BoxY, BoxX, BoxY + Length, Chess, TRUE);
				}
			}
		}
		else {
			for (j = 1; j <= Queen; j++) {
				if (j % 2 == 1) {
					DrawBox(BoxX, BoxY, BoxX + Length, BoxY + Length, ChessBg2, TRUE);
					BoxX += Length;
				}
				else {
					DrawBox(BoxX, BoxY, BoxX + Length, BoxY + Length, ChessBg1, TRUE);
					BoxX += Length;
				}

				if (i == Posi && j == Posj) {
					DrawExtendGraph(BoxX - Length, BoxY, BoxX, BoxY + Length, Chess, TRUE);
				}
			}
		}

		if (Queen == 7) {
			BoxX -= 721;
			BoxY += Length;
		}
		else {
			BoxX -= 720;
			BoxY += Length;
		}

	}

}

void Game_Finalize() {

}