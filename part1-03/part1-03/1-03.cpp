#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x = 0;
	int y = 0;
	int swap;
	int dump;
	
	
	do {
		
		printf("��ȯ�� �� ������ �Է��ϼ���. >> ");
		scanf("%d %d", &x, &y);
		printf("�Է��� �� �� : x = %d and y = %d", x, y);

		puts("");
		puts("");

		printf("\n ���Ḧ ���ҽ�       �̿���[0]");
		printf("\n �ӽ� ���� ���      �̿���[1]");
		printf("\n ������ ��������     ��ȯ���[2]");
		printf("\n ������ ����������   ��ȯ���[3]");
		printf("\n XOR ������ ^        �̿���[4]");

		puts("");
		puts("");

		printf("�� ��ȯ ��� �� �� ��ȣ�� �����ϼ���. >> ");
		scanf("%d", &swap);

		puts("");
		puts("");

		if (swap == 1) {
			
			dump = x;
			x = y;
			y = dump;

			printf("��ȯ�� �� �� : x = %d and y = %d", x, y);
			puts("");
			puts("");
		}

		else if (swap == 2) {
			
			x = x + y;
			y = x - y;//[ (x + y) - y]
			x = x - y;//[ (x + y) - x]

			printf("��ȯ�� �� �� : x = %d and y = %d", x, y);
			puts("");
			puts("");
		}

		else if (swap == 3) {
			
			x = x * y;
			y = x / y;//[ (x * y) / y]
			x = x / y;//[ (x * y) / x]

			printf("��ȯ�� �� �� : x = %d and y = %d", x, y);
			puts("");
			puts("");
		}

		else if (swap == 4) {
			
			x = x ^ y;
			y = x ^ y;//[ (x ^ y) ^ y ] == [ x ^ (y ^ y) ] == [ x ^ 0 ] == [x]
			x = x ^ y;//[ (x ^ y) ^ x ] == [ (y ^ x) ^ x ] == [ y ^ (x ^ x) ] == [ y ^ 0] == [y]

			printf("��ȯ�� �� �� : x = %d and y = %d", x, y);
			puts("");
			puts("");
		}

		else if (swap == 0) {
			
			printf("����");
			break;
		}
	
	} while (1);

}