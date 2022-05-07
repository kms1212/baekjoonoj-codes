#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int pwr(int x, int n) {
    if (n == 0)
        return 1;
    for (int tmp = x; n > 1; n--)
        x *= tmp;
    return x;
}

long double getlinelength(long double x1, long double y1, long double x2, long double y2) {
    int xb = x1 > x2 ? x1 : x2,
        yb = y1 > y2 ? y1 : y2,
        xs = x1 < x2 ? x1 : x2,
        ys = y1 < y2 ? y1 : y2;
    return sqrtl(powl(xb - xs, 2) + powl(yb - ys, 2));
}

void showgraph(int size, int* xlist, int* ylist, int listcnt) {
    char** graph = (char**)malloc(sizeof(char*) * (size * 2 + 1));
    for (int i = 0; i < size; i++) {
        graph[i] = (char*)malloc(sizeof(char) * (size * 2 + 2));
        memset(graph[i], ' ', size * 2 + 1);
        graph[i][size] = '|';
    }
    graph[size] = (char*)malloc(sizeof(char) * (size * 2 + 2));
    memset(graph[size], '-', size * 2 + 1);
    for (int i = size + 1; i < size * 2 + 1; i++) {
        graph[i] = (char*)malloc(sizeof(char) * (size * 2 + 2));
        memset(graph[i], ' ', size * 2 + 1);
        graph[i][size] = '|';
    }

    for (int i = 0; i < listcnt; i++) {
        graph[size - ylist[i]][xlist[i] + size] = i + '0';
    }

    for(int i = 0; i < size * 2 + 1; i++) {
        for (int j = 0; j < size * 2 + 1; j++) {
            if (graph[i][j] == '|') 
                fputs("][", stdout);
            else {
                putchar(graph[i][j]);
                putchar(graph[i][j]);
            }
        }
        putchar('\n');
        free(graph[i]);
    }
    free(graph);
}

int main(int argc, char** argv) {
    int xlist[7], ylist[7];
    scanf("%d %d %d %d %d %d", &xlist[0], &ylist[0], &xlist[1], &ylist[1], &xlist[2], &ylist[2]);

    long double a = 100000, b = 100000;
    if (xlist[0] != xlist[1])
        a = (long double)abs(ylist[1] - ylist[0]) / abs(xlist[1] - xlist[0]);
    if (xlist[1] != xlist[2])
        b = (long double)abs(ylist[2] - ylist[1]) / abs(xlist[2] - xlist[1]);
        
    if (a == b) {
        printf("-1\n");
        return 0;
    }

    long double d1, d2, d3, l1, l2, l3;
    d1 = getlinelength(xlist[0], ylist[0], xlist[1], ylist[1]);
    d2 = getlinelength(xlist[0], ylist[0], xlist[2], ylist[2]);
    d3 = getlinelength(xlist[1], ylist[1], xlist[2], ylist[2]);

    l1 = 2 * (d1 + d2);
    l2 = 2 * (d2 + d3);
    l3 = 2 * (d1 + d3);

    //printf("%.16Lf, %.16Lf, %.16Lf\n", l1, l2, l3);
    
    printf("%.16Lf\n", (l1 > (l2 > l3 ? l2 : l3) ? l1 : (l2 > l3 ? l2 : l3)) - (l1 < (l2 < l3 ? l2 : l3) ? l1 : (l2 < l3 ? l2 : l3)));

    //showgraph(15, xlist, ylist, 3);
}