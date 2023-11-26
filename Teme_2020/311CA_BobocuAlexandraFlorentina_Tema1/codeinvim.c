//311CA_Bobocu_Alexandra-Florentina
#include <stdio.h>

void bubble_sort(int nr, int nota[])
{
	int ok, aux;
	do {
		ok = 0;
		for (int i = 0; i < nr - 1; ++i)
			if (nota[i] > nota[i + 1]) {
				ok = 1;
				aux = nota[i];
				nota[i] = nota[i + 1];
				nota[i + 1] = aux;
			}
	} while (ok == 1);
}

int main(void)
{
	int n, i, x[100], c[100], p_min, P = 0, nota[100] = {0}, nr = 0, nr10 = 0;
	int dif, m = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &x[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &c[i]);
	scanf("%d", &p_min);
	for (i = 0; i < n; i++)
		P = P + x[i] * c[i];//punctajul studentului
	dif = p_min - P;//cate puncte ii mai trebuie ca sa atinga minimul
	if (dif == 0 || dif < 0) {//studentul n-are nevoie de marire
		printf("-1");
		return 0;
	}
	for (i = 0; i < n; i++) {
		if (x[i] < 10)
			nota[nr++] = (10 - x[i]) * c[i];//cresterea posibila pentru
			//materiile la care studentul nu are 10
		else
			if (x[i] == 10)
				nr10++;
	}
	bubble_sort(nr, nota);
	if (n == nr10) {
		printf("-1");
		return 0;
	}
	while (dif > 0) {
		dif = dif - nota[nr - 1];
		nr--;
		m++;
	}
	printf("%d\n", m);
	return 0;
}
