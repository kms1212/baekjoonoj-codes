#include <stdio.h>
#include <math.h>

int checkPrime(int n) {
    if (n == 1)
        return 0;
    else if (!(n % 2))
        return n == 2;
    else {
        for (int i = 3; i <= sqrt(n); i++)
            if(n % i == 0)
                return 0;
        return 1;
    }
}

int main(int argc, char** argv) {
    int cnt;
    scanf("%d", &cnt);
    int result = 0;
    for (; cnt > 0; cnt--) {
        int a;
        scanf("%d", &a);
        result += checkPrime(a);
    }

    printf("%d\n", result);
}