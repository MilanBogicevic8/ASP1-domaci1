#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Skup.h"

int main() {

	Skup* niz[5] = { NULL, NULL, NULL, NULL, NULL };
	int n = 0;
	int opcija;

	do {
		printf("\n   *****     MENI\t*****");
		printf("\n________________________________");
		printf("\n\n1 - Ucitavanje novog skupa");
		printf("\n2 - Dodavanje novog clana skupu");
		printf("\n3 - Brisanje clana skupa");
		printf("\n4 - Ispis skupa");
		printf("\n5 - Sprovodjenje operacija skupa");
		printf("\n6 - Brisanje skupa");
		printf("\n0 - Kraj programa");
		printf("\n\nVas izbor: ");
		scanf("%d", &opcija);
		switch (opcija)
		{
		case 0:
			system("exit");
			break;
		case 1:
			if (n == 5)
				printf("\nVas program vec sadrzi 5 skupova, morate izbrisati neki kako biste mogli da kreirate novi !\n");
			else {
				niz[n] = kreirajSkup();
				n++;
				printf("\nNovi skup je uspesno kreiran, i smesten je na %d. mesto u nizu\n", n);
			}
			break;
		case 2: {
			if (n <= 0) {
				printf("\nMorate prvo kreirati makar jedan skup !\n");
				break;
			}
			int rb;
			printf("\nOdaberite skup kome zelite da dodate element:");
			for (int i = 1; i <= n; i++)
				printf(" S%d", i);
			printf("\nRedni broj skupa: ");
			scanf("%d", &rb);
			if (rb <= 0 || rb > n)
				printf("\nRedni broj skupa mora biti u opsegu od 1 do %d\n", n);
			else {
				int broj;
				printf("\nUnesite broj koji zelite da ubacite u skup: ");
				scanf("%d", &broj);
				niz[rb - 1] = dodajElementSkupu(niz[rb - 1], broj);
			}
			break;
		}
		case 3: {
			if (n <= 0) {
				printf("\nMorate prvo kreirati makar jedan skup !\n");
				break;
			}
			int rb;
			printf("\nOdaberite skup kome zelite da obrisete element:");
			for (int i = 1; i <= n; i++)
				printf(" S%d", i);
			printf("\nRedni broj skupa: ");
			scanf("%d", &rb);
			if (rb <= 0 || rb > n)
				printf("\nRedni broj skupa mora biti u opsegu od 1 do %d\n", n);
			else {
				int broj;
				printf("\nUnesite broj koji zelite da obristete iz skupa: ");
				scanf("%d", &broj);
				niz[rb - 1] = obrisiElement(niz[rb - 1], broj);
			}
			break;
		}
		case 4: {
			if (n <= 0) {
				printf("\nMorate prvo kreirati makar jedan skup !\n");
				break;
			}
			int rb;
			printf("\nOdaberite skup kome zelite da ispisete:");
			for (int i = 1; i <= n; i++)
				printf(" S%d", i);
			printf("\nRedni broj skupa: ");
			scanf("%d", &rb);
			if (rb <= 0 || rb > n)
				printf("\nRedni broj skupa mora biti u opsegu od 1 do %d\n", n);
			else {
				ispisSkupa(niz[rb - 1]);
			}
			break;
		}
		case 5: {
			printf("\n\nOdaberite operaciju:");
			printf("\n1 - Kardinalonst");
			printf("\n2 - Unija dva skupa");
			printf("\n3 - Presek dva skupa");
			printf("\n4 - Razlika dva skupa");
			printf("\n\nVas izbor: ");
			scanf("%d", &opcija);
			switch (opcija)
			{
			case 2: {
				int rb1, rb2;
				if (n == 5) {
					printf("\nNema slobodnih mesta za novi skup, prvo morate obrisati neki i osloboditi mesto !");
					break;
				}
				printf("Raspolozivi skupovi:");
				for (int i = 0; i < n; i++)
					printf(" S%d", i + 1);
				printf("\nUnesite redni broj prvog skupa: ");
				scanf("%d", &rb1);
				printf("\nUnesite redni broj drugog skupa: ");
				scanf("%d", &rb2);
				if (rb1 <= 0 || rb2 <= 0 || rb1>n || rb2 > n) {
					printf("Greska pri unosu rednog broja !");
					break;
				}
				niz[n] = unijaSkupova(niz[rb1 - 1], niz[rb2 - 1]);
				n++;
				break;
			}
			case 3: {
				if (n == 5) {
					printf("\nNema slobodnih mesta za novi skup, prvo morate obrisati neki i osloboditi mesto !");
					break;
				}
				int rb1, rb2;
				printf("Raspolozivi skupovi:");
				for (int i = 0; i < n; i++)
					printf(" S%d", i + 1);
				printf("\nUnesite redni broj prvog skupa: ");
				scanf("%d", &rb1);
				printf("\nUnesite redni broj drugog skupa: ");
				scanf("%d", &rb2);
				if (rb1 <= 0 || rb2 <= 0 || rb1>n || rb2 > n) {
					printf("Greska pri unosu rednog broja !");
					break;
				}
				niz[n] = presekSkupova(niz[rb1 - 1], niz[rb2 - 1]);
				n++;
				break;
			}
			case 4: {
				if (n == 5) {
					printf("\nNema slobodnih mesta za novi skup, prvo morate obrisati neki i osloboditi mesto !");
					break;
				}
				int rb1, rb2;
				printf("Raspolozivi skupovi:");
				for (int i = 0; i < n; i++)
					printf(" S%d", i + 1);
				printf("\nUnesite redni broj prvog skupa: ");
				scanf("%d", &rb1);
				printf("\nUnesite redni broj drugog skupa: ");
				scanf("%d", &rb2);
				if (rb1 <= 0 || rb2 <= 0 || rb1>n || rb2 > n) {
					printf("Greska pri unosu rednog broja !");
					break;
				}
				niz[n] = razlikaSkupova(niz[rb1 - 1], niz[rb2 - 1]);
				n++;
				break;
			}
			case 1: {
				int rb;
				printf("Raspolozivi skupovi:");
				for (int i = 0; i < n; i++)
					printf(" S%d", i + 1);
				printf("\nUnesite redni broj skupa: ");
				scanf("%d", &rb);
				if (rb <= 0 || rb > n) {
					printf("Greska pri unosu rednog broja !");
					break;
				}
				int k = kardinalnost(niz[rb - 1]);
				printf("\nKardinalnost skupa S%d je %d", rb, k);
				break;
			}
			}
				break;
		}
		case 6: {
			if (n <= 0) {
				printf("\nMorate prvo kreirati makar jedan skup !\n");
				break;
			}
			int rb;
			printf("\nOdaberite skup kome zelite da ispisete:");
			for (int i = 1; i <= n; i++)
				printf(" S%d", i);
			printf("\nRedni broj skupa: ");
			scanf("%d", &rb);
			if (rb <= 0 || rb > n)
				printf("\nRedni broj skupa mora biti u opsegu od 1 do %d\n", n);
			else {
				niz[rb - 1] = brisanjeSkupa(niz[rb - 1]);
				printf("\nSkup %d je uspesno obrisan", rb);
				bool pomeranje = false;
				for (int i = rb - 1; i < n - 1 && niz[i+1] != NULL; i++) {
					if (!pomeranje) {
						printf("\nDoslo je do sledeceg pomeranja:");
						pomeranje = true;
					}
					niz[i] = niz[i+1];
					printf("\nSkup %d je pomeren na poziciju %d", i+2, i+1);
				}
				n--;
				free(niz[n]);
				niz[n] = NULL;
				printf("\n");
			}
			break;
		}
		default:
			printf("\nUneta opcija mora biti u opsegu od 0 do 6 !");
			break;
		}
	} while (opcija != 0);

	for (int i = 0; i < n; i++) {
		niz[i] = brisanjeSkupa(niz[i]);
		free(niz[i]);
		niz[i] = NULL;
	}
	return 0;
}