//311CA_Bobocu_Alexandra-Florentina
#include <stdio.h>
#define MAX 105

int verif_oriz(int n, int m, int nomo[MAX][MAX], int oriz[MAX][MAX])
{
	int i, j, secv_unit, k;
	for (i = 0; i < n; i++) {
		k = 1;//initial ma pozitionez in primul grup
		secv_unit = 0;
		for (j = 0; j < m; j++) {
			if (nomo[i][j] == 1) {//am gasit casuta colorata
				secv_unit++;//numar secvente de 1 consecutivi
				if (secv_unit > oriz[i][k])
					return 0;//am mai multi de 1 de cat este prevazut
			} else {//am gasit casuta alba
				if (secv_unit) {
					if (secv_unit != oriz[i][k])
						return 0;
					k++;//trec la urmatorul grup
				}
				secv_unit = 0;
			}
		}
		if (secv_unit) {//cand se termina cate o linie de matrice cu 1
			k++;
			if (secv_unit != oriz[i][k - 1])
				return 0;
		}
		if (k - 1 != oriz[i][0])
			return 0;
	}
	return 1;
}

int verif_vert(int n, int m, int nomo[MAX][MAX], int vert[MAX][MAX])
{
	int i, j, secv_unit, k;
	for (j = 0; j < m; j++) {
		k = 1;//initial ma pozitionez in primul grup
		secv_unit = 0;
		for (i = 0; i < n; i++) {
			if (nomo[i][j] == 1) {//am gasit casuta colorata
				secv_unit++;//numar secvente de 1 consecutivi
				if (secv_unit > vert[j][k])
					return 0;//am mai multi de 1 de cat este prevazut
			} else {//am gasit casuta alba
				if (secv_unit) {
					if (secv_unit != vert[j][k])
						return 0;
					k++;//trec la urmatorul grup
				}
				secv_unit = 0;
			}
		}
		if (secv_unit) {
			k++;
			if (secv_unit != vert[j][k - 1])
				return 0;
		}
		if (k - 1 != vert[j][0])
			return 0;
	}
	return 1;
}

int main(void)
{
	int n, m, nr_puzzle, i, j, nomo[MAX][MAX];
	int oriz[MAX][MAX], ok_oriz = 1, vert[MAX][MAX], ok_vert = 1;
	scanf("%d", &nr_puzzle);
	for (int t = 0; t < nr_puzzle; t++) {
		ok_oriz = 1;
		ok_vert = 1;
		scanf("%d %d", &n, &m);
		for (i = 0; i < n; i++) {
			scanf("%d", &oriz[i][0]);//citim numarul de grupuri de casute negre
			for (j = 1; j <= oriz[i][0]; j++)
				scanf("%d", &oriz[i][j]);//citim cate patratele sunt in grup
		}
		for (i = 0; i < m; i++) {
			scanf("%d", &vert[i][0]);//citim numarul de grupuri de casute negre
			for (j = 1; j <= vert[i][0]; j++)
				scanf("%d", &vert[i][j]);//citim cate patratele sunt in grup
		}
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				scanf("%d", &nomo[i][j]);//citim matricea
		ok_oriz = verif_oriz(n, m, nomo, oriz);
		ok_vert = verif_vert(n, m, nomo, vert);
		if (ok_oriz == 1 && ok_vert == 1)
			printf("Corect\n");
		else
			printf("Eroare\n");
	}
	return 0;
}
