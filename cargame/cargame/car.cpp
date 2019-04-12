//---------------------------------------------------------------------------

#include <stdio.h>
#pragma hdrstop

#include <tchar.h>

#include<conio.h>
#include<stdlib.h>
#include<windows.h>


//---------------------------------------------------------------------------



#define SCREEN_X 12
#define SCREEN_Y 28
#define MAX_EN 3
#define MAX_SPEED 100
#define MIN_SPEED 2000

char arr[SCREEN_X][SCREEN_Y],
en_xy[2][MAX_EN],
frame, life, player_st;

int i, h, score, speed;
char player_x, player_y;

void clear_arr() {
	for (i = 0; i < SCREEN_Y; i++)
	{
		for (h = 0; h < SCREEN_X; h++)
		{
			arr[h][i] = '"';
		}
	}
}

void reset()
{
	for (i = 0; i < MAX_EN; ++i) {
		en_xy[0][i] = 100;
	}
	clear_arr();
	player_x = SCREEN_X / 2;
	player_y = SCREEN_Y - 8;
	arr[player_x][player_y] = 'A';
	life = 5;
	score = 0;
	frame = 0;
	player_st = 0;
	speed = MIN_SPEED;
}


void key()
{
	switch (_getch()) {
	case 'K':
		if (player_x != 0) player_x -= 3;
		break;
	case 'M':
		if (player_x != 9) player_x += 3;
		break;
	case 'r':
		if (life == 0) reset();
		break;
	}
}

void drowscreen()
{
	if (life == 0 && player_st > 0) {
		arr[player_x][player_y] = (i % 2 == player_st % 2) ? ' ' : 'X';
		arr[player_x + 1][player_y] = (i % 2 == player_st % 2) ? 'X' : 'N';
		arr[player_x][player_y + 1] = (i % 2 == player_st % 2) ? 'N' : 'X';
		arr[player_x + 1][player_y + 1] = (i % 2 == player_st % 2) ? ' ' : 'M';
		arr[player_x + 2][player_y + 1] = (i % 2 == player_st % 2) ? 'N' : 'X';
		arr[player_x][player_y + 2] = (i % 2 == player_st % 2) ? 'X' : ' ';
		arr[player_x + 1][player_y + 2] = (i % 2 == player_st % 2) ? 'N' : 'X';
		arr[player_x][player_y + 3] = (i % 2 == player_st % 2) ? 'X' : 'M';
		arr[player_x + 1][player_y + 3] = (i % 2 == player_st % 2) ? 'N' : 'M';
		arr[player_x + 2][player_y + 3] = (i % 2 == player_st % 2) ? 'X' : ' ';
		player_st--;
	}
	else if (!player_st && !life == 0) {
		arr[player_x + 1][player_y] = 'A';
		arr[player_x][player_y + 1] = (i % 2 == frame % 2) ? 'Z' : 'E';
		arr[player_x + 1][player_y + 1] = 'A';
		arr[player_x + 2][player_y + 1] = (i % 2 == frame % 2) ? 'Z' : 'E';

		arr[player_x + 1][player_y + 2] = 'A';
		arr[player_x][player_y + 3] = (i % 2 == frame % 2) ? 'Z' : 'E';
		arr[player_x + 1][player_y + 3] = 'A';
		arr[player_x + 2][player_y + 3] = (i % 2 == frame % 2) ? 'Z' : 'E';
	}
	else if (player_st > 0) {
		arr[player_x + 1][player_y] = (i % 2 == frame % 2) ? 'N' : 'M';
		arr[player_x][player_y + 1] = (i % 2 == frame % 2) ? 'N' : 'M';
		arr[player_x + 1][player_y + 1] = (i % 2 == frame % 2) ? 'N' : 'M';
		arr[player_x + 2][player_y + 1] = (i % 2 == frame % 2) ? 'N' : 'M';

		arr[player_x + 1][player_y + 2] = (i % 2 == frame % 2) ? 'N' : 'M';
		arr[player_x][player_y + 3] = (i % 2 == frame % 2) ? 'N' : 'M';
		arr[player_x + 1][player_y + 3] = (i % 2 == frame % 2) ? 'N' : 'M';
		arr[player_x + 2][player_y + 3] = (i % 2 == frame % 2) ? 'N' : 'M';
		player_st--;
	}


	for (i = 0; i < MAX_EN; ++i) {
		if (en_xy[0][i] != 100)
		{
			arr[en_xy[0][i] + 1][en_xy[1][i]] = 'E';
			arr[en_xy[0][i]][en_xy[1][i] + 1] = (i % 2 == frame % 2) ? 'Z' : 'E';
			arr[en_xy[0][i] + 1][en_xy[1][i] + 1] = 'E';
			arr[en_xy[0][i] + 2][en_xy[1][i] + 1] = (i % 2 == frame % 2) ? 'Z' : 'E';

			arr[en_xy[0][i] + 1][en_xy[1][i] + 2] = 'E';
			arr[en_xy[0][i]][en_xy[1][i] + 3] = (i % 2 == frame % 2) ? 'Z' : 'E';
			arr[en_xy[0][i] + 1][en_xy[1][i] + 3] = 'E';
			arr[en_xy[0][i] + 2][en_xy[1][i] + 3] = (i % 2 == frame % 2) ? 'Z' : 'E';
		}
	}

	for (i = 0; i < SCREEN_Y - 4; i++)
	{
		for (h = 0; h < SCREEN_X; h++)
		{
			if (!(h % 3))
			{
				printf("%s", (i % 2 == frame % 2) ? "┃" : "  ");
			}

			switch (arr[h][i]) {
			case'A':
				printf("▣");
				break;
			case'E':
				printf("□");
				break;
			case'Z':
				printf("■");
				break;
			case'N':
				printf("△");
				break;
			case'M':
				printf("▽");
				break;
			case'X':
				printf("※");
				break;
			default:
				printf("  ");
			}

		}
		printf("%s", (i % 2 == frame % 2) ? "┃" : "  ");

		switch (i) {
		case 0:
		case 1:
			printf("▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒", score);
			break;
		case 2:
			printf("▒     ☜ 자동차 게임 ☞    ▒", score);
			break;
		case 3:
		case 4:
		case 5:
			printf("▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒", score);
			break;
		case 6:
			printf("▒  SPEED: %3dKm            ▒", ((MIN_SPEED + 400) - speed) / 10);
			break;
		case 7:
			printf("▒  SCORE: %5d            ▒", score);
			break;
		case 8:
			printf("▒   LIFE: %5d            ▒", life);
			break;
		case 12:
			printf("%s", (life == 0) ? "▒    OH~ SHIT! GAME OVER   ▒" : "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
			break;
		case 13:
			printf("%s", (life == 0) ? "▒R키를 누르시면 계속됩니다!▒" : "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒");
			break;
		default:
			printf("▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒", score);

		}


		printf("\n");
	}

}

void en() {
	if (!frame) {
		for (i = 0; i < MAX_EN; ++i) {
			if (en_xy[0][i] == 100)
			{
				en_xy[0][i] = (rand() % 4) * 3;
				en_xy[1][i] = 0;
				break;
			}
		}
	}

	for (i = 0; i < MAX_EN; ++i) {
		if (en_xy[0][i] != 100)
		{
			en_xy[1][i]++;

			if (en_xy[1][i] + 3 >= player_y && en_xy[0][i] == player_x) {
				life--;
				player_st = 10;
				en_xy[0][i] = 100;
				speed = MIN_SPEED;
			}

			if (en_xy[1][i] >= SCREEN_Y - 4) {
				en_xy[0][i] = 100;
				score += 50;
			}
		}
	}
}

void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}


int _tmain(int argc, _TCHAR* argv[])
{
	reset();
	while (1)
	{
		if (life)
		{
			en();
			frame = frame > 10 ? 0 : frame + 1;
			speed = (speed > MAX_SPEED) ? speed -= 7 : MAX_SPEED;
			score++;

		}

		gotoxy(0, 0);
		drowscreen();
		clear_arr();
		for (i = 0; i < speed; i++) if (_kbhit()) key();
	}

	return 0;
}
//---------------------------------------------------------------------------

