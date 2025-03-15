#include <stdio.h>

/*1 Îáúÿâèòü ìàññèâ äàííûõ òèïà double ðàçìåðîì 3 íà 3. 
2Ââåñòè ñ êîíñîëè åãî çíà÷åíèÿ, âûâåñòè íà êîíñîëü ñóììó åãî ýëåìåíòîâ, ðàñïîëîæåííûõ íà ãëàâíîé äèàãîíàëè è ñóììó ýëåìåíòîâ, 
ðàñïîëîæåííûõ íà  ïîáî÷íîé äèàãîíàëè.
3Îáúÿâèòü ìàññèâ äàííûõ òèïà int ðàçìåðîì 2 íà 2.
4Ââåñòè ñ êîíñîëè åãî çíà÷åíèÿ, âûâåñòè íà êîíñîëü êâàäðàò äàííîé ìàòðèöû.
*/

int main() {
    double m[3][3];
    double sum1 = 0, sum2 = 0;
    int m2[2][2];
    double res[2][2];
    char i, j, k;

    printf("vedi matricu 3x3:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%lf", &m[i][j]);
        }
    }

    for (i = 0; i < 3; i++) {
        sum1 += m[i][i];
    }

    for (i = 0; i < 3; i++) {
        sum2 += m[i][2 - i];
    }

    printf("Suma diagonal main: %.2lf\n", sum1);
    printf("Suma diagonal ne main: %.2lf\n", sum2);

    printf("vedi matricu 2x2:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &m2[i][j]);
        }
    }

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 2; k++) {
                res[i][j] += m2[i][k] * m2[k][j];
            }
        }
    }

    printf("kvadr matrici 2x2:\n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%.2lf ", res[i][j]);
        }
    }
    return 0;
}
