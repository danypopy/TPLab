//1. Sa se scrie un program care calculeaza suma elementelor unui
//vector folosindu-ne doar de variabile de tip pointer.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* v, * i, * n, * s;
	n = (int*)malloc(sizeof(int));
	printf("Cate elemente sa aiba vectorul?\n"); scanf("%d", n);
	v = (int*)malloc((*n) * sizeof(int));
	s = (int*)malloc(sizeof(int));
	*s = 0;
	printf("Scrieti cele %d elemente ale vectorului\n", *n);
	for (i = v; i < v + (*n); i++)
	{
		scanf("%d", i);
		*s = *s + *i;
	}
	printf("Suma elementelor vectorului este: %d\n", *s);
	system("pause");
	return 0;
}
