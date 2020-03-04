#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

void cautare_binara(int sir[], int lungime, int numar_cautat)
{
	int primul, ultimul, mijloc;
	primul = 0;
	ultimul = lungime - 1;
	mijloc = (primul + ultimul) / 2;

	while (primul <= ultimul)
	{
		if (sir[mijloc] < numar_cautat)
		{
			primul = mijloc + 1;
		}
		else if (sir[mijloc] == numar_cautat)
		{
			printf("Numarul %d se afla pe pozitia %d.\n", numar_cautat, mijloc + 1);
			break;
		}
		else
		{
			ultimul = mijloc - 1;
		}

		mijloc = (primul + ultimul) / 2;
	}

	if (primul > ultimul)
	{
		printf("Numarul %d nu se afla in vector", numar_cautat);
	}
}

void cautare_liniara(int v[], int lungime, int numar_cautat)
{
	int i, gasit = 0;
	for (i = 0; i < lungime; i++)
	{
		if (v[i] == numar_cautat)
		{
			printf("Numarul %d a fost gasit pe pozitia %d.\n", numar_cautat, i + 1);
			gasit = 1;
		}
	}

	if (gasit == 0)
	{
		printf("Numarul nu se afla in vector.\n");
	}
}

void sortare(int v[], int lungime)
{
	int k, i, j, aux;
	do
	{
		k = 1;
		for (j = 1; j < lungime; j++)
		{
			if (v[j - 1] > v[j])
			{
				aux = v[j - 1];
				v[j - 1] = v[j];
				v[j] = aux;
				k = 0;
			}
		}

	} while (k == 0);
	for (i = 0; i < lungime; i++)
		printf("%d ", v[i]);
}

int main()
{
	int v[10], i, nr, n, optiune;
	printf("lungimea vectorului = "); scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("v[%d] = ", i+1); scanf("%d", &v[i]);
	}
	do {
		printf("\n0.Iesire\n");
		printf("1.Afisare vector\n");
		printf("2.Cautare liniara\n");
		printf("3.Cautare binara\n");
		printf("Alegeti o optiune: "); scanf("%d", &optiune);
		switch (optiune)
		{
		case 1:
			for (i = 0; i < n; i++)
				printf("%d ", v[i]);
			break;
		case 2:
			printf("Numarul pe care doriti sa il cautati: "); scanf("%d", &nr);
			cautare_liniara(v, n, nr);
			break;
		case 3:
			printf("Numarul pe care doriti sa il cautati: "); scanf("%d", &nr);
			printf("Vectorul sortat: ");
			sortare(v, n);
			cautare_binara(v, n, nr);
			break;
		case 0:
			exit(0);
			break;
		default:
			printf("Optiune gresita!");
			break;
		}
	} while (1);
	system("pause");
	return 0;
}