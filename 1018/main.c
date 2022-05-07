#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include <stdlib.h>

int get8x8result (char** board, int x, int y) {
    int cstat = 0;
    int resultB = 0;
    int resultW = 0;

    for (int i = y; i < y + 8; i++) {
        for (int j = x; j < x + 8; j++) {
            if (board[i][j] != (j % 2 == cstat ? 'B' : 'W'))
                resultB++;
            else
                resultW++;
        }
        cstat = !cstat;
    }

    return resultB < resultW ? resultB : resultW;
}

int main(int argc, char** argv) {
    int w, h;
    
    scanf("%d %d", &h, &w);

    char** board = (char**)malloc(sizeof(char*) * h);
    for (int i = 0; i < h; i++) {
        board[i] = (char*)malloc(sizeof(char) * w);
        scanf("%s", board[i]);
    }

    int result = -1;

    for (int i = 0; i < h - 7; i++) {
        for (int j = 0; j < w - 7; j++) {
            int tmp = get8x8result(board, j, i);

            if (tmp < result || result == -1)
                result = tmp;
        }
    }
    
    printf("%d\n", result);

    for (int i = 0; i < h; i++) {
        free(board[i]);
    }
    free(board);
}