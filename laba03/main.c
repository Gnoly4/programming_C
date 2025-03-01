#include <stdio.h>

int main() {
    char str[80];
    int i = 0;

    printf("vedi strochku: ");
    gets(str);

    while (str[i] != '\0') {
        if (str[i] == 'a' || str[i] == 'b') {
            str[i] = str[i] - 32;
        }
        i++;
    }

    printf("result: %s\n", str);
    return 0;
}
