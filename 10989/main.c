#include <stdio.h>

int main() {
    int numcnt[10000];
    int cnt;
    scanf("%d", &cnt);
    for (int i = 0; i < 10000; i++)
        numcnt[i] = 0;

    for (int i = 0; i < cnt; i++) {
        int num;
        scanf("%d", &num);

        (numcnt[num - 1])++;
    }

    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < numcnt[i]; j++) {
            printf("%d\n", i + 1);
        }
    }
}