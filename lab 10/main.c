#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

#define MAX_IN_ARRAY(arr, length, max_val, i)     \
    do {                                         \
        max_val = (length) > 0 ? (arr)[0] : 0;   \
        for (i = 1; i < (length); i++) {         \
            max_val = MAX(max_val, (arr)[i]);    \
        }                                        \
    } while(0)

int main() {
    char input[1024];
    printf("Enter the numbers separated by a space: ");
    if (!fgets(input, sizeof(input), stdin)) {
        fprintf(stderr, "Enter error\n");
        return 1;
    }

    input[strcspn(input, "\n")] = '\0';

    double numbers[100];
    int count = 0;

    char *token = strtok(input, " ");
    while (token != NULL && count < 100) {
        numbers[count++] = strtod(token, NULL);
        token = strtok(NULL, " ");
    }

    if (count == 0) {
        printf("Number is not entered.\n");
        return 0;
    }

    double max_number;
    int i;
    MAX_IN_ARRAY(numbers, count, max_number, i);

    printf("Max number: %g\n", max_number);

    return 0;
}

