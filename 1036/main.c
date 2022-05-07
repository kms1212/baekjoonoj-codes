#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include <stdlib.h>

void add1digitb36(const char a, const char b, char* d10, char* d1) {
    int r1, r10;

    if (a <= '9' && a >= '0')
        r1 = a - '0';
    else if (a <= 'Z' && a >= 'A')
        r1 = a - 'A' + 10;

    if (b <= '9' && b >= '0')
        r1 += b - '0';
    else if (b <= 'Z' && b >= 'A')
        r1 += b - 'A' + 10;


    r10 = r1 / 36;
    r1 = r1 % 36;

    if (r1 <= 9 && r1 >= 0)
        *d1 = '0' + r1;
    else if (r1 <= 35 && r1 >= 10)
        *d1 = 'A' + r1 - 10;

    if (r10 <= 9 && r10 >= 0)
        *d10 = '0' + r10;
    else if (r10 <= 35 && r10 >= 10)
        *d10 = 'A' + r10 - 10;
} 

int sub1digitb36(const char a, const char b, char* d) {
    int r1;

    if (a <= '9' && a >= '0')
        r1 = a - '0';
    else if (a <= 'Z' && a >= 'A')
        r1 = a - 'A' + 10;

    if (b <= '9' && b >= '0')
        r1 -= b - '0';
    else if (b <= 'Z' && b >= 'A')
        r1 -= b - 'A' + 10;

    if (r1 < 0)
        return 1;

    if (r1 <= 9 && r1 >= 0)
        *d = '0' + r1;
    else if (r1 <= 35 && r1 >= 10)
        *d = 'A' + r1 - 10;

    return 0;
} 

void memflip(char* dest, const char* src, const size_t size) {
    for (size_t i = 0; i < size; i++)
        dest[i] = src[size - i - 1];
}

void addbase36(const char* a, const char* b, char* result) {
    char up = '0', t;
    char at[51] = { 0, };
    char bt[51] = { 0, };
    char r[52] = { 0, };

    memflip(at, a, strlen(a));
    memflip(bt, b, strlen(b));

    for (int i = 0; i < 50; i++) {
        if (!at[i] && !bt[i]) {
            if (up != '0')
                r[i] = '1';
            break;
        }

        if (up != '0') {
            add1digitb36(at[i], bt[i], &up, &(r[i]));
            add1digitb36(r[i], '1', &t, &(r[i]));
        } else
            add1digitb36(at[i], bt[i], &up, &(r[i]));
    }

    memflip(result, r, strlen(r));
}

int subbase36(const char* a, const char* b, char* result) {
    char down = '0', t;
    char at[51] = { 0, };
    char bt[51] = { 0, };
    char r[52] = { 0, };

    memflip(at, a, strlen(a));
    memflip(bt, b, strlen(b));

    for (int i = 0; i < 50; i++) {
        if (!at[i] && !bt[i]) {
            break;
        }

        if (down != '0') {
            sub1digitb36(at[i], bt[i], );
            add1digitb36(r[i], '1', &t, &(r[i]));
        } else
            add1digitb36(at[i], bt[i], &up, &(r[i]));
    }

    if (down != 0)
        return 1;

    memflip(result, r, strlen(r));
}

int main(int argc, char** argv) {
    char** num = 0;
    int numcnt;

    char a[51], b[51];
    char result[51] = { 0, };

    scanf("%s %s", a, b);

    addbase36(a, b, result);
    printf("%s\n", result);

    fflush(stdin);

    char c, d, r ;
    scanf("%c %c", &c, &d);
    sub1digitb36(c, d, &r);

    printf("%c\n", r);
/*
    scanf("%d", &numcnt);

    num = (char**)malloc(sizeof(char**) * numcnt);
    for (int i = 0; i < numcnt; i++) {
        num[i] = (char*)malloc(sizeof(char) * 51);
        scanf("%s", num[i]);
    }



    for(int i = 0; i < numcnt; i++) {
        free(num[i]);
    }
    free(num); */
}