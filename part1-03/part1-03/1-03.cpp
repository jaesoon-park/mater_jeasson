#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x = 0;
	int y = 0;
	int swap;
	int dump;
	
	
	do {
		
		printf("교환할 두 정수를 입력하세요. >> ");
		scanf("%d %d", &x, &y);
		printf("입력한 두 수 : x = %d and y = %d", x, y);

		puts("");
		puts("");

		printf("\n 종료를 원할시       이용방법[0]");
		printf("\n 임시 저장 장소      이용방법[1]");
		printf("\n 덧셈과 뺄셈으로     교환방법[2]");
		printf("\n 곱셈과 나눗셈으로   교환방법[3]");
		printf("\n XOR 연산자 ^        이용방법[4]");

		puts("");
		puts("");

		printf("위 교환 방법 중 한 번호를 선택하세요. >> ");
		scanf("%d", &swap);

		puts("");
		puts("");

		if (swap == 1) {
			
			dump = x;
			x = y;
			y = dump;

			printf("교환한 두 수 : x = %d and y = %d", x, y);
			puts("");
			puts("");
		}

		else if (swap == 2) {
			
			x = x + y;
			y = x - y;//[ (x + y) - y]
			x = x - y;//[ (x + y) - x]

			printf("교환한 두 수 : x = %d and y = %d", x, y);
			puts("");
			puts("");
		}

		else if (swap == 3) {
			
			x = x * y;
			y = x / y;//[ (x * y) / y]
			x = x / y;//[ (x * y) / x]

			printf("교환한 두 수 : x = %d and y = %d", x, y);
			puts("");
			puts("");
		}

		else if (swap == 4) {
			
			x = x ^ y;
			y = x ^ y;//[ (x ^ y) ^ y ] == [ x ^ (y ^ y) ] == [ x ^ 0 ] == [x]
			x = x ^ y;//[ (x ^ y) ^ x ] == [ (y ^ x) ^ x ] == [ y ^ (x ^ x) ] == [ y ^ 0] == [y]

			printf("교환한 두 수 : x = %d and y = %d", x, y);
			puts("");
			puts("");
		}

		else if (swap == 0) {
			
			printf("종료");
			break;
		}
	
	} while (1);

}