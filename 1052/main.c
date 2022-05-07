#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include <stdlib.h>

int pwr(int x, int n) {
    if (n == 0)
        return 1;
    for (int tmp = x; n > 1; n--)
        x *= tmp;
    return x;
}

int calc (int a, int b) {
    int largestSquare = 1;
    b--;
    
    if (largestSquare == a) {
        printf("0");
        exit(0);
    }
    for (int i = 0;; i++) {
        largestSquare *= 2;
        if (largestSquare == a) {
            printf("0");
            exit(0);
        }
        if (largestSquare * 2 > a)
            break;
    }
    
    if (b == 0) {
        int largestSquare = 1; 
        if (largestSquare == a) {
            printf("0");
            exit(0);
        } 
        for (int i = 0;; i++) {
            largestSquare *= 2;
            if (largestSquare == a) {
                printf("0");
                exit(0);
            }
            if (largestSquare * 2 > a)
                break;
        }
        return largestSquare * 2 - a;
    }
    
    a -= largestSquare;
    if (!a)
        return 0;
    int result = calc(a, b);
    
    return result;
}

int main(int argc, char** argv) {
    int a, b, result = 0;
    
    scanf("%d %d", &a, &b);
    
    result = calc(a, b);
    
    printf("%d\n", result);
}