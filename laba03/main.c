#include <stdio.h>

int main() {
    char str[80];
    printf("Vvedi strok: ");
    fgets(str, sizeof(str), stdin); 

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a') {
            str[i] = 'A';
        } else if (str[i] == 'b') 
            str[i] = 'B';
    }

    printf("Result: %s\n", str);
    return 0;
}
