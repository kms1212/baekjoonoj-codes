#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int pwr(int x, int n) {
    if (n == 0)
        return 1;
    for (int tmp = x; n > 1; n--)
        x *= tmp;
    return x;
}

char numlist[10][5][3] = {
    {
        { '#', '#', '#'},
        { '#', '.', '#'},
        { '#', '.', '#'},
        { '#', '.', '#'},
        { '#', '#', '#'}
    },
    { 
        { '.', '.', '#'},
        { '.', '.', '#'},
        { '.', '.', '#'},
        { '.', '.', '#'},
        { '.', '.', '#'}
    }, 
    {
        { '#', '#', '#'},
        { '.', '.', '#'},
        { '#', '#', '#'},
        { '#', '.', '.'},
        { '#', '#', '#'}
    }, 
    {
        { '#', '#', '#'},
        { '.', '.', '#'},
        { '#', '#', '#'},
        { '.', '.', '#'},
        { '#', '#', '#'}
    }, 
    {
        { '#', '.', '#'},
        { '#', '.', '#'},
        { '#', '#', '#'},
        { '.', '.', '#'},
        { '.', '.', '#'}
    }, 
    {
        { '#', '#', '#'},
        { '#', '.', '.'},
        { '#', '#', '#'},
        { '.', '.', '#'},
        { '#', '#', '#'}
    }, 
    {
        { '#', '#', '#'},
        { '#', '.', '.'},
        { '#', '#', '#'},
        { '#', '.', '#'},
        { '#', '#', '#'}
    }, 
    {
        { '#', '#', '#'},
        { '.', '.', '#'},
        { '.', '.', '#'},
        { '.', '.', '#'},
        { '.', '.', '#'}
    }, 
    {
        { '#', '#', '#'},
        { '#', '.', '#'},
        { '#', '#', '#'},
        { '#', '.', '#'},
        { '#', '#', '#'}
    }, 
    {
        { '#', '#', '#'},
        { '#', '.', '#'},
        { '#', '#', '#'},
        { '.', '.', '#'},
        { '#', '#', '#'}
    }
};

void getnumlist(int* list, char** display) {
    int tmp = 0;
    for (int i = 0; i < 10; i++) {
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 3; x++) {
                if (display[y][x] == '#' && numlist[i][y][x] == '.')
                    goto next;
            }
        }
        list[tmp] = i;
        tmp++;

next:
        continue;
    }
    list[tmp] = -1;
}

int getcnt(int** list, int digit) {
    int result = 1;
    for (int i = 0; i < digit; i++) {
        int cnt = 0;
        for (; list[i][cnt] != -1; cnt++);
        result *= cnt;
    }
    return result;
}

uint64_t getsum(int** list, int digit) {
    uint64_t sum = 0;

    if (digit == 0)
        return 0;

    int ccnt = 0;
    for (; list[0][ccnt] != -1; ccnt++);

    uint64_t cdigitsum = 0;
    for(int i = 0; list[0][i] != -1; i++)
        cdigitsum += list[0][i];

    uint64_t cnt = getcnt(&(list[1]), digit - 1);
    sum += cdigitsum * pwr(10, digit - 1) * cnt;
    sum += getsum(&(list[1]), digit - 1) * ccnt;

    return sum;
}

int main(int argc, char** argv) {
    int digit;
    char** display;
    uint64_t sum = 0;

    scanf("%d", &digit);

    display = (char**)malloc(sizeof(char*) * 5);
    for (int i = 0; i < 5; i++) {
        display[i] = (char*)malloc(sizeof(char) * ((digit * 4) - 1));
        scanf("%s", display[i]);
    }

    int** numlist = (int**)malloc(sizeof(int*) * digit);

    for (int i = 0; i < digit; i++) {
        numlist[i] = (int*)malloc(sizeof(int) * 11);
        char* displaytmp[5] = { 
            display[0] + i * 4, 
            display[1] + i * 4, 
            display[2] + i * 4, 
            display[3] + i * 4, 
            display[4] + i * 4,
        };
        getnumlist(numlist[i], displaytmp);
    }

    if (getcnt(numlist, digit) == 0) {
        printf("-1");
        return 0;
    }

    printf("%Lf\n", (long double)getsum(numlist, digit) / getcnt(numlist, digit));

    for (int i = 0; i < 5; i++)
        free(display[i]);
    free(display);
}