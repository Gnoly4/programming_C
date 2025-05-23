#include <stdio.h>

void print_digits_forward(unsigned int n) {
    if (n == 0) return;
    print_digits_forward(n / 10);
    printf("%u ", n % 10);
}

void print_digits_backward(unsigned int n) {
    if (n == 0) return;
    printf("%u ", n % 10);
    print_digits_backward(n / 10);
}

int main() {
    unsigned int N;

    printf("Enter a natural number N: ");
    if (scanf("%u", &N) != 1 || N == 0) {
        printf("Error: enter the number that higher than zero.\n");
        return 1;
    }

    if (N == 0) {
        printf("0\n0\n");
        return 0;
    }

    print_digits_forward(N);
    printf("\n");

    print_digits_backward(N);
    printf("\n");

    return 0;
}

