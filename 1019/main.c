#include <stdio.h>
#include <memory.h>

int powi(int x, int n) {
    if (n == 0)
        return 1;
    for (int tmp = x; n > 1; n--)
        x *= tmp;
    return x;
}

int addnum(int* numlist, int num, int pwr10) {
    switch(pwr10) {
        case 0:
            for (int i = 1; i < num; i++) {
                (numlist[i] ) += 1;
            }
            break;
        case 1:
            for (int i = 0; i < 11; i++) {
                (numlist[i]) += num;
            }
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        default:
            break;
    }
    for (int i = 1; i < num; i++) {
        (numlist[i]) += powi(10, num);
    }
    (numlist[num])++;
}

int main() {
    int numlist[11];
    int i10, i1;
    memset(numlist, 0, sizeof(int) * 11);
    scanf("%d %d", &i10, &i1);
    addnum(numlist, i10, 1);
    for (int i = 0; i < 11; i++) {
        printf("%d ", numlist[i]);
    }
}