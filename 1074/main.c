#include <stdio.h>
#include <stdlib.h>

int powi(int x, int n) {
    if (n == 0)
        return 1;
    for (int tmp = x; n > 1; n--)
        x *= tmp;
    return x;
}

int calc(int x, int y, int sz) {
    if (sz == 1)
        return 0;
    int result;
    int blocksz = sz * sz / 4;
    if (y >= sz / 2) {
        if (x >= sz / 2)
            result = 3 * blocksz;
        else
            result = 2 * blocksz;
    } else {
        if (x >= sz / 2)
            result = blocksz;
        else
            result = 0;
    }
    return result + calc(x % (sz / 2), y % (sz / 2), sz / 2);
}

int main(int argc, char** argv) {
    int sz, x, y;
    scanf("%d %d %d", &sz, &y, &x);
    sz = powi(2, sz);

    printf("%d\n", calc(x, y, sz));
    return 0;
}