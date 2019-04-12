//---------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h> //system("cls")를 쓰기 위한 헤더파일
#include<conio.h> //getch()를 쓰기 위한 헤더 파일
#include<string.h> //strcpy를 쓰기 위한 헤더 파일
#include<process.h> //exit를 쓰기 위한 헤더 파일
#include<time.h>

#pragma hdrstop

#include <tchar.h>
//---------------------------------------------------------------------------


//name과 몇가지 전역 변수로 설정한다//
static char name[7];
static int select, mainroop = 1, type, gold = 2000, year = 1, tpart = 1, tp = 3;

struct MAP //지역 정보 구조체 변수
{
	char mapname[10];
	int civil;
	int mind;
	int army;
	int power;
	int own;
	int tax;
};

struct MAP m[9]; //전역 변수로 지역정보구조체변수 선언

void delay(clock_t sleep);//딜레이 함수


int intro(void); // 인트로 메뉴

int charmake(void); //캐릭터 생성 함수

int inmilli(void); // 군사함수 (전쟁,징병,훈련)
int war(void); //전쟁함수
int wartarget(void); //전쟁관련 함수(외교에서도 쓰임)
int jing(void); //징병함수
int excer(void); //훈련함수

int ininjob(void); // 내정함수(복지,개발)
int bokji(void); //복지함수
int gaibal(void); //개발함수

int inoutt(void); // 외교함수 (군사혼란)
int armyfuse(void); //군사혼란함수

int insystem(void); // 시스템인터페이스 함수
int savegame(void);//세이브 함수
int loadgame(void);//로드 함수

int inter(void); // 게임내 인터페이스 함수
int chogi(void); //지역 정보 함수 초기화 함수

int infomation(void);// 정보함수
int mainmap(void); //맵과 사용자 정보를 보여준다

int turnout(void); //턴 종료 (시간 경과)
int mapguide(void); //자신의 지역을 선택할 수 있게 해준다

int _tmain(int argc, _TCHAR* argv[])
{

	//게임 시작시 메뉴 함수 호출//
	intro();

	//캐릭터 생성함수를 불러들인다//
	charmake();

	//데이터 초기화 함수
	chogi();

	//인터페이스 함수 호출//
	inter();

	return 0;
}

int intro(void)
{
	while (mainroop == 1)
	{
		system("cls");
		printf("\n\n");
		printf("                    ┏━━━━━━━━━━━━━━━━━┓\n");
		printf("                    ┃             삼국지 v0.1          ┃\n");
		printf("                    ┗━━━━━━━━━━━━━━━━━┛\n\n\n");
		printf("               ┏━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("               ┃        [1]게임시작  [2]로드  [3]종료       ┃\n");
		printf("               ┗━━━━━━━━━━━━━━━━━━━━━━┛\n");

		select = _getch();


		if (select == '1')
		{
			mainroop = 0;
		}
		else if (select == '2')
		{
			system("cls");
			chogi();
			system("cls");
			if (loadgame() == 1)
				return -1;
			inter();
			_getch();
		}
		else if (select == '3')
		{
			exit(0);
		}
		else
		{
			printf("\nWrong keyword Press any key"); _getch();
		}

		system("cls");
	}
	return 0;
}

//캐릭터 생성 함수//
int charmake(void)
{
	printf("\n\n  ▶ 당신의 이름을 입력하세요(한글 세글자 이하) ◀\n\n\n    ☞");
	scanf("%6s", &name);

	system("cls");

	mainroop = 1;		//while을 돌리기 위해 mainroop함수를 초기화 시켜준다//
	while (mainroop == 1)
	{

		printf("\n\n  ▶ %s님의 성향을 선택하세요 ◀\n\n", name);
		printf("       ┏━━━━━━━━┓\n");
		printf("       ┃                ┃\n");
		printf("       ┃   [1] 전투형   ┃\n");
		printf("       ┃                ┃\n");
		printf("       ┃   [2] 내정형   ┃\n");
		printf("       ┃                ┃\n");
		printf("       ┃   [3] 외교형   ┃\n");
		printf("       ┃                ┃\n");
		printf("       ┗━━━━━━━━┛\n");

		select = _getch();
		if (select == '1') {
			mainroop = 0; type = 1; printf("\n전투형 캐릭터를 선택하셨습니다.\n"); _getch();
		}
		else if (select == '2') {
			mainroop = 0;
			type = 2; printf("\n내정에 특화된 캐릭터를 선택하셨습니다.\n"); _getch();
		}
		else if (select == '3') {
			mainroop = 0; type = 3; printf("\n외교적인 능력이 뛰어난 캐릭터를 선택하셨습니다.\n"); _getch();
		}
		else if (select == '4') {
			mainroop = 0; type = 4; printf("\n숨겨진 캐릭터 입니다.\n"); _getch();
		}
		else {
			printf("\nWrong keyword Press any key"); _getch();
		}
		system("cls");
	}
	return 0;
}



// 세부 인터페이스 함수


// 군사 관련
int inmilli(void)
{
	system("cls");
	printf("\n   ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("                     [%d년]   [%d/4분기]   [행동치 %d]", year, tpart, tp);
	printf("\n   ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	mainmap();
	printf("┏━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃   [1] 공격  [2] 징병  [3] 훈련  [4] 뒤로   ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━┛\n");

	select = _getch();
	if (select == '1')
		war();
	else if (select == '2')
		jing();
	else if (select == '3')
		excer();
	else
		return 0;

	return 0;
}

//징병함수
int jing(void)
{

	if (tp == 0)
	{
		printf("   ▷ 행동력이 부족합니다"); _getch();
		return 0;
	}

	mapguide();

	select = _getch();

	if (select == '1')
		select = 0;
	else if (select == '2')
		select = 1;
	else if (select == '3')
		select = 2;
	else if (select == '4')
		select = 3;
	else if (select == '5')
		select = 4;
	else if (select == '6')
		select = 5;
	else if (select == '7')
		select = 6;
	else if (select == '8')
		select = 7;
	else if (select == '9')
		select = 8;
	else
	{
		printf("   ▷ 잘못 입력 하셨습니다"); _getch();
		return 0;
	}
	if (m[select].mind < 10)
	{
		printf("   ▷ 민심이 너무 낮습니다"); _getch();
		return 0;
	}
	if (m[select].civil < 1000)
	{
		printf("   ▷ 인구가 너무 적습니다"); _getch();
		return 0;
	}



	if (m[select].own == 1)
	{
		if (gold >= 1000)
		{
			m[select].army = m[select].army + m[select].civil / 100;
			printf("   ▶ 군사를 모집 합니다\n\n");
			gold = gold - 1000;
			printf("   ▷ 금이 1000원 줄었습니다.\n");
			m[select].mind = m[select].mind - 10;
			printf("   ▷ 민심이 10줄었습니다!\n");
			m[select].civil = m[select].civil - 500;
			printf("   ▷ 인구가 %d줄었습니다!\n", m[select].civil / 100);
			m[select].army = m[select].army + 500;
			printf("   ▷ 군사가 %d증가했습니다!\n\n", m[select].civil / 100);

			m[select].civil = m[select].civil - m[select].civil / 100;

			printf("   ▷ %s의 군사가 [%d]입니다\n", m[select].mapname, m[select].army);
			printf("   ▷ %s의 민심이 [%d]입니다\n", m[select].mapname, m[select].mind);
			printf("   ▷ %s의 금이 [%d]입니다\n", m[select].mapname, gold);
			tp--;
			_getch();
		}
		else
		{
			printf("   ▷ 돈이 부족합니다\n");
			_getch();
		}
	}

	else
	{
		printf("   ▷ 당신의 지역이 아닙니다\n");
		_getch();

	}
	return 0;
}
// 훈련함수
int excer(void)
{
	if (tp == 0)
	{
		printf("   ▷ 행동력이 부족합니다"); _getch();
		return 0;
	}


	mapguide();

	select = _getch();

	if (select == '1')
		select = 0;
	else if (select == '2')
		select = 1;
	else if (select == '3')
		select = 2;
	else if (select == '4')
		select = 3;
	else if (select == '5')
		select = 4;
	else if (select == '6')
		select = 5;
	else if (select == '7')
		select = 6;
	else if (select == '8')
		select = 7;
	else if (select == '9')
		select = 8;
	else
	{
		printf("   ▷ 잘못 입력 하셨습니다"); _getch();
		return 0;
	}

	if (m[select].power == 400)
	{
		printf("   ▷ 최대치 입니다"); _getch();
		return 0;
	}


	if (m[select].own == 1)
	{
		if (gold >= 500)
		{
			printf("   ▶ 군사를 훈련 시킵니다\n\n");
			gold = gold - 500;
			printf("   ▷ 금이 500원 줄었습니다.\n");
			m[select].power = m[select].power + 5;
			printf("   ▷ 훈련도가 5상승했습니다!\n\n");
			printf("   ▷ %s의 훈련도가 [%d]입니다\n", m[select].mapname, m[select].power);
			printf("   ▷ %s의 금이 [%d]입니다\n", m[select].mapname, gold);
			tp--;
			_getch();
		}
		else
		{
			printf("   ▷ 돈이 부족합니다\n");
			_getch();
		}
	}

	else
	{
		printf("   ▷ 당신의 지역이 아닙니다\n");
		_getch();

	}
	return 0;
}

//내정 관련
int ininjob(void)
{
	system("cls");
	printf("\n   ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("                     [%d년]   [%d/4분기]   [행동치 %d]", year, tpart, tp);
	printf("\n   ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	mainmap();
	printf("┏━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃         [1] 복지  [2] 개발  [3] 뒤로       ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━┛\n");

	select = _getch();
	if (select == '1')
		bokji();
	else if (select == '2')
		gaibal();
	else
		return 0;

	return 0;
}

//복지 함수
int bokji(void)
{
	if (tp == 0)
	{
		printf("   ▷ 행동력이 부족합니다"); _getch();
		return 0;
	}
	printf("\n어느 성의 복지를 실행 하겠습니까?\n");

	mapguide();

	select = _getch();

	if (select == '1')
		select = 0;
	else if (select == '2')
		select = 1;
	else if (select == '3')
		select = 2;
	else if (select == '4')
		select = 3;
	else if (select == '5')
		select = 4;
	else if (select == '6')
		select = 5;
	else if (select == '7')
		select = 6;
	else if (select == '8')
		select = 7;
	else if (select == '9')
		select = 8;
	else
	{
		printf("   ▷ 잘못 입력 하셨습니다"); _getch();
		return 0;
	}

	if (m[select].mind == 120)
	{
		printf("   ▷ 최대치 입니다."); _getch();
		return 0;
	}

	if (m[select].own == 1)
	{
		if (gold >= 200)
		{
			printf("   ▶ 복지를 수행 합니다\n\n");
			gold = gold - 200;
			printf("   ▷ 금이 200원 줄었습니다.\n");
			m[select].mind = m[select].mind + 5;
			printf("   ▷ 민심이 +5올랐습니다!\n\n");
			printf("   ▷ %s의 민심이 [%d]입니다\n", m[select].mapname, m[select].mind);
			printf("   ▷ %s의 금이 [%d]입니다\n", m[select].mapname, gold);
			tp--;
			_getch();
		}
		else
		{
			printf("   ▷ 돈이 부족합니다\n");
			_getch();
		}
	}

	else
	{
		printf("   ▷ 당신의 지역이 아닙니다\n");
		_getch();
	}
	return 0;
}


//개발 함수
int gaibal(void)
{
	if (tp == 0)
	{
		printf("   ▷ 행동력이 부족합니다"); _getch();
		return 0;
	}

	if (gold < 1000)
	{
		printf("   ▷ 금이 부족합니다"); _getch();
		return 0;
	}

	printf("\n어느 성의 개발을 실행 하겠습니까?\n");

	mapguide();

	select = _getch();

	if (select == '1')
		select = 0;
	else if (select == '2')
		select = 1;
	else if (select == '3')
		select = 2;
	else if (select == '4')
		select = 3;
	else if (select == '5')
		select = 4;
	else if (select == '6')
		select = 5;
	else if (select == '7')
		select = 6;
	else if (select == '8')
		select = 7;
	else if (select == '9')
		select = 8;
	else
	{
		printf("   ▷ 잘못 입력 하셨습니다"); _getch();
		return 0;
	}
	if (m[select].own == 1)
	{
		if (gold >= 200)
		{
			printf("   ▶ 개발을 수행 합니다\n\n");
			gold = gold - 1000;
			printf("   ▷ 금이 1000원 줄었습니다.\n");
			m[select].civil = m[select].civil + 1000;
			printf("   ▷ 인구가 +1000올랐습니다!\n\n");
			printf("   ▷ %s의 인구가 [%d]입니다\n", m[select].mapname, m[select].civil);
			printf("   ▷ %s의 금이 [%d]입니다\n", m[select].mapname, gold);
			tp--;
			_getch();
		}
		else
		{
			printf("   ▷ 돈이 부족합니다\n");
			_getch();
		}
	}

	else
	{
		printf("   ▷ 당신의 지역이 아닙니다\n");
		_getch();

	}
	return 0;
}
//외교 함수
int inoutt(void)
{
	system("cls");
	printf("\n   ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	printf("                     [%d년]   [%d/4분기]   [행동치 %d]", year, tpart, tp);
	printf("\n   ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
	mainmap();
	printf("┏━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃    [1] 군사혼란                [2] 뒤로    ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━┛\n");

	select = _getch();
	if (select == '1')
	{
		armyfuse();
	}
	else
		return 0;

	return 0;
}
//군사 혼란 함수
int armyfuse(void)
{
	int i = 1, seltar, tarcnt;

	if (tp < 1)
	{
		printf("   ▷ 행동력이 부족합니다"); _getch();
		return 0;
	}

	if (gold < 500)
	{
		printf("   ▷ 자금이 부족합니다"); _getch();
		return 0;
	}




	wartarget();
	seltar = _getch();
	if (seltar == '1')
		seltar = 0;
	else if (seltar == '2')
		seltar = 1;
	else if (seltar == '3')
		seltar = 2;
	else if (seltar == '4')
		seltar = 3;
	else if (seltar == '5')
		seltar = 4;
	else if (seltar == '6')
		seltar = 5;
	else if (seltar == '7')
		seltar = 6;
	else if (seltar == '8')
		seltar = 7;
	else if (seltar == '9')
		seltar = 8;
	else
	{
		printf("   ▷ 잘못 입력 하셨습니다"); _getch();
		return 0;
	}

	tarcnt = 0;

	for (i = 0; i < 9; i++)
	{
		if (m[i].own == 1)
		{
			tarcnt++;
		}
	}

	if (seltar < tarcnt)
	{
		printf("   ▷ 자신의 지역 입니다\n"); _getch();
		return 0;
	}

	if (m[seltar - 1].own == 1)
	{
		printf("   ▷ %s에 군사혼란을 실행합니다\n", m[seltar].mapname);
	}
	else
	{
		printf("   ▷ 실행 가능한 지역이 아닙니다\n"); _getch();
		return 0;
	}

	m[seltar].power = m[seltar].power - 2;
	gold = gold - 500;
	tp--;
	printf("   ▷ 적군사의 사기가 약간 떨어졌습니다.\n");
	printf("   ▷ 자금이 %d가 되었습니다\n", gold);
	_getch();
	return 0;
}

//시스템 메뉴 함수
int insystem(void)
{
	mainroop = 1;
	while (mainroop == 1)
	{
		system("cls");
		printf("\n\n\n\n");
		printf(" 			     ┏━━━━━━━━━━┓\n");
		printf("			     ┃                    ┃\n");
		printf("			     ┃   ◆ 시 스 템 ◆   ┃\n");
		printf("			     ┃                    ┃\n");
		printf("			     ┠──────────┨\n");
		printf("			     ┃                    ┃\n");
		printf("			     ┃    [1] 세 이 브    ┃\n");
		printf("			     ┃                    ┃\n");
		printf("			     ┃    [2] 로    드    ┃\n");
		printf("			     ┃                    ┃\n");
		printf("	 		     ┃    [3] 종    료    ┃\n");
		printf("			     ┃                    ┃\n");
		printf("			     ┃    [4] 게임으로    ┃\n");
		printf("			     ┃                    ┃\n");
		printf("			     ┗━━━━━━━━━━┛\n");

		select = _getch();
		if (select == '1')
		{
			savegame();
		}
		else if (select == '2')
		{
			if (loadgame() == 1)
				return 0;
			_getch();
		}
		else if (select == '3')
		{
			printf("\n감사합니다\n");
			_getch();
			exit(0);
		}
		else if (select == '4')
		{
			printf("\n게임으로 돌아갑니다\n");
			_getch();
			return 0;
		}
		else
		{
			printf("\nWrong keyword Press any key"); _getch();
		}


	}

	return 0;
}

int savegame(void) //세이브 함수
{
	int i;
	char snm1[7], snm2[7], snm3[7];
	FILE *savman, *savmap, *lman1, *lman2, *lman3;

	if ((lman1 = fopen("ssavman.s01", "r")) == NULL)
	{
		strcpy(snm1, "EMPTY");
	}
	else
	{
		fscanf(lman1, "%s", snm1);
		fclose(lman1);
	}


	if ((lman2 = fopen("ssavman.s02", "r")) == NULL)
	{
		strcpy(snm2, "EMPTY");
	}
	else
	{
		fscanf(lman2, "%s", snm2);
		fclose(lman2);
	}



	if ((lman3 = fopen("ssavman.s03", "r")) == NULL)
	{
		strcpy(snm3, "EMPTY");
	}
	else
	{
		fscanf(lman3, "%s", snm3);
		fclose(lman3);
	}





	system("cls");
	printf("\n\n\n\n");
	printf("                        ┏━━━━━━━━━━━┓\n");
	printf("                        ┃                      ┃\n");
	printf("                        ┃       게임 저장      ┃\n");
	printf("                        ┃                      ┃\n");
	printf("                        ┣━━━━━━━━━━━┫\n");
	printf("                        ┃                      ┃\n");
	printf("                        ┃    [1 %6s SLOT]   ┃\n", snm1);
	printf("                        ┃                      ┃\n");
	printf("                        ┃    [2 %6s SLOT]   ┃\n", snm2);
	printf("                        ┃                      ┃\n");
	printf("                        ┃    [3 %6s SLOT]   ┃\n", snm3);
	printf("                        ┃                      ┃\n");
	printf("                        ┗━━━━━━━━━━━┛\n");
	select = _getch();
	printf("게임을 저장합니다\n");

	if (select == '1')
	{
		savman = fopen("ssavman.s01", "w");

		fprintf(savman, "%s %d %d %d %d %d", name, gold, type, year, tpart, tp);
		fclose(savman);

		savmap = fopen("ssavmap.s01", "w");
		for (i = 0; i < 9; i++)
		{
			fprintf(savmap, "%d %d %d %d %d ", m[i].civil, m[i].mind, m[i].army, m[i].power, m[i].own);
		}
		fclose(savmap);
	}

	else if (select == '2')
	{
		savman = fopen("ssavman.s02", "w");

		fprintf(savman, "%s %d %d %d %d %d", name, gold, type, year, tpart, tp);
		fclose(savman);

		savmap = fopen("ssavmap.s02", "w");
		for (i = 0; i < 9; i++)
		{
			fprintf(savmap, "%d %d %d %d %d ", m[i].civil, m[i].mind, m[i].army, m[i].power, m[i].own);
		}
		fclose(savmap);
	}

	else if (select == '3')
	{
		savman = fopen("ssavman.s03", "w");

		fprintf(savman, "%s %d %d %d %d %d", name, gold, type, year, tpart, tp);
		fclose(savman);

		savmap = fopen("ssavmap.s03", "w");
		for (i = 0; i < 9; i++)
		{
			fprintf(savmap, "%d %d %d %d %d ", m[i].civil, m[i].mind, m[i].army, m[i].power, m[i].own);
		}
		fclose(savmap);
	}



	_getch();
	return 0;
}

int loadgame(void) //로드함수
{
	int i;
	char snm1[7], snm2[7], snm3[7];
	FILE *loadman, *loadmap, *lman1, *lman2, *lman3;

	if ((lman1 = fopen("ssavman.s01", "r")) == NULL)
	{
		strcpy(snm1, "EMPTY");
	}
	else
	{
		fscanf(lman1, "%s", snm1);
		fclose(lman1);
	}


	if ((lman2 = fopen("ssavman.s02", "r")) == NULL)
	{
		strcpy(snm2, "EMPTY");
	}
	else
	{
		fscanf(lman2, "%s", snm2);
		fclose(lman2);
	}



	if ((lman3 = fopen("ssavman.s03", "r")) == NULL)
	{
		strcpy(snm3, "EMPTY");
	}
	else
	{
		fscanf(lman3, "%s", snm3);
		fclose(lman3);
	}





	system("cls");
	printf("\n\n\n\n");
	printf("                        ┏━━━━━━━━━━━┓\n");
	printf("                        ┃                      ┃\n");
	printf("                        ┃       게임 로드      ┃\n");
	printf("                        ┃                      ┃\n");
	printf("                        ┣━━━━━━━━━━━┫\n");
	printf("                        ┃                      ┃\n");
	printf("                        ┃    [1 %6s SLOT]   ┃\n", snm1);
	printf("                        ┃                      ┃\n");
	printf("                        ┃    [2 %6s SLOT]   ┃\n", snm2);
	printf("                        ┃                      ┃\n");
	printf("                        ┃    [3 %6s SLOT]   ┃\n", snm3);
	printf("                        ┃                      ┃\n");
	printf("                        ┗━━━━━━━━━━━┛\n");
	select = _getch();


	if (select == '1')
	{
		if ((loadman = fopen("ssavman.s01", "r")) == NULL)
		{
			printf("저장된 게임 데이터가 없습니다\n"); _getch();
			system("cls");
			return 1;
		}
		fscanf(loadman, "%s %d %d %d %d %d", name, &gold, &type, &year, &tpart, &tp);
		fclose(loadman);

		loadmap = fopen("ssavmap.s01", "r");
		for (i = 0; i < 9; i++)
		{
			fscanf(loadmap, "%d %d %d %d %d", &m[i].civil, &m[i].mind, &m[i].army, &m[i].power, &m[i].own);
		}
		fclose(loadmap);
	}

	else if (select == '2')
	{
		if ((loadman = fopen("ssavman.s02", "r")) == NULL)
		{
			printf("저장된 게임 데이터가 없습니다\n"); _getch();
			system("cls");
			return 1;
		}

		fscanf(loadman, "%s %d %d %d %d %d", name, &gold, &type, &year, &tpart, &tp);
		fclose(loadman);

		loadmap = fopen("ssavmap.s02", "r");
		for (i = 0; i < 9; i++)
		{
			fscanf(loadmap, "%d %d %d %d %d", &m[i].civil, &m[i].mind, &m[i].army, &m[i].power, &m[i].own);
		}
		fclose(loadmap);
	}

	else if (select == '3')
	{
		if ((loadman = fopen("ssavman.s03", "r")) == NULL)
		{
			printf("저장된 게임 데이터가 없습니다\n"); _getch();
			system("cls");
			return 1;
		}

		fscanf(loadman, "%s %d %d %d %d %d", name, &gold, &type, &year, &tpart, &tp);
		fclose(loadman);

		loadmap = fopen("ssavmap.s03", "r");
		for (i = 0; i < 9; i++)
		{
			fscanf(loadmap, "%d %d %d %d %d", &m[i].civil, &m[i].mind, &m[i].army, &m[i].power, &m[i].own);
		}
		fclose(loadmap);
	}

	else
	{
		printf("잘못 누르셨습니다\n");
		_getch();
		return 1;
	}
	system("cls");
	return 0;

}

//메인 맵과 사용자 정보 출력 함수
int mainmap(void)
{
	/*
	┌───────────────┐ ┏━━━━━━━━━━┓
	│                              │ ┃                    ┃
	│  O[허창]━O[건업]━O[성도]   │ ┃ 짱꼴라             ┃
	│                       ┃     │ ┃                    ┃
	│  O[신야]━O[낙양]━O[양양]   │ ┃ 10000000000000 원  ┃
	│     ┃                       │ ┃                    ┃
	│  O[평원]━O[천수]━O[북평]   │ ┃ 내정형             ┃
	│                              │ ┃                    ┃
	└───────────────┘ ┗━━━━━━━━━━┛
	*/
	printf("\n");
	printf("    ┏━━━━━━━━━━━━━━━┓ ┏━━━━━━━━━━━━━━┓\n");
	printf("    ┃                              ┃ ┃                            ┃\n");
	printf("    ┃         □전체지도□         ┃ ┃       □사용자 정보□      ┃\n");
	printf("    ┃                              ┃ ┃                            ┃\n");
	printf("    ┃  ");

	if (m[0].own == 1)
		printf("O");
	else if (m[0].own == 0)
		printf("X");
	printf("[%s]", m[0].mapname);

	printf("━");

	if (m[1].own == 1)
		printf("O");
	else if (m[1].own == 0)
		printf("X");
	printf("[%s]", m[1].mapname);

	printf("━");

	if (m[2].own == 1)
		printf("O");
	else if (m[2].own == 0)
		printf("X");
	printf("[%s]", m[2].mapname);

	printf("   ┃ ┃ [이  름]  %11s      ┃ \n", name);
	printf("    ┃                       ┃     ┃ ┃                            ┃\n");
	printf("    ┃  ");

	if (m[5].own == 1)
		printf("O");
	else if (m[5].own == 0)
		printf("X");
	printf("[%s]", m[5].mapname);

	printf("━");

	if (m[4].own == 1)
		printf("O");
	else if (m[4].own == 0)
		printf("X");
	printf("[%s]", m[4].mapname);

	printf("━");

	if (m[3].own == 1)
		printf("O");
	else if (m[3].own == 0)
		printf("X");
	printf("[%s]", m[3].mapname);

	printf("   ┃ ┃ [예  산]  %11d      ┃\n", gold);
	printf("    ┃     ┃                       ┃ ┃                            ┃\n");
	printf("    ┃  ");

	if (m[6].own == 1)
		printf("O");
	else if (m[6].own == 0)
		printf("X");
	printf("[%s]", m[6].mapname);

	printf("━");

	if (m[7].own == 1)
		printf("O");
	else if (m[7].own == 0)
		printf("X");
	printf("[%s]", m[7].mapname);

	printf("━");

	if (m[8].own == 1)
		printf("O");
	else if (m[8].own == 0)
		printf("X");
	printf("[%s]", m[8].mapname);
	printf("   ┃ ┃");
	if (type == 1)
	{
		printf(" [성  향]       전투형");
	}
	else if (type == 2)
	{
		printf(" [성  향]       내정형");
	}
	else if (type == 3)
	{
		printf(" [성  향]       외교형");
	}
	else if (type == 4)
	{
		printf(" [성  향]       만능형");
	}
	printf("      ┃\n");
	printf("    ┃                              ┃ ┃                            ┃\n");
	printf("    ┗━━━━━━━━━━━━━━━┛ ┗━━━━━━━━━━━━━━┛");
	printf("\n  [ O : %s님의 지역 | X : 적의 지역]\n", name);
	printf("\n\n");

	return 0;
}

//사용자 인터페이스 함수//
int inter(void)
{
	mainroop = 1;
	while (mainroop == 1)
	{
		printf("\n   ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		printf("                     [%d년]   [%d/4분기]   [행동치 %d]", year, tpart, tp);
		printf("\n   ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
		mainmap();
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃   [1] 군사  [2] 내정  [3] 외교  [4] 시스템  [5] 정보  [6] 시간경과   ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");

		select = _getch();
		if (select == '1')
		{
			inmilli();

		}
		else if (select == '2')
		{
			ininjob();

		}
		else if (select == '3')
		{
			inoutt();

		}
		else if (select == '4')
		{
			mainroop = 0;
			insystem();
		}
		else if (select == '5')
		{
			infomation();
		}
		else if (select == '6')
		{
			if (turnout() == 1)
			{
				printf("\n   당신은 천하통일을 하지 못하고 늙어 죽었습니다!!\n");
				printf("  천하는 과연 누구의 손으로 넘어갈 것인가?? \n");
				printf("\n 아무키나 누르면 빠져 나갑니다.\n");
				_getch();
				exit(0);
			}
		}
		else {
			printf("\nwrong keyword!"); _getch();
		}
		system("cls");
	}
	return 0;
}

//지역정보 초기화 함수
int chogi()
{
	gold = 4000;
	tp = 3;
	tpart = 1;
	year = 1;


	strcpy(m[0].mapname, "허창");
	m[0].civil = 10000;
	m[0].mind = 90;
	m[0].army = 500;
	m[0].power = 40;
	m[0].own = 1;
	m[0].tax = m[0].civil*m[0].mind / 3000;

	strcpy(m[1].mapname, "건업");
	m[1].civil = 20000;
	m[1].mind = 80;
	m[1].army = 1500;
	m[1].power = 55;
	m[1].own = 0;
	m[1].tax = m[1].civil*m[1].mind / 3000;

	strcpy(m[2].mapname, "성도");
	m[2].civil = 40000;
	m[2].mind = 70;
	m[2].army = 3000;
	m[2].power = 60;
	m[2].own = 0;
	m[2].tax = m[2].civil*m[2].mind / 3000;

	strcpy(m[3].mapname, "양양");
	m[3].civil = 80000;
	m[3].mind = 60;
	m[3].army = 7000;
	m[3].power = 65;
	m[3].own = 0;
	m[3].tax = m[3].civil*m[3].mind / 3000;

	strcpy(m[4].mapname, "낙양");
	m[4].civil = 160000;
	m[4].mind = 50;
	m[4].army = 15000;
	m[4].power = 70;
	m[4].own = 0;
	m[4].tax = m[4].civil*m[4].mind / 3000;

	strcpy(m[5].mapname, "신야");
	m[5].civil = 320000;
	m[5].mind = 40;
	m[5].army = 32000;
	m[5].power = 80;
	m[5].own = 0;
	m[5].tax = m[5].civil*m[5].mind / 3000;

	strcpy(m[6].mapname, "평원");
	m[6].civil = 640000;
	m[6].mind = 30;
	m[6].army = 100000;
	m[6].power = 90;
	m[6].own = 0;
	m[6].tax = m[6].civil*m[6].mind / 3000;

	strcpy(m[7].mapname, "천수");
	m[7].civil = 1280000;
	m[7].mind = 20;
	m[7].army = 300000;
	m[7].power = 100;
	m[7].own = 0;
	m[7].tax = m[7].civil*m[7].mind / 3000;

	strcpy(m[8].mapname, "북평");
	m[8].civil = 2560000;
	m[8].mind = 10;
	m[8].army = 700000;
	m[8].power = 110;
	m[8].own = 0;
	m[8].tax = m[8].civil*m[8].mind / 3000;

	return 0;
}

//(지역)정보 출력 함수
int infomation(void)
{
	mapguide();

	select = _getch();

	if (select == '1')
		select = 0;
	else if (select == '2')
		select = 1;
	else if (select == '3')
		select = 2;
	else if (select == '4')
		select = 3;
	else if (select == '5')
		select = 4;
	else if (select == '6')
		select = 5;
	else if (select == '7')
		select = 6;
	else if (select == '8')
		select = 7;
	else if (select == '9')
		select = 8;
	else
	{
		printf("   ▷ 잘못 입력 하셨습니다"); _getch();
		return 0;
	}

	if (m[select].own == 1)
	{
		printf("당신이 소유한 %s의 정보 입니다\n", m[select].mapname);
		printf("인  구 : %d\n", m[select].civil);
		printf("민  심 : %d\n", m[select].mind);
		printf("군  사 : %d\n", m[select].army);
		printf("훈련도 : %d\n", m[select].power);
		printf("세  금 : %d\n", m[select].tax);

	}
	else
		printf("   ▷ 당신의 지역이 아닙니다\n"); _getch();

	return 0;
}


//시간 경과 함수
int turnout(void)
{
	int i;
	system("cls");
	tp = 2;
	if (m[0].own == 1 && m[1].own == 1 && m[2].own == 1 && m[3].own == 1 && m[4].own == 1 && m[5].own == 1 && m[6].own == 1 && m[7].own == 1 && m[8].own == 1)
	{
		printf("      수고하셨습니다\n");
		printf("      당신은 드디어 천하를 통일하였습니다!!\n");
		printf("      백성들도 태평성대를 누리게 되었습니다.\n");
		printf("\n      당신은 난세의 영웅으로 영원히 기억될 것입니다.\n\n");
		printf("      아무키나 누르면 빠져 나갑니다.\n");
		_getch();
		exit(0);
	}

	if (year == 80)
	{
		printf("수명이 다했습니다\n");
		return 1;
	}


	if (tpart < 4)
	{
		printf("\n\n     ⊙ 다음 분기로 넘어갑니다");

		for (i = 0; i < 9; i++)
		{
			if (m[i].own == 1)
			{
				tp = tp + 1;
			}
		}
		tpart++;
		_getch();
		system("cls");

		return 0;
	}
	else
	{
		year++;
		tpart = 1;
		printf("\n\n     ⊙ 다음 해로 넘어갑니다\n\n\n");
		for (i = 0; i < 9; i++)
		{
			if (m[i].own == 1)
			{
				if (m[i].mind <= 20)
				{
					m[i].civil = m[i].civil - 1000;
					printf("    ◆ %s의 민심이 매우 흉흉해서 시민이 도망갑니다\n\n", m[i].mapname);
				}
				else if (m[i].mind <= 40)
				{
					m[i].civil = m[i].civil - 600;
					printf("    ◆ %s에서 나쁜 소문이 돌고 시민이 불안해 합니다\n\n", m[i].mapname);
				}
				else if (m[i].mind <= 60)
				{
					m[i].civil = m[i].civil - 300;
					printf("    ◆ %s의 민심이 별로 좋지 않은 듯 합니다.\n\n", m[i].mapname);
				}
				else if (m[i].mind <= 80)
				{
					printf("    ◆ %s에서 그럭저럭 백성들이 만족해 합니다.\n\n", m[i].mapname);
				}
				else if (m[i].mind <= 100)
				{
					m[i].civil = m[i].civil + 500;
					printf("    ◆ %s의 백성들이 평안해 합니다.\n\n", m[i].mapname);
				}
				else
				{
					m[i].civil = m[i].civil + 1000;
					printf("    ◆ %s의 백성들이 %s님을 매우 존경하고 따릅니다.\n\n", m[i].mapname, name);
				}

				if (m[i].civil < 0)
				{
					m[i].civil = 0;
				}

				gold = gold + m[i].tax;
				m[i].tax = m[i].civil*m[i].mind / 3000;
				tp = tp + 1;
			}
		}
		_getch();
		system("cls");
		return 0;
	}
	return 0;
}

//선택가능한 지역
int mapguide(void)
{
	int i, no = 1;


	printf("───────────────────────────────────────\n ");
	for (i = 0; i < 9; i++)
	{
		printf("%d>%s", no, m[i].mapname);
		no++;
		if (m[i].own == 1)
			printf("[가능]  ");
		else
			printf("  ");
	}
	printf("\n");
	printf("───────────────────────────────────────\n");

	return 0;
}


//전쟁 가능한 지역 출력
int wartarget(void)
{
	int i, no = 1, tarcnt = 0;

	printf("───────────────────────────────────────\n ");
	for (i = 0; i < 9; i++)
	{
		if (m[i].own == 1)
		{
			tarcnt++;
		}
	}

	for (i = 0; i < 9; i++)
	{
		printf("%d>%s", no, m[i].mapname);
		no++;
		if (i == tarcnt)
		{
			printf("[가능]  ");
		}
		else
			printf("  ");
	}
	printf("\n");
	printf("───────────────────────────────────────\n");


	return 0;
}

//전쟁 함수
int war(void)
{
	int mulpowme, mulpowtar;
	int i = 1, j, selme, seltar, mebar, tarbar, mefst, tarfst, tarcnt, wardly;

	if (tp < 2)
	{
		printf("   ▷ 행동력이 부족합니다"); _getch();
		return 0;
	}

	//출전 가능한 곳 출력
	printf("\n   ▷ 출전할 지역을 선택하세요\n");
	mapguide();
	selme = _getch();

	if (selme == '1')
		selme = 0;
	else if (selme == '2')
		selme = 1;
	else if (selme == '3')
		selme = 2;
	else if (selme == '4')
		selme = 3;
	else if (selme == '5')
		selme = 4;
	else if (selme == '6')
		selme = 5;
	else if (selme == '7')
		selme = 6;
	else if (selme == '8')
		selme = 7;
	else if (selme == '9')
		selme = 8;
	else
	{
		printf("   ▷ 잘못 입력 하셨습니다"); _getch();
		return 0;
	}

	if (m[selme].own == 1)
	{
		printf("   ▷ %s에서 출전 합니다\n", m[selme].mapname);
	}
	else
	{
		printf("   ▷ 당신의 지역이 아닙니다\n"); _getch();
		return 0;
	}




	//공격가능한 곳 출력
	printf("\n   ▷ 공격할 지역을 선택하세요\n");
	wartarget();
	seltar = _getch();
	if (seltar == '1')
		seltar = 0;
	else if (seltar == '2')
		seltar = 1;
	else if (seltar == '3')
		seltar = 2;
	else if (seltar == '4')
		seltar = 3;
	else if (seltar == '5')
		seltar = 4;
	else if (seltar == '6')
		seltar = 5;
	else if (seltar == '7')
		seltar = 6;
	else if (seltar == '8')
		seltar = 7;
	else if (seltar == '9')
		seltar = 8;
	else
	{
		printf("   ▷ 잘못 입력 하셨습니다"); _getch();
		return 0;
	}

	tarcnt = 0;

	for (i = 0; i < 9; i++)
	{
		if (m[i].own == 1)
		{
			tarcnt++;
		}
	}

	if (seltar < tarcnt)
	{
		printf("   ▷ 자신의 지역 입니다\n"); _getch();
		return 0;
	}

	if (m[seltar - 1].own == 1)
	{
		printf("   ▷ %s으로 출전 합니다\n", m[seltar].mapname);
		_getch();
	}
	else
	{
		printf("   ▷ 출전 가능한 지역이 아닙니다\n"); _getch();
		return 0;
	}

	tp = tp - 2;// 행동력 감수
	//초기값 저장
	mebar = m[selme].army / 10;
	tarbar = m[seltar].army / 10;
	mefst = m[selme].army;
	tarfst = m[seltar].army;



	// 군사수가 100000 이상일 경우 전투가 느려지기 때문에 공격력을 배수로 높이는 방법으로 시간을 줄인다
	mulpowme = m[selme].power;
	mulpowtar = m[seltar].power;

	if (m[selme].army < m[seltar].army)
	{
		if (m[seltar].army >= 50000)
		{
			mulpowme = m[selme].power * 10;
			mulpowtar = m[seltar].power * 10;
		}
		else if (m[seltar].army >= 100000)
		{
			mulpowme = m[selme].power * 70;
			mulpowtar = m[seltar].power * 70;
		}


	}
	else if (m[selme].army > m[seltar].army)
	{
		if (m[selme].army >= 50000)
		{
			mulpowme = m[selme].power * 10;
			mulpowtar = m[seltar].power * 10;
		}
		else if (m[seltar].army >= 100000)
		{
			mulpowme = m[selme].power * 70;
			mulpowtar = m[seltar].power * 70;
		}

	}


	//전쟁이 이루어 지는 부분
	while (1)
	{
		system("cls");
		printf("\n\n");
		printf("   [ %6s ]  ", name);

		m[selme].army = m[selme].army - mulpowtar;
		if (m[selme].army < 1)
		{
			m[selme].army = 0;
		}

		m[seltar].army = m[seltar].army - mulpowme;
		if (m[seltar].army < 1)
		{
			m[seltar].army = 0;
		}

		for (j = 0; j < m[selme].army; j = j + mebar)
		{

			printf("■");
		}
		printf("\n");

		printf("           [%d/%d]\n", m[selme].army, mefst);

		printf("   [     적 ]  ");

		for (j = 0; j < m[seltar].army; j = j + tarbar)
		{
			printf("■");
		}
		printf("\n");

		printf("           [%d/%d]\n", m[seltar].army, tarfst);

		//딜레이
		wardly = 350000 / tarfst;
		if (wardly < 10)
		{
			wardly = 1;
		}
		delay(wardly);

		//전쟁 결과
		if (m[selme].army < 1)
		{
			printf("졌습니다"); _getch();
			return 0;
		}

		if (m[seltar].army < 1)
		{
			printf("이겼습니다"); _getch();
			m[seltar].own = 1;
			return 0;
		}
	}
	return 0;
}

void delay(clock_t sleep)
{
	clock_t cur = clock(), el;


	for (;;) {              /* 무한루프를 돌린다. */
		el = clock();  /* 현재까지 프로그램이 실행된 TICK */
		if ((el - cur) > sleep)
			break;
	}
}

//---------------------------------------------------------------------------

