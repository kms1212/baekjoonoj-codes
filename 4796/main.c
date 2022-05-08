#include <stdio.h>

int main() {
    for (int i = 1;; i++) {
        int l, p, v, v2, r = 0;
        scanf("%d %d %d", &l, &p, &v);
        v2 = v;
        
        if (l == 0 && p == 0 && v == 0)
            break;
        
        for (; v > l - 1;) {
            r += l;
            v -= p;
        }
        r += v > 0 ? v : 0;
        

        printf("Case %d: %d\n", i, r);
    }
}