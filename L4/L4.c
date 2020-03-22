//6. Sa se realizeze un program care realizeaza suma a doua
//numerelor intr - o metoda separate de metoda main, iar aceea
//metoda returneaza un pointer.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int* suma(int a, int b)
{
	int s = 0;
	s = a + b;
	return s;
}

int main()
{
	int x, y, * s;
	s = (int*)malloc(sizeof(int));
	printf("primul numar: "); scanf("%d", &x);
	printf("al doilea numar: "); scanf("%d", &y);
	s = suma(x, y);
	printf("Suma dintre %d si %d este %d\n", x, y, s);
	system("pause");
	return 0;
}
