#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
	6.Se citeste de la tastatura un numar zecimal pana in 255. Sa se afiseze forma binara a numarului iar apoi din sirul binar sa se genereze valoarea maxima:
27 -> 0001 1011 (val binara)	1111 0000 – Valoarea maxima
5 -> 0000 0101 (val binara)		1100 0000 – Valoarea maxima
*/

void transformare_baza(int numar)
{
    int sir_binar[8], i, j, maxim, maximum[8], aux =0;
    maxim = numar;
    for (i = 0; i < 8; i++)
        sir_binar[i] = 0;
    i = 0;
    while (numar > 0)
    {
        sir_binar[i] = numar % 2;
        numar = numar / 2;
        i++;
    }
    for (i = 7; i >= 0; i--)
        printf("%d", sir_binar[i]);
    printf("\n");
}

int Contor1(int numar)
{
    int contor = 0;
    while (numar)
    {
        if (numar % 2 == 1)
        {
            contor++;
        }
        numar = numar / 2;
    }
    return contor;
}

int GenerareMaxim(int numar)
{
    int i, n = 0;
    for (i = 0; i < numar; i++)
    {
        n = n | (1 << (7 - i));
    }
    return n;
}

int main()
{
    int numar, val_maxim, contor, optiune;
    do {
        printf("\n0.Iesire\n");
        printf("1.Transformare din zecimal in binar si generarea valorii maxime a sirului binar\n");
        printf("Alegeti o optiune: "); scanf("%d", &optiune);
        switch (optiune)
        {
        case 0:
            exit(0);
            break;
        case 1:
            printf("Introduceti numarul pe care doriti sa il aduceti la forma binara: "); scanf("%d", &numar);
            printf("%d -> ", numar);
            transformare_baza(numar);
            contor = Contor1(numar);
            val_maxim = GenerareMaxim(contor);
            printf("Valoarea maxima a sirului binar este:\n");
            printf("%d -> ", val_maxim);
            transformare_baza(val_maxim);
            break;
        default:
            printf("Optiune gresita!\n");
            break;
        }
    } while (1);
	system("pause");
	return 0;
}
