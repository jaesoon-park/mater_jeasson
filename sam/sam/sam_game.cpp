//---------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h> //system("cls")�� ���� ���� �������
#include<conio.h> //getch()�� ���� ���� ��� ����
#include<string.h> //strcpy�� ���� ���� ��� ����
#include<process.h> //exit�� ���� ���� ��� ����
#include<time.h>

#pragma hdrstop

#include <tchar.h>
//---------------------------------------------------------------------------


//name�� ��� ���� ������ �����Ѵ�//
static char name[7];
static int select, mainroop = 1, type, gold = 2000, year = 1, tpart = 1, tp = 3;

struct MAP //���� ���� ����ü ����
{
	char mapname[10];
	int civil;
	int mind;
	int army;
	int power;
	int own;
	int tax;
};

struct MAP m[9]; //���� ������ ������������ü���� ����

void delay(clock_t sleep);//������ �Լ�


int intro(void); // ��Ʈ�� �޴�

int charmake(void); //ĳ���� ���� �Լ�

int inmilli(void); // �����Լ� (����,¡��,�Ʒ�)
int war(void); //�����Լ�
int wartarget(void); //������� �Լ�(�ܱ������� ����)
int jing(void); //¡���Լ�
int excer(void); //�Ʒ��Լ�

int ininjob(void); // �����Լ�(����,����)
int bokji(void); //�����Լ�
int gaibal(void); //�����Լ�

int inoutt(void); // �ܱ��Լ� (����ȥ��)
int armyfuse(void); //����ȥ���Լ�

int insystem(void); // �ý����������̽� �Լ�
int savegame(void);//���̺� �Լ�
int loadgame(void);//�ε� �Լ�

int inter(void); // ���ӳ� �������̽� �Լ�
int chogi(void); //���� ���� �Լ� �ʱ�ȭ �Լ�

int infomation(void);// �����Լ�
int mainmap(void); //�ʰ� ����� ������ �����ش�

int turnout(void); //�� ���� (�ð� ���)
int mapguide(void); //�ڽ��� ������ ������ �� �ְ� ���ش�

int _tmain(int argc, _TCHAR* argv[])
{

	//���� ���۽� �޴� �Լ� ȣ��//
	intro();

	//ĳ���� �����Լ��� �ҷ����δ�//
	charmake();

	//������ �ʱ�ȭ �Լ�
	chogi();

	//�������̽� �Լ� ȣ��//
	inter();

	return 0;
}

int intro(void)
{
	while (mainroop == 1)
	{
		system("cls");
		printf("\n\n");
		printf("                    ��������������������������������������\n");
		printf("                    ��             �ﱹ�� v0.1          ��\n");
		printf("                    ��������������������������������������\n\n\n");
		printf("               ������������������������������������������������\n");
		printf("               ��        [1]���ӽ���  [2]�ε�  [3]����       ��\n");
		printf("               ������������������������������������������������\n");

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

//ĳ���� ���� �Լ�//
int charmake(void)
{
	printf("\n\n  �� ����� �̸��� �Է��ϼ���(�ѱ� ������ ����) ��\n\n\n    ��");
	scanf("%6s", &name);

	system("cls");

	mainroop = 1;		//while�� ������ ���� mainroop�Լ��� �ʱ�ȭ �����ش�//
	while (mainroop == 1)
	{

		printf("\n\n  �� %s���� ������ �����ϼ��� ��\n\n", name);
		printf("       ��������������������\n");
		printf("       ��                ��\n");
		printf("       ��   [1] ������   ��\n");
		printf("       ��                ��\n");
		printf("       ��   [2] ������   ��\n");
		printf("       ��                ��\n");
		printf("       ��   [3] �ܱ���   ��\n");
		printf("       ��                ��\n");
		printf("       ��������������������\n");

		select = _getch();
		if (select == '1') {
			mainroop = 0; type = 1; printf("\n������ ĳ���͸� �����ϼ̽��ϴ�.\n"); _getch();
		}
		else if (select == '2') {
			mainroop = 0;
			type = 2; printf("\n������ Ưȭ�� ĳ���͸� �����ϼ̽��ϴ�.\n"); _getch();
		}
		else if (select == '3') {
			mainroop = 0; type = 3; printf("\n�ܱ����� �ɷ��� �پ ĳ���͸� �����ϼ̽��ϴ�.\n"); _getch();
		}
		else if (select == '4') {
			mainroop = 0; type = 4; printf("\n������ ĳ���� �Դϴ�.\n"); _getch();
		}
		else {
			printf("\nWrong keyword Press any key"); _getch();
		}
		system("cls");
	}
	return 0;
}



// ���� �������̽� �Լ�


// ���� ����
int inmilli(void)
{
	system("cls");
	printf("\n   ��������������������������������������������������������������������\n");
	printf("                     [%d��]   [%d/4�б�]   [�ൿġ %d]", year, tpart, tp);
	printf("\n   ��������������������������������������������������������������������\n");
	mainmap();
	printf("������������������������������������������������\n");
	printf("��   [1] ����  [2] ¡��  [3] �Ʒ�  [4] �ڷ�   ��\n");
	printf("������������������������������������������������\n");

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

//¡���Լ�
int jing(void)
{

	if (tp == 0)
	{
		printf("   �� �ൿ���� �����մϴ�"); _getch();
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
		printf("   �� �߸� �Է� �ϼ̽��ϴ�"); _getch();
		return 0;
	}
	if (m[select].mind < 10)
	{
		printf("   �� �ν��� �ʹ� �����ϴ�"); _getch();
		return 0;
	}
	if (m[select].civil < 1000)
	{
		printf("   �� �α��� �ʹ� �����ϴ�"); _getch();
		return 0;
	}



	if (m[select].own == 1)
	{
		if (gold >= 1000)
		{
			m[select].army = m[select].army + m[select].civil / 100;
			printf("   �� ���縦 ���� �մϴ�\n\n");
			gold = gold - 1000;
			printf("   �� ���� 1000�� �پ����ϴ�.\n");
			m[select].mind = m[select].mind - 10;
			printf("   �� �ν��� 10�پ����ϴ�!\n");
			m[select].civil = m[select].civil - 500;
			printf("   �� �α��� %d�پ����ϴ�!\n", m[select].civil / 100);
			m[select].army = m[select].army + 500;
			printf("   �� ���簡 %d�����߽��ϴ�!\n\n", m[select].civil / 100);

			m[select].civil = m[select].civil - m[select].civil / 100;

			printf("   �� %s�� ���簡 [%d]�Դϴ�\n", m[select].mapname, m[select].army);
			printf("   �� %s�� �ν��� [%d]�Դϴ�\n", m[select].mapname, m[select].mind);
			printf("   �� %s�� ���� [%d]�Դϴ�\n", m[select].mapname, gold);
			tp--;
			_getch();
		}
		else
		{
			printf("   �� ���� �����մϴ�\n");
			_getch();
		}
	}

	else
	{
		printf("   �� ����� ������ �ƴմϴ�\n");
		_getch();

	}
	return 0;
}
// �Ʒ��Լ�
int excer(void)
{
	if (tp == 0)
	{
		printf("   �� �ൿ���� �����մϴ�"); _getch();
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
		printf("   �� �߸� �Է� �ϼ̽��ϴ�"); _getch();
		return 0;
	}

	if (m[select].power == 400)
	{
		printf("   �� �ִ�ġ �Դϴ�"); _getch();
		return 0;
	}


	if (m[select].own == 1)
	{
		if (gold >= 500)
		{
			printf("   �� ���縦 �Ʒ� ��ŵ�ϴ�\n\n");
			gold = gold - 500;
			printf("   �� ���� 500�� �پ����ϴ�.\n");
			m[select].power = m[select].power + 5;
			printf("   �� �Ʒõ��� 5����߽��ϴ�!\n\n");
			printf("   �� %s�� �Ʒõ��� [%d]�Դϴ�\n", m[select].mapname, m[select].power);
			printf("   �� %s�� ���� [%d]�Դϴ�\n", m[select].mapname, gold);
			tp--;
			_getch();
		}
		else
		{
			printf("   �� ���� �����մϴ�\n");
			_getch();
		}
	}

	else
	{
		printf("   �� ����� ������ �ƴմϴ�\n");
		_getch();

	}
	return 0;
}

//���� ����
int ininjob(void)
{
	system("cls");
	printf("\n   ��������������������������������������������������������������������\n");
	printf("                     [%d��]   [%d/4�б�]   [�ൿġ %d]", year, tpart, tp);
	printf("\n   ��������������������������������������������������������������������\n");
	mainmap();
	printf("������������������������������������������������\n");
	printf("��         [1] ����  [2] ����  [3] �ڷ�       ��\n");
	printf("������������������������������������������������\n");

	select = _getch();
	if (select == '1')
		bokji();
	else if (select == '2')
		gaibal();
	else
		return 0;

	return 0;
}

//���� �Լ�
int bokji(void)
{
	if (tp == 0)
	{
		printf("   �� �ൿ���� �����մϴ�"); _getch();
		return 0;
	}
	printf("\n��� ���� ������ ���� �ϰڽ��ϱ�?\n");

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
		printf("   �� �߸� �Է� �ϼ̽��ϴ�"); _getch();
		return 0;
	}

	if (m[select].mind == 120)
	{
		printf("   �� �ִ�ġ �Դϴ�."); _getch();
		return 0;
	}

	if (m[select].own == 1)
	{
		if (gold >= 200)
		{
			printf("   �� ������ ���� �մϴ�\n\n");
			gold = gold - 200;
			printf("   �� ���� 200�� �پ����ϴ�.\n");
			m[select].mind = m[select].mind + 5;
			printf("   �� �ν��� +5�ö����ϴ�!\n\n");
			printf("   �� %s�� �ν��� [%d]�Դϴ�\n", m[select].mapname, m[select].mind);
			printf("   �� %s�� ���� [%d]�Դϴ�\n", m[select].mapname, gold);
			tp--;
			_getch();
		}
		else
		{
			printf("   �� ���� �����մϴ�\n");
			_getch();
		}
	}

	else
	{
		printf("   �� ����� ������ �ƴմϴ�\n");
		_getch();
	}
	return 0;
}


//���� �Լ�
int gaibal(void)
{
	if (tp == 0)
	{
		printf("   �� �ൿ���� �����մϴ�"); _getch();
		return 0;
	}

	if (gold < 1000)
	{
		printf("   �� ���� �����մϴ�"); _getch();
		return 0;
	}

	printf("\n��� ���� ������ ���� �ϰڽ��ϱ�?\n");

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
		printf("   �� �߸� �Է� �ϼ̽��ϴ�"); _getch();
		return 0;
	}
	if (m[select].own == 1)
	{
		if (gold >= 200)
		{
			printf("   �� ������ ���� �մϴ�\n\n");
			gold = gold - 1000;
			printf("   �� ���� 1000�� �پ����ϴ�.\n");
			m[select].civil = m[select].civil + 1000;
			printf("   �� �α��� +1000�ö����ϴ�!\n\n");
			printf("   �� %s�� �α��� [%d]�Դϴ�\n", m[select].mapname, m[select].civil);
			printf("   �� %s�� ���� [%d]�Դϴ�\n", m[select].mapname, gold);
			tp--;
			_getch();
		}
		else
		{
			printf("   �� ���� �����մϴ�\n");
			_getch();
		}
	}

	else
	{
		printf("   �� ����� ������ �ƴմϴ�\n");
		_getch();

	}
	return 0;
}
//�ܱ� �Լ�
int inoutt(void)
{
	system("cls");
	printf("\n   ��������������������������������������������������������������������\n");
	printf("                     [%d��]   [%d/4�б�]   [�ൿġ %d]", year, tpart, tp);
	printf("\n   ��������������������������������������������������������������������\n");
	mainmap();
	printf("������������������������������������������������\n");
	printf("��    [1] ����ȥ��                [2] �ڷ�    ��\n");
	printf("������������������������������������������������\n");

	select = _getch();
	if (select == '1')
	{
		armyfuse();
	}
	else
		return 0;

	return 0;
}
//���� ȥ�� �Լ�
int armyfuse(void)
{
	int i = 1, seltar, tarcnt;

	if (tp < 1)
	{
		printf("   �� �ൿ���� �����մϴ�"); _getch();
		return 0;
	}

	if (gold < 500)
	{
		printf("   �� �ڱ��� �����մϴ�"); _getch();
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
		printf("   �� �߸� �Է� �ϼ̽��ϴ�"); _getch();
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
		printf("   �� �ڽ��� ���� �Դϴ�\n"); _getch();
		return 0;
	}

	if (m[seltar - 1].own == 1)
	{
		printf("   �� %s�� ����ȥ���� �����մϴ�\n", m[seltar].mapname);
	}
	else
	{
		printf("   �� ���� ������ ������ �ƴմϴ�\n"); _getch();
		return 0;
	}

	m[seltar].power = m[seltar].power - 2;
	gold = gold - 500;
	tp--;
	printf("   �� �������� ��Ⱑ �ణ ���������ϴ�.\n");
	printf("   �� �ڱ��� %d�� �Ǿ����ϴ�\n", gold);
	_getch();
	return 0;
}

//�ý��� �޴� �Լ�
int insystem(void)
{
	mainroop = 1;
	while (mainroop == 1)
	{
		system("cls");
		printf("\n\n\n\n");
		printf(" 			     ������������������������\n");
		printf("			     ��                    ��\n");
		printf("			     ��   �� �� �� �� ��   ��\n");
		printf("			     ��                    ��\n");
		printf("			     ������������������������\n");
		printf("			     ��                    ��\n");
		printf("			     ��    [1] �� �� ��    ��\n");
		printf("			     ��                    ��\n");
		printf("			     ��    [2] ��    ��    ��\n");
		printf("			     ��                    ��\n");
		printf("	 		     ��    [3] ��    ��    ��\n");
		printf("			     ��                    ��\n");
		printf("			     ��    [4] ��������    ��\n");
		printf("			     ��                    ��\n");
		printf("			     ������������������������\n");

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
			printf("\n�����մϴ�\n");
			_getch();
			exit(0);
		}
		else if (select == '4')
		{
			printf("\n�������� ���ư��ϴ�\n");
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

int savegame(void) //���̺� �Լ�
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
	printf("                        ��������������������������\n");
	printf("                        ��                      ��\n");
	printf("                        ��       ���� ����      ��\n");
	printf("                        ��                      ��\n");
	printf("                        ��������������������������\n");
	printf("                        ��                      ��\n");
	printf("                        ��    [1 %6s SLOT]   ��\n", snm1);
	printf("                        ��                      ��\n");
	printf("                        ��    [2 %6s SLOT]   ��\n", snm2);
	printf("                        ��                      ��\n");
	printf("                        ��    [3 %6s SLOT]   ��\n", snm3);
	printf("                        ��                      ��\n");
	printf("                        ��������������������������\n");
	select = _getch();
	printf("������ �����մϴ�\n");

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

int loadgame(void) //�ε��Լ�
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
	printf("                        ��������������������������\n");
	printf("                        ��                      ��\n");
	printf("                        ��       ���� �ε�      ��\n");
	printf("                        ��                      ��\n");
	printf("                        ��������������������������\n");
	printf("                        ��                      ��\n");
	printf("                        ��    [1 %6s SLOT]   ��\n", snm1);
	printf("                        ��                      ��\n");
	printf("                        ��    [2 %6s SLOT]   ��\n", snm2);
	printf("                        ��                      ��\n");
	printf("                        ��    [3 %6s SLOT]   ��\n", snm3);
	printf("                        ��                      ��\n");
	printf("                        ��������������������������\n");
	select = _getch();


	if (select == '1')
	{
		if ((loadman = fopen("ssavman.s01", "r")) == NULL)
		{
			printf("����� ���� �����Ͱ� �����ϴ�\n"); _getch();
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
			printf("����� ���� �����Ͱ� �����ϴ�\n"); _getch();
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
			printf("����� ���� �����Ͱ� �����ϴ�\n"); _getch();
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
		printf("�߸� �����̽��ϴ�\n");
		_getch();
		return 1;
	}
	system("cls");
	return 0;

}

//���� �ʰ� ����� ���� ��� �Լ�
int mainmap(void)
{
	/*
	���������������������������������� ������������������������
	��                              �� ��                    ��
	��  O[��â]��O[�Ǿ�]��O[����]   �� �� ¯�ö�             ��
	��                       ��     �� ��                    ��
	��  O[�ž�]��O[����]��O[���]   �� �� 10000000000000 ��  ��
	��     ��                       �� ��                    ��
	��  O[���]��O[õ��]��O[����]   �� �� ������             ��
	��                              �� ��                    ��
	���������������������������������� ������������������������
	*/
	printf("\n");
	printf("    ���������������������������������� ��������������������������������\n");
	printf("    ��                              �� ��                            ��\n");
	printf("    ��         ����ü������         �� ��       ������ ������      ��\n");
	printf("    ��                              �� ��                            ��\n");
	printf("    ��  ");

	if (m[0].own == 1)
		printf("O");
	else if (m[0].own == 0)
		printf("X");
	printf("[%s]", m[0].mapname);

	printf("��");

	if (m[1].own == 1)
		printf("O");
	else if (m[1].own == 0)
		printf("X");
	printf("[%s]", m[1].mapname);

	printf("��");

	if (m[2].own == 1)
		printf("O");
	else if (m[2].own == 0)
		printf("X");
	printf("[%s]", m[2].mapname);

	printf("   �� �� [��  ��]  %11s      �� \n", name);
	printf("    ��                       ��     �� ��                            ��\n");
	printf("    ��  ");

	if (m[5].own == 1)
		printf("O");
	else if (m[5].own == 0)
		printf("X");
	printf("[%s]", m[5].mapname);

	printf("��");

	if (m[4].own == 1)
		printf("O");
	else if (m[4].own == 0)
		printf("X");
	printf("[%s]", m[4].mapname);

	printf("��");

	if (m[3].own == 1)
		printf("O");
	else if (m[3].own == 0)
		printf("X");
	printf("[%s]", m[3].mapname);

	printf("   �� �� [��  ��]  %11d      ��\n", gold);
	printf("    ��     ��                       �� ��                            ��\n");
	printf("    ��  ");

	if (m[6].own == 1)
		printf("O");
	else if (m[6].own == 0)
		printf("X");
	printf("[%s]", m[6].mapname);

	printf("��");

	if (m[7].own == 1)
		printf("O");
	else if (m[7].own == 0)
		printf("X");
	printf("[%s]", m[7].mapname);

	printf("��");

	if (m[8].own == 1)
		printf("O");
	else if (m[8].own == 0)
		printf("X");
	printf("[%s]", m[8].mapname);
	printf("   �� ��");
	if (type == 1)
	{
		printf(" [��  ��]       ������");
	}
	else if (type == 2)
	{
		printf(" [��  ��]       ������");
	}
	else if (type == 3)
	{
		printf(" [��  ��]       �ܱ���");
	}
	else if (type == 4)
	{
		printf(" [��  ��]       ������");
	}
	printf("      ��\n");
	printf("    ��                              �� ��                            ��\n");
	printf("    ���������������������������������� ��������������������������������");
	printf("\n  [ O : %s���� ���� | X : ���� ����]\n", name);
	printf("\n\n");

	return 0;
}

//����� �������̽� �Լ�//
int inter(void)
{
	mainroop = 1;
	while (mainroop == 1)
	{
		printf("\n   ��������������������������������������������������������������������\n");
		printf("                     [%d��]   [%d/4�б�]   [�ൿġ %d]", year, tpart, tp);
		printf("\n   ��������������������������������������������������������������������\n");
		mainmap();
		printf("��������������������������������������������������������������������������\n");
		printf("��   [1] ����  [2] ����  [3] �ܱ�  [4] �ý���  [5] ����  [6] �ð����   ��\n");
		printf("��������������������������������������������������������������������������\n");

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
				printf("\n   ����� õ�������� ���� ���ϰ� �ľ� �׾����ϴ�!!\n");
				printf("  õ�ϴ� ���� ������ ������ �Ѿ ���ΰ�?? \n");
				printf("\n �ƹ�Ű�� ������ ���� �����ϴ�.\n");
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

//�������� �ʱ�ȭ �Լ�
int chogi()
{
	gold = 4000;
	tp = 3;
	tpart = 1;
	year = 1;


	strcpy(m[0].mapname, "��â");
	m[0].civil = 10000;
	m[0].mind = 90;
	m[0].army = 500;
	m[0].power = 40;
	m[0].own = 1;
	m[0].tax = m[0].civil*m[0].mind / 3000;

	strcpy(m[1].mapname, "�Ǿ�");
	m[1].civil = 20000;
	m[1].mind = 80;
	m[1].army = 1500;
	m[1].power = 55;
	m[1].own = 0;
	m[1].tax = m[1].civil*m[1].mind / 3000;

	strcpy(m[2].mapname, "����");
	m[2].civil = 40000;
	m[2].mind = 70;
	m[2].army = 3000;
	m[2].power = 60;
	m[2].own = 0;
	m[2].tax = m[2].civil*m[2].mind / 3000;

	strcpy(m[3].mapname, "���");
	m[3].civil = 80000;
	m[3].mind = 60;
	m[3].army = 7000;
	m[3].power = 65;
	m[3].own = 0;
	m[3].tax = m[3].civil*m[3].mind / 3000;

	strcpy(m[4].mapname, "����");
	m[4].civil = 160000;
	m[4].mind = 50;
	m[4].army = 15000;
	m[4].power = 70;
	m[4].own = 0;
	m[4].tax = m[4].civil*m[4].mind / 3000;

	strcpy(m[5].mapname, "�ž�");
	m[5].civil = 320000;
	m[5].mind = 40;
	m[5].army = 32000;
	m[5].power = 80;
	m[5].own = 0;
	m[5].tax = m[5].civil*m[5].mind / 3000;

	strcpy(m[6].mapname, "���");
	m[6].civil = 640000;
	m[6].mind = 30;
	m[6].army = 100000;
	m[6].power = 90;
	m[6].own = 0;
	m[6].tax = m[6].civil*m[6].mind / 3000;

	strcpy(m[7].mapname, "õ��");
	m[7].civil = 1280000;
	m[7].mind = 20;
	m[7].army = 300000;
	m[7].power = 100;
	m[7].own = 0;
	m[7].tax = m[7].civil*m[7].mind / 3000;

	strcpy(m[8].mapname, "����");
	m[8].civil = 2560000;
	m[8].mind = 10;
	m[8].army = 700000;
	m[8].power = 110;
	m[8].own = 0;
	m[8].tax = m[8].civil*m[8].mind / 3000;

	return 0;
}

//(����)���� ��� �Լ�
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
		printf("   �� �߸� �Է� �ϼ̽��ϴ�"); _getch();
		return 0;
	}

	if (m[select].own == 1)
	{
		printf("����� ������ %s�� ���� �Դϴ�\n", m[select].mapname);
		printf("��  �� : %d\n", m[select].civil);
		printf("��  �� : %d\n", m[select].mind);
		printf("��  �� : %d\n", m[select].army);
		printf("�Ʒõ� : %d\n", m[select].power);
		printf("��  �� : %d\n", m[select].tax);

	}
	else
		printf("   �� ����� ������ �ƴմϴ�\n"); _getch();

	return 0;
}


//�ð� ��� �Լ�
int turnout(void)
{
	int i;
	system("cls");
	tp = 2;
	if (m[0].own == 1 && m[1].own == 1 && m[2].own == 1 && m[3].own == 1 && m[4].own == 1 && m[5].own == 1 && m[6].own == 1 && m[7].own == 1 && m[8].own == 1)
	{
		printf("      �����ϼ̽��ϴ�\n");
		printf("      ����� ���� õ�ϸ� �����Ͽ����ϴ�!!\n");
		printf("      �鼺�鵵 ���򼺴븦 ������ �Ǿ����ϴ�.\n");
		printf("\n      ����� ������ �������� ������ ���� ���Դϴ�.\n\n");
		printf("      �ƹ�Ű�� ������ ���� �����ϴ�.\n");
		_getch();
		exit(0);
	}

	if (year == 80)
	{
		printf("������ ���߽��ϴ�\n");
		return 1;
	}


	if (tpart < 4)
	{
		printf("\n\n     �� ���� �б�� �Ѿ�ϴ�");

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
		printf("\n\n     �� ���� �ط� �Ѿ�ϴ�\n\n\n");
		for (i = 0; i < 9; i++)
		{
			if (m[i].own == 1)
			{
				if (m[i].mind <= 20)
				{
					m[i].civil = m[i].civil - 1000;
					printf("    �� %s�� �ν��� �ſ� �����ؼ� �ù��� �������ϴ�\n\n", m[i].mapname);
				}
				else if (m[i].mind <= 40)
				{
					m[i].civil = m[i].civil - 600;
					printf("    �� %s���� ���� �ҹ��� ���� �ù��� �Ҿ��� �մϴ�\n\n", m[i].mapname);
				}
				else if (m[i].mind <= 60)
				{
					m[i].civil = m[i].civil - 300;
					printf("    �� %s�� �ν��� ���� ���� ���� �� �մϴ�.\n\n", m[i].mapname);
				}
				else if (m[i].mind <= 80)
				{
					printf("    �� %s���� �׷����� �鼺���� ������ �մϴ�.\n\n", m[i].mapname);
				}
				else if (m[i].mind <= 100)
				{
					m[i].civil = m[i].civil + 500;
					printf("    �� %s�� �鼺���� ����� �մϴ�.\n\n", m[i].mapname);
				}
				else
				{
					m[i].civil = m[i].civil + 1000;
					printf("    �� %s�� �鼺���� %s���� �ſ� �����ϰ� �����ϴ�.\n\n", m[i].mapname, name);
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

//���ð����� ����
int mapguide(void)
{
	int i, no = 1;


	printf("������������������������������������������������������������������������������\n ");
	for (i = 0; i < 9; i++)
	{
		printf("%d>%s", no, m[i].mapname);
		no++;
		if (m[i].own == 1)
			printf("[����]  ");
		else
			printf("  ");
	}
	printf("\n");
	printf("������������������������������������������������������������������������������\n");

	return 0;
}


//���� ������ ���� ���
int wartarget(void)
{
	int i, no = 1, tarcnt = 0;

	printf("������������������������������������������������������������������������������\n ");
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
			printf("[����]  ");
		}
		else
			printf("  ");
	}
	printf("\n");
	printf("������������������������������������������������������������������������������\n");


	return 0;
}

//���� �Լ�
int war(void)
{
	int mulpowme, mulpowtar;
	int i = 1, j, selme, seltar, mebar, tarbar, mefst, tarfst, tarcnt, wardly;

	if (tp < 2)
	{
		printf("   �� �ൿ���� �����մϴ�"); _getch();
		return 0;
	}

	//���� ������ �� ���
	printf("\n   �� ������ ������ �����ϼ���\n");
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
		printf("   �� �߸� �Է� �ϼ̽��ϴ�"); _getch();
		return 0;
	}

	if (m[selme].own == 1)
	{
		printf("   �� %s���� ���� �մϴ�\n", m[selme].mapname);
	}
	else
	{
		printf("   �� ����� ������ �ƴմϴ�\n"); _getch();
		return 0;
	}




	//���ݰ����� �� ���
	printf("\n   �� ������ ������ �����ϼ���\n");
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
		printf("   �� �߸� �Է� �ϼ̽��ϴ�"); _getch();
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
		printf("   �� �ڽ��� ���� �Դϴ�\n"); _getch();
		return 0;
	}

	if (m[seltar - 1].own == 1)
	{
		printf("   �� %s���� ���� �մϴ�\n", m[seltar].mapname);
		_getch();
	}
	else
	{
		printf("   �� ���� ������ ������ �ƴմϴ�\n"); _getch();
		return 0;
	}

	tp = tp - 2;// �ൿ�� ����
	//�ʱⰪ ����
	mebar = m[selme].army / 10;
	tarbar = m[seltar].army / 10;
	mefst = m[selme].army;
	tarfst = m[seltar].army;



	// ������� 100000 �̻��� ��� ������ �������� ������ ���ݷ��� ����� ���̴� ������� �ð��� ���δ�
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


	//������ �̷�� ���� �κ�
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

			printf("��");
		}
		printf("\n");

		printf("           [%d/%d]\n", m[selme].army, mefst);

		printf("   [     �� ]  ");

		for (j = 0; j < m[seltar].army; j = j + tarbar)
		{
			printf("��");
		}
		printf("\n");

		printf("           [%d/%d]\n", m[seltar].army, tarfst);

		//������
		wardly = 350000 / tarfst;
		if (wardly < 10)
		{
			wardly = 1;
		}
		delay(wardly);

		//���� ���
		if (m[selme].army < 1)
		{
			printf("�����ϴ�"); _getch();
			return 0;
		}

		if (m[seltar].army < 1)
		{
			printf("�̰���ϴ�"); _getch();
			m[seltar].own = 1;
			return 0;
		}
	}
	return 0;
}

void delay(clock_t sleep)
{
	clock_t cur = clock(), el;


	for (;;) {              /* ���ѷ����� ������. */
		el = clock();  /* ������� ���α׷��� ����� TICK */
		if ((el - cur) > sleep)
			break;
	}
}

//---------------------------------------------------------------------------

