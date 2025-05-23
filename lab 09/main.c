#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[256];
    printf("Vvedi wiragenie:\n");
    if (!fgets(input, sizeof(input), stdin)) {
        printf("Error\n");
        return 1;
    }

    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    double result = 0.0;
    char *token;
    char *rest = input;

    int sign = 1;

    int expectNumber = 1;

    while ((token = strtok(rest, " ")) != NULL) {
        rest = NULL;

        if (expectNumber) {
            char *endptr;
            double val = strtod(token, &endptr);
            if (endptr == token) {
                printf("Error:we waited number, but got '%s'\n", token);
                return 1;
            }
            result += sign * val;
            expectNumber = 0;
        } else {
            if (strlen(token) != 1 || (token[0] != '+' && token[0] != '-')) {
                printf("Error: waited operator '+' or '-', but got '%s'\n", token);
                return 1;
            }
            sign = (token[0] == '+') ? 1 : -1;
            expectNumber = 1;
        }
    }

    if (expectNumber) {
        printf("Error: wiragenie end on operator \n");
        return 1;
    }

    printf("Result: %.6g\n", result);

    return 0;
}

