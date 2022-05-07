#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

#define UCHAR unsigned char

int readable;

UCHAR library[10][5] = {
    "ING",
    "MENT",
    "TION",
    "ION",
    "NCE",
    "NESS",
    "LESS",
    "ER",
    "ED",
    "LY"
};

UCHAR charmap1[6] = "STYED";

void decompress(FILE* fpsrc, FILE* fptgt) {
    UCHAR str[25];
    int isstr = 0;

    int diff = -1;
    for (int i = 0;; i++) {
        UCHAR tmp[25];
        UCHAR tmp2 = fgetc(fpsrc);
        for (int j = 0; tmp2 != EOF; j++) {
            tmp[j] = tmp2;
            if (readable) {
                if (tmp2 == ' ') {
                    tmp[j] = 0;
                    break;
                }
            } else {
                if (tmp2 >= 38 && tmp2 <= 47) {
                    tmp[j] += 10;
                    tmp[j + 1] = 0;
                    break;
                } else if (tmp2 >= 'a' && tmp2 <= 'z') {
                    tmp[j] -= 32;
                    tmp[j + 1] = 0;
                    break;
                }
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
        //printf("%s\n", str);
        fprintf(fptgt, "%s\n", str);
    }
}

int main(int argc, char** argv) {
    if (argc < 4) {
        printf("%s: usage: %s [src] [target] [readable]\n", argv[0], argv[0]);
        return 1;
    }

    readable = argv[3][0] - '0';

    FILE* fpsrc = fopen(argv[1], "r");

    if (fpsrc == NULL) {
        printf("%s: error: %s", argv[0], strerror(errno));
        return 0;
    }

    FILE* fptgt = fopen(argv[2], "w");

    if (fptgt == NULL) {
        printf("%s: error: %s", argv[0], strerror(errno));
        return 0;
    }

    decompress(fpsrc, fptgt);

end:
    fclose(fpsrc);
    fclose(fptgt);
}