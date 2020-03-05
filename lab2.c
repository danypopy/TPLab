#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// A	B	A&B		A|B		A^B
// 0	0	 0		 0		 0
// 0	1	 0		 1		 1
// 1	0	 0		 1		 1
// 1	1    1		 1	     0

//1.Fiind necesară setarea / verificarea permisiunilor pentru utilizatorii
//unei aplicații, și presupunând că informațiile legate de permisiune(per
//utilizator) pot fi salvate doar într - o variabilă de dimeniunea unui octet
//(limitări de memorie), să se implementeze funcții pentru setarea și
//verificarea permisiunilor unui anumit utilizator.Există 5 tipuri de
//permisiuni : Read / Write / Delete / Rename / Copy

int main()
{
	int a[15], optiune, opt, i=0, j;
	for (j = 0; j < 15; j++)
		a[j] = 0;
	do {
		printf("\n0.Iesire\n");
		printf("1.Adaugare permisiuni\n");
		printf("2.Afisarea permisiunilor utilizatorilor\n");
		printf("Alegeti optiunea: "); scanf("%d", &optiune);
		switch (optiune)
		{
		case 0:
			exit(0);
			break;
		case 1:
			printf("Adaugati permisiuni utilizatorului %d\n", i + 1);
			printf("Read: "); scanf("%d", &opt); 
			if (opt == 1)
				a[i] = a[i] + 16; //setam 1 pe bitul 3, daca permitem functia Read.
			printf("Write: "); scanf("%d", &opt);
			if (opt == 1)
				a[i] = a[i] + 8; //setam 1 pe bitul 3, daca permitem functia Write.
			printf("Delete: "); scanf("%d", &opt);
			if (opt == 1)
				a[i] = a[i] + 4; //setam 1 pe bitul 2, daca permitem functia Delete.
			printf("Rename: "); scanf("%d", &opt);
			if (opt == 1)
				a[i] = a[i] + 2; //setam 1 pe bitul 1, daca permitem functia Rename.
			printf("Copy: "); scanf("%d", &opt);
			if (opt == 1)
				a[i] = a[i] + 1; //setam 1 pe bitul 0, daca permitem functia Copy.
			i++;
			break;
		case 2:
			for (j = 0; j < i; j++)
			{
				printf("Utilizatorul %d are permisiunile: \n", j + 1);
				printf("Read: "); 
				if ((a[j] >> 4) % 2 == 1)
					printf("da\n");
				else
					printf("nu\n");
				printf("Write: ");
				if ((a[j] >> 3) % 2 == 1)
					printf("da\n");
				else
					printf("nu\n");
				printf("Delete: ");
				if ((a[j] >> 2) % 2 == 1)
					printf("da\n");
				else
					printf("nu\n");
				printf("Rename: ");
				if ((a[j] >> 1) % 2 == 1)
					printf("da\n");
				else
					printf("nu\n");
				printf("Copy: ");
				if ((a[j] >> 0) % 2 == 1)
					printf("da\n");
				else
					printf("nu\n");
			}
			break;
		default:
			printf("Optiune gresita!\n");
			break;
		}
	} while (1);
	system("pause");
	return 0;
}