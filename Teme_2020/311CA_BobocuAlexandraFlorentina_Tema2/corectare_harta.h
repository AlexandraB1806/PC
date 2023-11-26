//311CA_Bobocu_Alexandra-Florentina
#include <stdio.h>
#include <stdlib.h>

void modificare(int *m, int **a)
{
	int linie, index_date, j, portiune;
	char tip, golire;
	scanf("%c", &golire); // golesc buffer-ul
	scanf("%c", &tip);
	scanf("%d %d", &linie, &index_date);
	if (tip == 'I') {
		int nr, *bit, *bit_nou;
		scanf("%X", &nr); // valoarea cu care modific elementul matricei
		if (index_date > m[linie]) { // verific daca aloc memorie in plus
			a[linie] = (int *)realloc(a[linie], index_date * sizeof(int));
			for (j = m[linie]; j < index_date; j++)
				a[linie][j] = 0;
			m[linie] = index_date; // actualizez dimensiunea liniei
		}
		bit = (int *)&a[linie][index_date - 1]; // leg bitul de elementul in
		// care vreau sa fac inlocuirea
		bit_nou = (int *)&nr; // selectez ultimul byte din noul numar
		bit[0] = bit_nou[0];
	} else if (tip == 'S') {
		int nr;
		short *bit, *bit_nou;
		scanf("%X", &nr); // valoarea cu care modific elementul matricei
		if (index_date % 2 == 0) { // verific sa nu ma mut pe urmatorul short
			if (index_date > m[linie] * 2) { // verific daca mai aloc memorie
				portiune = index_date / 2;
				a[linie] = (int *)realloc(a[linie], portiune * sizeof(int));
				for (j = m[linie]; j < index_date / 2; j++)
					a[linie][j] = 0;
				m[linie] = index_date / 2; // actualizez dimensiunea liniei
			}
			bit = (short *)&a[linie][index_date / 2 - 1];
		} else {
			if (index_date > m[linie] * 2) {
				portiune = index_date / 2 + 1;
				a[linie] = (int *)realloc(a[linie], portiune * sizeof(int));
				for (j = m[linie]; j < index_date / 2 + 1; j++)
					a[linie][j] = 0;
				m[linie] = index_date / 2 + 1;
			}
			bit = (short *)&a[linie][index_date / 2];
		}
		bit_nou = (short *)&nr; // selectez ultimul byte din noul numar
		if (index_date % 2 == 0)
			bit[1] = bit_nou[0];
		else
			bit[0] = bit_nou[0];
	} else if (tip == 'C') {
		int nr;
		char *bit, *bit_nou;
		scanf("%X", &nr); // valoarea cu care modific elementul matricei
		if (index_date % 4 == 0) { //verific sa nu sara pe urmatorul int
			if (index_date > m[linie] * 4) { // verific daca mai aloc memorie
				portiune = index_date / 4;
				a[linie] = (int *)realloc(a[linie], portiune * sizeof(int));
				for (j = m[linie]; j < index_date / 4; j++)
					a[linie][j] = 0;
				m[linie] = index_date / 4;
			}
			bit = (char *)&a[linie][index_date / 4 - 1];
		} else {
			if (index_date > m[linie] * 4) {
				portiune = index_date / 4 + 1;
				a[linie] = (int *)realloc(a[linie], portiune * sizeof(int));
				for (j = m[linie]; j < index_date / 4 + 1; j++)
					a[linie][j] = 0;
				m[linie] = index_date / 4 + 1;
			}
			bit = (char *)&a[linie][index_date / 4];
		}
		bit_nou = (char *)&nr; // selectez ultimul byte din noul numar
		if (index_date % 4 == 0)
			bit[3] = bit_nou[0];
		else if (index_date % 4 == 1)
			bit[0] = bit_nou[0];
		else if (index_date % 4 == 2)
			bit[1] = bit_nou[0];
		else
			bit[2] = bit_nou[0];
	}
}

void interschimbare(int **a)
{
	int linie, index_date;
	char tip, golire;
	scanf("%c", &golire); // citesc o valoare reziduala sa golesc buffer-ul
	scanf("%c", &tip);
	scanf("%d %d", &linie, &index_date);

	if (tip == 'I') {
		char *bit, aux;
		bit = (char *)&a[linie][index_date];
		aux = bit[0];
		bit[0] = bit[3];
		bit[3] = aux;
		aux = bit[1];
		bit[1] = bit[2];
		bit[2] = aux;
	} else if (tip == 'S') {
		char *bit, aux;
		short *bitt;
		bitt = (short *)&a[linie][index_date / 2]; // impart int-ul in short
		bit = (char *)&bitt[index_date % 2]; // aleg shortul potrivit si il
		// separ in 2 bytes ca sa fac interschimbarea
		aux = bit[0];
		bit[0] = bit[1];
		bit[1] = aux;
	}
}

void stergere(int **a)
{
	int linie, index_date;
	char tip, golire;
	scanf("%c", &golire); // golesc buffer-ul
	scanf("%c", &tip);
	scanf("%d %d", &linie, &index_date);

	if (tip == 'I') {
		int *bit;
		bit = (int *)&a[linie][index_date - 1];
		bit[0] = 0;
	} else if (tip == 'S') {
		short *bit;
		if (index_date % 2 == 0)
			bit = (short *)&a[linie][index_date / 2 - 1];
		else
			bit = (short *)&a[linie][index_date / 2];
		if (index_date % 2 == 0)
			bit[1] = 0;
		else
			bit[0] = 0;
	} else if (tip == 'C') {
		char *bit;

		if (index_date % 4 == 0)
			bit = (char *)&a[linie][index_date / 4 - 1];
		else
			bit = (char *)&a[linie][index_date / 4];
		if (index_date % 4 == 0)
			bit[3] = 0;
		else if (index_date % 4 == 1)
			bit[0] = 0;
		else if (index_date % 4 == 2)
			bit[1] = 0;
		else
			bit[2] = 0;
	}
}
