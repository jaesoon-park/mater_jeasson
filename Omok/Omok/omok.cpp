#include <stdio.h>

#include <stdlib.h>

#include <conio.h>

#include <Windows.h>



void intro();

void move_arrow_key(char chr, int *x, int *y, int x_b, int y_b);

void gotoxy(int x, int y);

void draw_check01(int c, int r);

void game_control(void);

void display_stone(int matrix[][20][20]);

int game_end(int matrix[][20][20]);



int main(void)

{

	intro();

	system("cls");

	game_control();

	return 0;

}



void intro()

{

	printf("오목 게임\n\n");

	printf("개발일자: 2017-08-29\n");

	printf("출처: jaimemin.tistory.com\n");

	printf("가로, 세로, 혹은 대각선으로 먼저 5개의 돌을 연달아 배치시키면 이기는 게임\n");

	printf("사용자 2명이 번갈아가면서 돌을 배치시킵니다\n");

	printf("백돌이 먼저 시작합니다\n");

	printf("아직 별다른 규칙을 추가시키지는 않았지만 나중에 3*3 오류를 막도록 하겠습니다\n");

	printf("인지하셨다면 키보드를 누르세요\n");

	_getch();

}



void gotoxy(int x, int y)

{

	COORD  Pos = { x - 1, y - 1 };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}





/*

함수 move_arrow_key

*/

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)

{

	switch (key)

	{

	case 72:

		*y1 = *y1 - 1; //위쪽 방향의 화살표 키 입력

		if (*y1 < 1)

			*y1 = 1;

		break;

	case 75:

		*x1 = *x1 - 2; //왼쪽 방향의 화살표 키 입력

		if (*x1 < 1)

			*x1 = 1;

		break;

	case 77:

		*x1 = *x1 + 2; //오른쪽 방향의 화살표 키 입력

		if (*x1 > x_b)

			*x1 = x_b;

		break;

	case 80:

		*y1 = *y1 + 1; //아래쪽 방향의 화살표 키 입력

		if (*y1 > y_b)

			*y1 = y_b;

		break;

	default:

		return;

	}

}



/*

바둑판 그리기 함수

*/

void draw_check01(int c, int r)

{

	int i, j;

	unsigned char a = 0xa6;

	unsigned char b[12];

	for (i = 1; i < 12; i++)

		b[i] = 0xa0 + i;

	printf("%c%c", a, b[3]);

	for (i = 0; i < c - 1; i++)

		printf("%c%c", a, b[8]);

	printf("%c%c", a, b[4]);

	printf("\n");

	for (i = 0; i < r - 1; i++)

	{

		printf("%c%c", a, b[7]);

		for (j = 0; j < c - 1; j++)

			printf("%c%c", a, b[11]);

		printf("%c%c", a, b[9]);

		printf("\n");

	}

	printf("%c%c", a, b[6]);

	for (i = 0; i < c - 1; i++)

		printf("%c%c", a, b[10]);

	printf("%c%c", a, b[5]);

	printf("\n");

}



/*

번갈아가며 흑백의 바둑돌을 놓는 함수 game_control

*/

void game_control(void)

{

	int x = 1, y = 1, other = 0;

	int matrix[2][20][20] = { 0 };

	char key;

	const char *stone[2] = { "○", "●" };

	do

	{

		gotoxy(1, 1);

		draw_check01(18, 18);

		gotoxy(x, y);

		printf("%s", stone[other]);

		display_stone(matrix);

		gotoxy(1, 20);

		printf("방향키로 움직이고 ");

		printf("스페이스 키를 누르시오.");

		gotoxy(1, 21);

		printf("돌을 놓았으면 상대방 차례입니다. ");

		key = _getch();

		if (key == 27)

			exit(0);

		else if (key == 32)

		{

			matrix[other][(x + 1) / 2][y] = 1;

			other = 1 - other;

		}

		else if (key >= 72)

			move_arrow_key(key, &x, &y, 37, 19);

		if (game_end(matrix) == 1)

		{

			gotoxy(1, 24);

			printf("흑돌이 이겼습니다\n");

			break;

		}

		else if (game_end(matrix) == 2)

		{

			gotoxy(1, 24);

			printf("백돌이 이겼습니다\n");

			break;

		}

	} while (1);

}



/*

바둑판 위에 놓은 돌을 흑돌과 백돌로 구분하여 출력하는 함수

*/

void display_stone(int matrix[][20][20])

{

	int i, x, y;

	const char *stone[2] = { "○", "●" };



	for (i = 0; i < 2; i++)

		for (x = 1; x < 20; x++)

			for (y = 1; y < 20; y++)

			{

				if (matrix[i][x][y] == 1)

				{

					gotoxy(x * 2 - 1, y);

					printf("%s", stone[i]);

				}

			}

}



/*

오목의 승패 갈림 판별 함수

*/

int game_end(int matrix[][20][20])

{

	int count = 0;

	//가로 5개

	for (int i = 0; i < 2; i++)

	{

		for (int y = 1; y < 20; y++)

		{

			count = 0; //새로운 줄일 때는 count=0으로 시작

			for (int x = 1; x < 20; x++)

			{

				if (matrix[i][x][y])

					count++;

				else

					count = 0;

				if (count == 5)

					return (i + 1);

			}

		}

	}

	//세로 5개

	for (int i = 0; i < 2; i++)

	{

		for (int x = 1; x < 20; x++)

		{

			count = 0; //새로운 줄일 때는 count=0으로 시작

			for (int y = 1; y < 20; y++)

			{

				if (matrix[i][x][y])

					count++;

				else

					count = 0;

				if (count == 5)

					return (i + 1);

			}

		}

	}

	//왼쪽위에서 오른쪽 아래 대각선 ↘

	for (int i = 0; i < 2; i++)

	{

		for (int x = 1; x < 16; x++) //대각선이므로 15까지가 마지노선

		{

			count = 0; //새로운 대각선일 때는 count=0으로 시작

			for (int y = 1; y < 16; y++) //대각선이기 때문에 15까지가 마지노선

			{

				int temp1 = x; //x와 y값을 저장

				int temp2 = y;

				for (int j = 0; j < 5; j++)

				{

					if (matrix[i][temp1++][temp2++])

						count++;

					else

						count = 0;

				}

				if (count == 5)

					return (i + 1);

			}

		}

	}

	//왼쪽 아래에서 오른쪽 위 대각선 ↗

	for (int i = 0; i < 2; i++)

	{

		for (int x = 1; x < 16; x++) //대각선이므로 15까지가 마지노선

		{

			count = 0;

			for (int y = 5; y < 20; y++) //대각선이기 때문에 5부터 시작

			{

				int temp1 = x;

				int temp2 = y;

				for (int j = 0; j < 5; j++)

				{

					if (matrix[i][temp1++][temp2--])

						count++;

					else

						count = 0;

				}

				if (count == 5)

					return (i + 1);

			}

		}

	}

	return 0; //게임이 안 끝났으면 0 반환

}