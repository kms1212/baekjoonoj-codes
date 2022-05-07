#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    int sz;
    scanf("%d", &sz);

    char** paper = (char**)malloc(sizeof(char*) * sz);
    for (int i = 0; i < sz; i++) {
        paper[i] = (char*)malloc(sizeof(char) * (sz + 1));
        memset(paper[i], '.', sz);
        paper[i][sz] = 0;
    }

    char movement[251];
    int x = 0, y = 0;
    char prevmovement = '0';
    scanf("%s", movement);
    for (int i = 0; movement[i] != 0; i++) {
        switch(movement[i]) {
            case 'U':
                if (y == 0)
                    break;
                if (paper[y][x] == '.')
                    paper[y][x] = '|';
                else if (paper[y][x] == '-')
                    paper[y][x] = '+';
                y--;
                if (paper[y][x] == '.')
                    paper[y][x] = '|';
                else if (paper[y][x] == '-')
                    paper[y][x] = '+';
                break;
            case 'D':
                if (y == sz - 1)
                    break;
                if (paper[y][x] == '.')
                    paper[y][x] = '|';
                else if (paper[y][x] == '-')
                    paper[y][x] = '+';
                y++;
                if (paper[y][x] == '.')
                    paper[y][x] = '|';
                else if (paper[y][x] == '-')
                    paper[y][x] = '+';
                break;
            case 'L':
                if (x == 0)
                    break;
                if (paper[y][x] == '.')
                    paper[y][x] = '-';
                else if (paper[y][x] == '|')
                    paper[y][x] = '+';
                x--;
                if (paper[y][x] == '.')
                    paper[y][x] = '-';
                else if (paper[y][x] == '|')
                    paper[y][x] = '+';
                break;
            case 'R':
                if (x == sz - 1)
                    break;
                if (paper[y][x] == '.')
                    paper[y][x] = '-';
                else if (paper[y][x] == '|')
                    paper[y][x] = '+';
                x++;
                if (paper[y][x] == '.')
                    paper[y][x] = '-';
                else if (paper[y][x] == '|')
                    paper[y][x] = '+';
                break;
        }
        prevmovement = movement[i];
    }

    for (int i = 0; i < sz; i++) {
        printf("%s\n", paper[i]);
    }

}