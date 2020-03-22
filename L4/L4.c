//6. Sa se realizeze un program care realizeaza suma a doua
//numerelor intr - o metoda separate de metoda main, iar aceea
//metoda returneaza un pointer.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int* suma(int a, int b)
{
	int *s = NULL;
	s = (int*)malloc(sizeof(int));
	*s = 0;
	*s = a + b;
	return s;
}

int main()
{
	int x, y;
	printf("primul numar: "); scanf("%d", &x);
	printf("al doilea numar: "); scanf("%d", &y);
	printf("Suma dintre %d si %d este %d\n", x, y, *suma(x,y));
	system("pause");
	return 0;
}
