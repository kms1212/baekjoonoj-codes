#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include <stdlib.h>
char library[10][5]={"ING","MENT","TION","ION","NCE","NESS","LESS","ER","ED","LY"};char charmap1[]="STYED";

void decompress(FILE* fpsrc, FILE* fptgt) {
    char str[25];
    int isstr = 0;

    int diff = -1;
    for (int i = 0;; i++) {
        char tmp[25];
        char tmp2 = fgetc(fpsrc);
        for (int j = 0; tmp2 != EOF; j++) {
            tmp[j] = tmp2;
            if (tmp2 >= 38 && tmp2 <= 47) {
                tmp[j] += 10;
                tmp[j + 1] = 0;
                break;
            } else if (tmp2 >= 'a' && tmp2 <= 'z') {
                tmp[j] -= 32;
                tmp[j + 1] = 0;
                break;
            }
            tmp2 = fgetc(fpsrc);
        } 
        if (tmp2 == EOF)
            break;

        if (tmp[0] <= '9' && tmp[0] >= '0') {
            int value = atoi(tmp);
            if (isstr) {
                strcpy(str + diff, library[value]);
                diff = -1;
                isstr = 0;
            } else {
                diff = value;
                isstr = 1;
                continue;
            }
        } else {
            if (isstr) {
                strcpy(str + diff, tmp);
                isstr = 0;
            } else {
                if (tmp[0] >= 'A') {
                    diff = (tmp[0] - 'A') / 5 + 5;
                    str[diff] = charmap1[(tmp[0] - 'A') % 5];
                }
                str[diff + 1] = 0;
                isstr = 0;
            }
        }
        fprintf(fptgt, "%s\n", str);
    }
}