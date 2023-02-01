#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Red.h"


int main() {


	
	int ukStudenata = 0;
	int opcija;
	Cvor* lista = NULL;

	do {
		printf("\nMENI1:");
		printf("\n1 - Ucitavanje novog studenta");
		printf("\n0 - Kraj unosa studenata");
		printf("\nVas izbor: ");
		scanf("%d", &opcija);
		if (opcija == 1) {
			lista = dodajUListu(lista, &ukStudenata);
		}
	} while (opcija != 0);
	printf("\n\nUkupno ucitano %d studenata\n\n", ukStudenata);

	printf("\nMENI2:");
	printf("\n1 - Ubacivanje studenata u red");
	printf("\n0 - Kraj programa");
	printf("\nVas izbor: ");
	scanf("%d", &opcija);

	if (opcija == 0)
		system("exit");

	Red* red = kreirajRed();
	prebaciIzListeURed(&red, lista, ukStudenata);
	ispis(red);

	int br = 0;

	printf("\nMENI3:");
	printf("\n1 - Simulacija upisa");
	printf("\n0 - Kraj programa");
	printf("\nVas izbor: ");
	scanf("%d", &opcija);


	if (opcija == 0)
		system("exit");

	float prag;
	printf("\nUnesite prag za verovatnocu upisa [0, 0.5]: ");
	scanf("%f", &prag);

	while (velicina(red) != 0) {
		red = upis(red, prag, &br);
	}
	ispis(red);
	printf("\n\nBilo je potrebno %d koraka da se svi upisu", br);
	free(lista);
	free(red);
	printf("\n\n");
	system("pause");
	return 1;
}