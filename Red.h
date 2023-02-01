#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


typedef struct student {
	char ime[20];
	char prezime[20];
	int index;
	int godina;
}Student;

typedef struct cvor {
	Student student;
	struct cvor* sled;
	struct cvor* pret;
}Cvor;

typedef struct red {
	Cvor* head;
	Cvor* tail;
}Red;

Cvor* dodajUListu(Cvor* head, int* ukS) {
	Student s;
	printf("\nUnesi ime studenta: ");
	scanf("%s", s.ime);
	printf("\nUnesi prezime studenta: ");
	scanf("%s", s.prezime);
	printf("\nUnesi trenutnu godinu studija studenta: ");
	scanf("%d", &s.godina);
	static int index = 0;
	s.index = ++index;
	Cvor* novi = (Cvor*)(malloc(sizeof(Cvor)));
	novi->student = s;
	novi->sled = head;
	novi->pret = NULL;
	if (head != NULL) {
		head->pret = novi;
	}
	head = novi;
	(*ukS)++;
	return head;
}

Cvor* obrisiIzListe(Cvor* head, Student s) {
	Cvor* stari;
	if (head->student.index == s.index) {
		stari = head;
		head = head->sled;
		if (head != NULL) {
			head->pret = NULL;
		}
		free(stari);
		return head;
	}
	else {
		Cvor* pom = head;
		while (pom->sled != NULL && pom->sled->student.index != s.index)
			pom = pom->sled;
		if (pom->sled == NULL) {
			printf("\nNe postoji student u listi!");
			return head;
		}
		else {
			stari = pom->sled;
			pom->sled = stari->sled;
			if (pom->sled != NULL) {
				pom->sled->pret = pom;
			}
			free(stari);
			return head;
		}
	}
}

Red* kreirajRed() {
	Red* red = (Red*)(malloc(sizeof(Red)));
	red->head = NULL;
	red->tail = NULL;
	return red;
}

Red* ubaciURed(Red* r, Student s) {
	Cvor* novi = (Cvor*)(malloc(sizeof(Cvor)));
	novi->student = s;
	novi->sled = NULL;
	novi->pret = NULL;
	if (r->tail == NULL) {
		r->head = novi;
		r->tail = novi;
	}
	else {
		r->tail->sled = novi;
		novi->pret = r->tail;
		r->tail = novi;
	}
	return r;
}

Student* izbaciIzReda(Red** r) {
	if ((*r)->head == NULL) {
		printf("\nRed je prazan !");
		return NULL;
	}
	else {
		Cvor* pom = (*r)->head;
		(*r)->head = (*r)->head->sled;
		if ((*r)->head == NULL) {
			(*r)->tail = NULL;
		}
		else {
			(*r)->head->pret = NULL;
		}
		Student s = pom->student;
		free(pom);
		return &s;
	}
}

int velicina(Red* r) {
	Cvor* pom = r->head;
	int brojac = 0;
	while (pom != NULL) {
		brojac++;
		pom = pom->sled;
	}
	return brojac;
}

bool redPrazan(Red* r) {
	if (r->head == NULL)
		return true;
	else
		return false;
}

bool redPun(Red *r, int n) {
	if (velicina(r) == n)
		return true;
	else
		return false;
}

void ispis(Red* r) {
	if (redPrazan(r)) {
		printf("\nRed je prazan!");
		return;
	}
	printf("\nRed (ime, prezime, index, godina):");
	Cvor* pom = r->head;
	while (pom != NULL) {
		printf("\n%s %s %d %d", pom->student.ime, pom->student.prezime, pom->student.index, pom->student.godina);
		pom = pom->sled;
	}
	printf("\n");
}

void prebaciIzListeURed(Red** red, Cvor* lst, int ukS) {
	srand(time(NULL));
	while (velicina(*red) != ukS) {
		int poz = rand() % (ukS - velicina(*red));
		int i = 0;
		Cvor* pom;
		Student s;
		for (pom = lst; pom != NULL; pom = pom->sled) {
			if (i == poz) {
				s = pom->student;
				lst = obrisiIzListe(lst, s);
				break;
			}
			i++;
		}
		*red = ubaciURed(*red, s);
	}
}

Red* upis(Red* r, float prag, int *br) {
	(*br)++;
	Student* s = izbaciIzReda(&r);
	float verovatnoca = ((float)rand() / (float)(RAND_MAX)) * 1;
	if (verovatnoca < prag) {
		r = ubaciURed(r, *s);
	}
	return r;
}