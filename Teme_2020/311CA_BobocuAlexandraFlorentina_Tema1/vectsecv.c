//311CA_Bobocu_Alexandra-Florentina
#include <stdio.h>

void bubble_sort(int N, int v[])
{
	int ok, aux;
	do {
		ok = 0;
		for (int i = 0; i < N - 1; ++i)
			if (v[i] > v[i + 1]) {
				ok = 1;
				aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
			}
	} while (ok == 1);
}

int gasire_element(int secv[], int n, int x)
{
	int i = 0;
	while (i < x) {
		if (secv[i] == n)
			return i;
		i++;
	}
	return -1;
}

int main(void)
{
	int v[10] = {0}, secv[100];
	int n_crescator[10] = {0}, n_descrescator[10] = {0};
	int n, i, j, dif = -1, x = 0, ok = 1;
	scanf("%d", &n);
	if (n >= 0 && n <= 9) {
		printf("0\n0\n");
		return 0;
	}
	while (ok == 1) {
		//extrag cifrele lui n in vectorul v[]
		int nr_cif = 0;//devine indice pentru vectorul de cifre
		int ct1 = 0, ct2 = 0, nr1 = 0, nr2 = 0;
		while (n != 0) {
			v[nr_cif++] = n % 10;
			n /= 10;
		}
		bubble_sort(nr_cif, v);
		//parcurgem invers vectorul ordonat crescator
		for (i = nr_cif - 1; i >= 0; i--)
			n_descrescator[ct2++] = v[i];
		//construim numarul cel mare nr2
		for (i = 0; i < ct2; ++i)
			nr2 = nr2 * 10 + n_descrescator[i];
		//parcurgem vectorul ordonat crescator
		j = 0;
		while (v[j] == 0)
			j++;//impun ca numarul sa nu aiba 0 pe prima pozitie
		for (i = j; i < nr_cif; ++i)
			n_crescator[ct1++] = v[i];
		//construim numarul cel mic nr1
		for (i = 0; i < ct1; ++i)
			nr1 = nr1 * 10 + n_crescator[i];
		n = nr2 - nr1;//noul numar rezultat in urma diferentei
		secv[++x] = n;//il retinem intr-un nou vector
		if (x)
			dif = gasire_element(secv, n, x);
		if (dif == 0) {
			printf("%d\n", x - 1);
			printf("0\n");
			return 0;
		}
		if (dif != -1) {
			printf("%d\n", dif - 1);
			for (i = dif; i < x; i++)
				printf("%d ", secv[i]);
			ok = 0;
		printf("\n");
		}
	}
	return 0;
}

