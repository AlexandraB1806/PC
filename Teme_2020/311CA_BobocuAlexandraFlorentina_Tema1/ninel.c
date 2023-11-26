//311CA_Bobocu_Alexandra-Florentina
#include <stdio.h>
#define MAX 1000000//inaltimea maxima a unui copac

int main(void)
{
	int N, x1 = 0, x2 = 0, x3 = 0, xmin_par = MAX, xmax_impar = -1;
	int ok_par = 0;//presupunem ca nu am gasit copac cu indice par
	int nr_speciali = 0;
	long long S = 0;
	double m_a = 0;
	scanf("%d", &N);//citim numarul de copaci

	if (N == 1 || N == 2) {//deficit de copaci
		xmin_par = 0;
		xmax_impar = 0;
		printf("%lld\n", S);
		printf("%.7lf\n", m_a);
		printf("%d\n", xmax_impar);
		printf("%d\n", xmin_par);
		return 0;
	}

	for (int i = 0; i < N; ++i) {
		x1 = x2;
		x2 = x3;//transfer valoarea citita de la ult copac spre primul
		//citim inaltimea ultimului copac
		scanf("%d", &x3);
		if (i >= 2) {//incepem comparatia de la a treia pozitie
			if (x1 < x2 && x2 > x3) {
				S += x2;
				nr_speciali++;
				if ((i - 1) % 2 == 0 && x2 < xmin_par) {
					xmin_par = x2;
					ok_par = 1;
				}
				if ((i - 1) % 2 == 1 && x2 > xmax_impar)
					xmax_impar = x2;
			}
		}
	}
	if (ok_par == 0)
		xmin_par = -1;

	if (nr_speciali == 0) {
		S = -1;
		m_a = -1;
	} else {
		m_a = (double)S / (double)nr_speciali;
	}
	printf("%lld\n", S);
	printf("%.7lf\n", m_a);
	printf("%d\n", xmax_impar);
	printf("%d\n", xmin_par);
	return 0;
}

