#include <stdio.h>
#include <math.h>
#define MAX 7

int main()
{
	int i, j;

	for (i = 0; i <= MAX; i++) {
		for (j = MAX; j >= -MAX; j--) {
			if (abs(j) > i)  {//abs ���밪
				putchar(' ');//����
			}
			else
			{
				printf("%d", abs(j));
			}
			
		}
		putchar('\n');
	}
}