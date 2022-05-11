#include <stdio.h>
#include <stdlib.h>

int arr33[3][3] = {
    { 5, 4, 3 },
    { 6, 1, 2 },
    { 7, 8, 9 }
};

int absi(int n) {
    return n > 0 ? n : -n;
}

int getdigitcnt(int n) {
    if (n == 0)
        return 1;
    int result = 0;
    for (; n > 0; n /= 10)
        result++;
    return result;
}

int calc(int x, int y) {
    int val = 0;
    if (absi(x) < 2 && absi(y) < 2) {
        val = arr33[y + 1][x + 1];
    } else if (y <= -absi(x)) { // T
        int addition = arr33[0][1] - arr33[1][1];
        val = arr33[1][1] + addition;
        for (int i = 1; i < absi(y); i++) {
            addition += 8;
            val += addition;
        }
        val -= x;
    } else if (y >= absi(x)) { // B
        int addition = arr33[2][1] - arr33[1][1];
        val = arr33[1][1] + addition;
        for (int i = 1; i < absi(y); i++) {
            addition += 8;
            val += addition;
        }
        val += x;
    } else if (x > absi(y)) { // R
        int addition = arr33[1][2] - arr33[1][1];
        val = arr33[1][1] + addition;
        for (int i = 1; i < absi(x); i++) {
            addition += 8;
            val += addition;
        }
        val -= y;
    } else if (x < -absi(y)) { // L
        int addition = arr33[1][0] - arr33[1][1];
        val = arr33[1][1] + addition;
        for (int i = 1; i < absi(x); i++) {
            addition += 8;
            val += addition;
        }
        val += y;
    }
    return val;
}

int main() {
    int x1, y1, x2, y2, maxdigit = 0;
    scanf("%d %d %d %d", &y1, &x1, &y2, &x2);

    int** arr = (int**)malloc(sizeof(int*) * (y2 - y1 + 1));
    for (int i = 0; i < y2 - y1 + 1; i++) {
        arr[i] = (int*)malloc(sizeof(int) * (x2 - x1 + 1));
        for (int j = 0; j < x2 - x1 + 1; j++) {
            arr[i][j] = calc(j + x1, i + y1);
            if (getdigitcnt(arr[i][j]) > maxdigit)
                maxdigit = getdigitcnt(arr[i][j]);
        }
    }

    char fmtstr[10];
    sprintf(fmtstr, "%%%dd ", maxdigit);
    for (int i = 0; i < y2 - y1 + 1; i++) {
        for (int j = 0; j < x2 - x1 + 1; j++) {
            printf(fmtstr, arr[i][j]);
        }
        free(arr[i]);
        printf("\n");
    }
    
    free(arr);
}