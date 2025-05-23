#include <stdio.h>
#include <setjmp.h>

jmp_buf env;

int fib(int n) {
    if (n == 1 || n == 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

void fib_sum(int n, int *sum) {
    if (n == 0) {
        longjmp(env, 1);
    }
    *sum += fib(n);
    fib_sum(n - 1, sum);
}

int main() {
    int n;
    int sum = 0;

    printf("Enter the quantity of Fibonachi numbers for summ: ");
    scanf("%d", &n);

    if (setjmp(env) == 0) {
        fib_sum(n, &sum);
    } else {
        printf("Summ of first %d Fibonachi numbers: %d\n", n, sum);
    }

    return 0;
}

