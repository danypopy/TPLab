//6. Se citeste de la tastatura un numar zecimal pâna în 255. Sa
//se Înscrie într - o stiva reprezentarea sa binara.Sa se
//genereze pe stack cea mai mare valoarea posibila.
//A) Sa se implementeze citirea conditionata pâna la 255.
//B) Sa se realizeze transformarea din zecimal în binar.
//C) Adaugarea fiecarui bit într - o stiva
//D) Sa se genereze valoarea maxima posibila din valorile de
//pe stiva.
//27 -> 0001 1011 (val binara) – Stack initial
//1111 0000 – Valoarea maxima
//5 -> 0000 0101 (val binara) – Stack initial
//1100 0000 – Valoarea maxima

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define CAPACITATE 50 //setam capacitatea stivei.

int stack[CAPACITATE], top = -1; //declaram variabile globale stiva si varful stivei.

int validareNumar();
void Push();
int transformareBinar();
void afisareStiva();
int contorizare();
int valoareMaximaBinar();

int main()
{
	int numar;
	numar = validareNumar();
	transformareBinar(numar);
	printf("\n\n");
	afisareStiva();
	printf("Valoarea maxima a numarului %d in forma binara este: %d.\n", numar, valoareMaximaBinar());
	system("pause");
	return 0;
}

int validareNumar()
{
	do {
		int x;
		printf("Introduceti un numar natural mai mic decat 255:\n"); scanf("%d", &x); // introducem numarul dorit.
		if (x >= 0 && x <= 255) // verificam daca numarul introdus este intre 0 si 255.
		{
			return x; // in caz afirmativ se returneaza valoarea introdusa.
			break; // si se opreste while-ul.
		}
		else 
		{
			printf("Reintroduceti un numar intre 0 si 255!\n"); // altfel se repeta while-ul.
		}
	} while (1);
}

void Push(int numar)
{
	if (top == CAPACITATE - 1) // verificam daca stiva este plina.
		printf("Stiva este plina.\n");
	else
		stack[++top] = numar; // altfel adaugam elementul.
}

int transformareBinar(int numar)
{
	for (int i = 0; i <= 7; i++) // luam un contor i care numara de la 0 la 7
	{
		Push((numar >> i) & 1); // se introduce in vector numarul introdus shiftat la dreapta cu i la care se efectueaza operatorul "si" cu 1.
	}
}

void afisareStiva()
{
	int i = top; // se egaleaza numarul elementelor din stiva cu i.
	while (i != -1) // cat timp stiva nu este goala.
	{
		printf("%d\n", stack[i]); // se afiseaza elementul de pe pozitia i.
		i--; // se scade pozitia.
	}
}

int contorizare()
{
	int cont = 0, i;
	i = top; // se egaleaza numarul elementelor din stiva cu i.
	while (i >= 0) // pentru a nu se ajunge ca stiva sa fie goala.
	{
		if (stack[i] == 1) // daca elementul de pe pozitia i este 1.
		{
			cont++; // se incrementeaza contorul.
		}
		i--; // se scade pozitia.
	}
	return cont; // la final se returneaza contorul.
}

int valoareMaximaBinar()
{
	int cont, dif10, laPutere = 1, maxim = 0;
	cont = contorizare(); // cont ia valoarea contorului.
	dif10 = top - cont + 1; // se calculeaza diferenta dintre 1 si 0.
	while (cont > 0) // cat timp contorul este mai mare decat 0.
	{
		maxim = maxim * 10 + 1; // maximul se inmulteste cu 10 si se aduna cu 1.
		cont--; // se scade contorul.
	}
	while (dif10 > 0) // cat timp dif10 este mai mare decat 0.
	{
		laPutere = laPutere * 10; // creste puterea.
		dif10--; // se scade diferenta.
	}
	maxim = maxim * laPutere; // se creaza maximul.
}