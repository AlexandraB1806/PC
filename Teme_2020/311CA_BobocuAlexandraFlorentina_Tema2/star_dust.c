//311CA_Bobocu_Alexandra-Florentina
#include <stdio.h>
#include <stdlib.h>
#include "corectare_harta.h"

double grad_incarcare(int n, int *m, int **a)
{
	int i, j, sum = 0, nr = 0;
	char *bit;
	// Adun bytes de pe marginea superioara
	for (j = 0; j < m[0]; j++) {
		bit = (char *)&a[0][j];
		sum = sum + bit[0] + bit[1] + bit[2] + bit[3];
		nr = nr + 4;
	}
	// Adun bytes de pe coloana din stanga
	for (i = 1; i < n - 1; i++) {
		bit = (char *)&a[i][0];
		sum = sum + bit[0];
		nr++;
	}
	// Adun bytes de pe marginea inferioara
	for (j = 0; j < m[n - 1]; j++) {
		bit = (char *)&a[n - 1][j];
		sum = sum + bit[0] + bit[1] + bit[2] + bit[3];
		nr = nr + 4;
	}
	// Adun bytes de pe coloana din dreapta
	for (i = 1; i < n - 1; i++) {
		bit = (char *)&a[i][m[i] - 1];
		sum = sum + bit[3];
		nr++;
	}

	return (double)sum / (double)nr;
}

void smasiv(char **nou, int *v, int *m, int n, int i, int j, int zona)
{
	if (i >= 0 && i < n && j >= 0 && j < 4 * m[i]) {
		if (nou[i][j] == 0) {
			nou[i][j] = 0xFF; // schimb valoarea pentru ca am trecut prin acest
			//element
			v[zona]++; // maresc numarul de elemente pe care le contine zona
			// in care ma aflu
			if (i + 1 < n)
				smasiv(nou, v, m, n, i + 1, j, zona);
			if (j + 1 < 4 * m[i])
				smasiv(nou, v, m, n, i, j + 1, zona);
			if (i - 1 >= 0)
				smasiv(nou, v, m, n, i - 1, j, zona);
			if (j - 1 >= 0)
				smasiv(nou, v, m, n, i, j - 1, zona);
		}
	}
}

int main(void)
{
	int n, *m, **a, i, j, nr_operatii;
	double medie;
	char golire, operatie, **nou, *bit;
	scanf("%d", &n);
	m = (int *)malloc(n * sizeof(int));
	a = (int **)malloc(n * sizeof(int *));

	for (i = 0; i < n; i++) {
		scanf("%d", &m[i]);
		a[i] = (int *)malloc(m[i] * sizeof(int));
		for (j = 0; j < m[i]; j++)
			scanf("%X", &a[i][j]);
	}
	medie = grad_incarcare(n, m, a);
	scanf("%d", &nr_operatii);

	for (i = 0; i < nr_operatii; i++) {
		scanf("%c", &golire); // golesc buffer-ul
		scanf("%c", &operatie);

		if (operatie == 'M')
			modificare(m, a);
		else if (operatie == 'D')
			stergere(a);
		else if (operatie == 'S')
			interschimbare(a);
	}
	nou = (char **)malloc(n * sizeof(char *));
	for (i = 0; i < n; i++)
		nou[i] = (char *)malloc(m[i] * 4 * sizeof(char));
	for (i = 0; i < n; i++)
		for (j = 0; j < m[i]; j++) {
			bit = (char *)&a[i][j];
			nou[i][j * 4 + 0] = bit[0];
			nou[i][j * 4 + 1] = bit[1];
			nou[i][j * 4 + 2] = bit[2];
			nou[i][j * 4 + 3] = bit[3];
		}
	int zona = 1; // contorizez cati de 0 sunt in fiecare zona
	int maxim = 0, min_i, min_j;
	int *v;
	v = (int *)malloc(2 * sizeof(int));
	v[0] = 0;
	v[1] = 0;

	for (i = 0; i < n; i++)
		for (j = 0; j < 4 * m[i]; j++) {
			if (nou[i][j] == 0) {
				smasiv(nou, v, m, n, i, j, zona);
				if (v[zona] > maxim) {
					maxim = v[zona];
					min_i = i;
					min_j = j;
				}
				zona++; // trecem la alta zona
				v = (int *)realloc(v, (zona + 1) * sizeof(int)); //pe masura ce
				// gasesc o zona noua, maresc numarul de elemente
				v[zona] = 0;
			}
		}
	printf("task 1\n");
	printf("%.8lf\n", medie);
	printf("task 2\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m[i]; j++)
			printf("%08X ", a[i][j]);
		printf("\n");
	}
	printf("task 3\n");
	printf("%d %d %d", min_i, min_j, maxim);
	free(m);
	for (i = 0; i < n; i++)
		free(a[i]);
	for (i = 0; i < n; i++)
		free(nou[i]);
	free(a);
	free(v);
	free(nou);
	return 0;
}
