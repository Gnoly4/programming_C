#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Perimetr(double a, double b, double c) {
    return a + b + c;
}

double Ploshad(double a, double b, double c) {
    double p = Perimetr(a, b, c) / 2; 
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
    double a, b, c;
    
    printf("Vvod dlin storon:\n");
    
    while(1) {
        printf("Storona a: ");
        scanf("%lf", &a);
        printf("Storona b: ");
        scanf("%lf", &b);
        printf("Storona c: ");
        scanf("%lf", &c);
        
        if(a > 0 && b > 0 && c > 0 &&
           a + b > c &&
           a + c > b &&
           b + c > a) {
            break;
        }
        printf("Eto ne dlini storon\n\n");
        break;
    }
    
    printf("\nRes:\n");
    printf("Perimetr: %.2f\n", Perimetr(a, b, c));
    printf("Ploshad: %.2f\n", Ploshad(a, b, c));
    
    return 0;
}

