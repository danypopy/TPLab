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
#define CAPACITATE 25 // setam capacitatea stivei.

int stack[CAPACITATE], top = -1; // declaram variabile globale stiva si varful stivei.

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
	if (top == CAPACITATE - 1) // verificam daca stiva este plina.
	{
		printf("Stiva este plina!\n");
	}
	else
	{
		stack[++top] = numar; // altfel adaugam elementul.
	}
}

int transformareBinar(int C, int N)
{
	int numar;
	for (int i = 0; i < N; i++) // luam un contor de la 0 la N.
	{
		printf("numar= ");
		scanf("%d", &numar); // citim cele "N" numere.
		if ((numar >> C) & 1 == 1) // daca numarul are pe bitul "C" 1.
			push(numar); // atunci se adauga numarul in stiva.
	}
}

void afisareStiva()
{
	int i = top; // luam un i egal cu numarul elementelor din stiva.
	while (i != -1) // cat timp stiva nu este goala.
	{
		printf("%d\n", stack[i]); // se afiseaza elementul de pe pozitia i.
		i--; // se scade pozitia i.
	}
}
