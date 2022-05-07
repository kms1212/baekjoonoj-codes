#include <stdio.h>
#include <math.h>

long double calcdist(long double x1, long double y1, long double x2, long double y2) {
    long double xb = x1 > x2 ? x1 : x2,
        yb = y1 > y2 ? y1 : y2,
        xs = x1 < x2 ? x1 : x2,
        ys = y1 < y2 ? y1 : y2;
    return sqrtl(powl(xb - xs, 2) + powl(yb - ys, 2));
}

int main() {
    int casecnt;
    scanf("%d", &casecnt);
    for (int i = 0; i < casecnt; i++) {
        int x1, y1, r1, x2, y2, r2;

        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

        long double dist = calcdist((long double)x1, (long double)y1, (long double)x2, (long double)y2);
        if ((r1 > r2 ? r1 - r2 : r2 - r1) < dist && (dist < r1 + r2))
            printf("2\n");
        else if (dist == r1 + r2 || (dist == (r1 > r2 ? r1 - r2 : r2 - r1) && dist != 0))
            printf("1\n");
        else if (r1 + r2 < dist || (r1 > r2 ? r1 - r2 : r2 - r1) > dist)
            printf("0\n");
        else 
            printf("-1\n");
    }
}