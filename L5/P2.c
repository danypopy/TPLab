//2. Se citeste de la tastatura un numar C cu valori posibile
//intre 0 - 7. Dupa citirea numarului "C" se vor citi de la tastatura
//"N" numere iar acele numere care au reprezentarea lor
//binara, bitul de pe pozitia "C" cu valoare 1, vor fi introduse
//intr - o stiva.Sa se afiseze in final tot continutul stivei
//(indiferent de ordine)
//Ex:
//C = 2
//N = 5
//- Acum se citesc 5 numere :
//	1 2 3 4 5
//	- Se afiseaza la sfarsit
//	4 5
//	Deoarece 4 = 100 si 5 = 101, bitul de pe pozitia "2" este "1"

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define CAPACITATE 25

int stack[CAPACITATE], top = -1;

void push();
int transformareBinar();
void afisareStiva();

int main()
{
	int C, N;
	printf("C = ");
	scanf("%d", &C);
	printf("N = ");
	scanf("%d", &N);
	transformareBinar(C, N);
	printf("\n\n");
	afisareStiva();
	system("pause");
	return 0;
}

void push(int numar)
{
	if (top == CAPACITATE - 1)
	{
		printf("Stiva este plina!\n");
	}
	else
	{
		stack[++top] = numar;
	}
}

int transformareBinar(int C, int N)
{
	int numar;
	for (int i = 0; i < N; i++)
	{
		printf("numar= ");
		scanf("%d", &numar);
		if ((numar >> C) & 1 == 1)
			push(numar);
	}
}

void afisareStiva()
{
	int i = top;
	while (i != -1)
	{
		printf("%d\n", stack[i]);
		i--;
	}
}