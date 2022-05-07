#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>

#include "digitcnt.ccsn"
#include "graph.ccsn"

double mod(double x) {
    double i;
    return modf(x, &i);
}

double d10(double x) {
    return x / 10;
}

int circle(double x, double* r) {
    r[0] = sqrt(-pow(x, 2) + 1);
    r[1] = -sqrt(-pow(x, 2) + 1);
    return 2;
}

int circle2(double x, double* r) {
    r[0] = sqrt(-pow(x, 2) + 4);
    r[1] = -sqrt(-pow(x, 2) + 4);
    return 2;
}

double f3(double x) {
    return pow(x, 3) + 2 * pow(x, 2) - x - 2;
}

int main() {
    showgraph(20, 20, 0.1, 0.05, 3, d10, log2, log);

    showgraphm(20, -1, 0.1, 0.1, 2, circle, circle2);
}