#pragma once
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct cvor{
	int broj;
	struct cvor* sled;
	struct cvor* pret;
}Cvor;

typedef struct skup {
	Cvor* prvi;
}Skup;


Skup* kreirajSkup() {
	Skup* s = (Skup*)malloc(sizeof(Skup));
	s->prvi = NULL;
	return s;
}

bool pripadaSkupu(Skup* s, int broj) {
	Cvor* pom = s->prvi;
	while (pom != NULL) {
		if (pom->broj == broj)
			return true;
		pom = pom->sled;
	}
	return false;
}

int kardinalnost(Skup* s) {
	Cvor* pom = s->prvi;
	int brojac = 0;
	while (pom != NULL) {
		brojac++;
		pom = pom->sled;
	}
	return brojac;
}

Skup* dodajElementSkupu(Skup* s, int broj) {

	if (pripadaSkupu(s, broj)) {
		printf("\nBroj %d se vec nalazi u skupu !\n", broj);
		return s;
	}
	Cvor* novi = (Cvor*)malloc(sizeof(Cvor));
	novi->broj = broj;
	novi->sled = NULL;
	novi->pret = NULL;
	Cvor* pom = s->prvi;
	if (pom == NULL) {
		s->prvi = novi;
	}
	else if (pom->broj > broj) {
		novi->sled = pom;
		pom->pret = novi;
		s->prvi = novi;
	}
	else {
		while (pom->sled != NULL && pom->sled->broj < broj)
			pom = pom->sled;
		novi->sled = pom->sled;
		novi->pret = pom;
		pom->sled = novi;
		if(novi->sled != NULL)
			novi->sled->pret = novi;
	}
	return s;

}

Skup* obrisiElement(Skup* s, int broj) {
	if (!pripadaSkupu(s, broj)) {
		printf("\nElement %d ne pripada skupu!", broj);
		return s;
	}
	Cvor* pom = s->prvi;
	if (pom->broj == broj) {
		Cvor* stari = pom;
		s->prvi = pom->sled;
		if(s->prvi != NULL)
			s->prvi->pret = NULL;
		free(stari);
	}
	else {
		while (pom->sled != NULL && pom->sled->broj != broj)
			pom = pom->sled;
		Cvor* stari = pom->sled;
		pom->sled = stari->sled;
		if (pom->sled)
			pom->sled->pret = pom;
		free(stari);
	}
	return s;
}

void ispisSkupa(Skup* s) {
	if (s->prvi == NULL) {
		printf("\nSkup je prazan\n");
		return;
	}
	printf("\nSkup:");
	Cvor* pom = s->prvi;
	while (pom != NULL) {
		printf(" %d", pom->broj);
		pom = pom->sled;
	}
	printf("\n");
}

Skup* razlikaSkupova(Skup* s1, Skup* s2) {
	Skup* rez = kreirajSkup();
	Cvor* pom = s1->prvi;
	while (pom != NULL) {
		if (!pripadaSkupu(s2, pom->broj)) {
			rez = dodajElementSkupu(rez, pom->broj);
		}
		pom = pom->sled;
	}
	pom = s2->prvi;
	while (pom != NULL) {
		if (!pripadaSkupu(s1, pom->broj)) {
			rez = dodajElementSkupu(rez, pom->broj);
		}
		pom = pom->sled;
	}
	return rez;
}

Skup* presekSkupova(Skup* s1, Skup* s2) {
	Skup* rez = kreirajSkup();
	Cvor* pom = s1->prvi;
	while (pom != NULL) {
		if (pripadaSkupu(s2, pom->broj)) {
			rez = dodajElementSkupu(rez, pom->broj);
		}
		pom = pom->sled;
	}
	return rez;
}

Skup* unijaSkupova(Skup* s1, Skup* s2) {
	Skup* rez = kreirajSkup();
	Cvor* pom = s1->prvi;
	while (pom != NULL) {
		rez = dodajElementSkupu(rez, pom->broj);
		pom = pom->sled;
	}
	pom = s2->prvi;
	while (pom != NULL) {
		if (!pripadaSkupu(s1, pom->broj)) {
			rez = dodajElementSkupu(rez, pom->broj);
		}
		pom = pom->sled;
	}
	return rez;
}

Skup* brisanjeSkupa(Skup* s) {
	Cvor* pom = s->prvi;
	while (pom != NULL) {
		s = obrisiElement(s, pom->broj);
		ispisSkupa(s);
		pom = s->prvi;
	}
	s->prvi = pom;
	return s;
}