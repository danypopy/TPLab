//1. Sa se scrie un program care calculeaza suma elementelor unui
//vector folosindu-ne doar de variabile de tip pointer.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int v[50], i, n, *a, s=0;
	a = &v[0];
	printf("Cate elemente sa aiba vectorul?\n"); scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("v[%d]=", i+1); scanf("%d", &v[i]);
	}
	for (i = 0; i < n; i++)
	{
		s = s + *(a + i);
	}
	printf("Suma elementelor vectorului este: %d", s);
	system("pause");
	return 0;
}
