#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include "../code snippets/distance.ccsn"

int iscirclecontainspos(int px, int py, int cx, int cy, int csz) {
    return calcdist(px, py, cx, cy) < csz;
}

int main() {
    int tcase;
    scanf("%d", &tcase);

    for (int i = 0; i < tcase; i++) {
        int posx, posy, destx, desty;
        scanf("%d %d %d %d", &posx, &posy, &destx, &desty);

        int ccnt;
        scanf("%d", &ccnt);

        int* posclist = (int*)malloc(sizeof(int) * ccnt);
        int* destclist = (int*)malloc(sizeof(int) * ccnt);
        int result = 0;
        for(int j = 0; j < ccnt; j++) {
            int cx, cy, csz;
            scanf("%d %d %d", &cx, &cy, &csz);

            if (iscirclecontainspos(posx, posy, cx, cy, csz) != iscirclecontainspos(destx, desty, cx, cy, csz))
                result++;
        }
        printf("%d\n", result);

        free(posclist);
        free(destclist);
    }

}