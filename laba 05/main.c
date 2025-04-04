#include <stdio.h>
#include <stdlib.h>


double** createmat(int N) {
    double **matrix;
    int i;

    matrix = (double**)malloc(N * sizeof(double*));
    for (i = 0; i < N; i++) {
        matrix[i] = (double*)malloc(N * sizeof(double));
    }
    return matrix;
}

double** summatrix(double **matrix1, double **matrix2, int N) {
    double **temp = createmat(N);
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            temp[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return temp;
}

double** submatrix(double **matrix1, double **matrix2, int N) {  
    double **temp = createmat(N);
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            temp[i][j] = matrix1[i][j] - matrix2[i][j];  
        }
    }

    return temp;
}

double** multmatrix(double **m1, double **m2, int N) {
    double **temp = createmat(N);
    int i, j, k;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            temp[i][j] = 0;
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                temp[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    return temp;
}

int main() {
    double **matrix1, **matrix2, **result;
    int N, i, j;
    char operation;

    printf("vvod razmera matrici (n): ");
    scanf("%d", &N);

    matrix1 = createmat(N);
    matrix2 = createmat(N);

    printf("vvod 1 matrici:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("m1[%d][%d] = ", i, j);
            scanf("%lf", &matrix1[i][j]);
        }
    }

    printf("vvod 2 matrici:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("m2[%d][%d] = ", i, j);
            scanf("%lf", &matrix2[i][j]);
        }
    }

    printf("vvod operacii (+, -, *): ");
    scanf(" %c", &operation);

    if (operation == '+') {
        result = summatrix(matrix1, matrix2, N);
    } 
    else if (operation == '-') {  
        result = submatrix(matrix1, matrix2, N); 
    } 
    else if (operation == '*') {  
        result = multmatrix(matrix1, matrix2, N);
    } else {
        printf("Wrong!\n");
        return 1;
    }

    printf("result:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%lf ", result[i][j]);
        }
        printf("\n");
    }


    for (i = 0; i < N; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}
