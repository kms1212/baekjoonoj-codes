#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <string>
#include <sstream>

int readable;

char library[10][5] = {
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

void separatedata(std::stringstream& sstream) {
    if (readable) {
        sstream << ' ';
    } else {
        sstream.seekg(-1, std::ios_base::end);
        char ch;
        sstream.get(ch);
        if (ch >= '0' && ch <= '9')
            ch -= 10;
        else if (ch >= 'A' && ch <= 'Z')
            ch += 32;
        sstream.seekp(-1, std::ios_base::end);
        sstream.put(ch);
    }

}

int getdiff(char* a, char* b) {
    int samecnt = 0;
    int length = strlen(a) < strlen(b) ? strlen(a) : strlen(b);
    for (; (samecnt < length) && (a[samecnt] == b[samecnt]); samecnt++);
    return samecnt;
}

void compress(FILE* fpsrc, FILE* fptgt) {
    std::stringstream stream;

    char str1[25];
    char str2[25] = { 0, };

    char* currentstr = str1;
    char* prevstr = str2;

    for (;;) {
        if (fgets(currentstr, 25, fpsrc)) {
            currentstr[strlen(currentstr) - 1] = 0;
            int diff = getdiff(currentstr, prevstr);

            int i;
            for (i = 0; i < 10; i++) {  // Check suffix library
                if (strcmp(currentstr + diff, library[i]) == 0) {
                    stream << diff;
                    separatedata(stream);
                    stream << (char)(i + '0');
                    
                    break;
                }
            }
            if (i == 10) {  // If word is not suffix
                if (diff < 10 && diff >= 5 && *(currentstr + diff + 1) == 0) {  // If char is in charmap
                    switch(*(currentstr + diff)) {
                        case 'S':
                            stream << (char)('A' + (diff - 5) * 5);
                            break;
                        case 'T':
                            stream << (char)('B' + (diff - 5) * 5);
                            break;
                        case 'Y':
                            stream << (char)('C' + (diff - 5) * 5);
                            break;
                        case 'E':
                            stream << (char)('D' + (diff - 5) * 5);
                            break;
                        case 'D':
                            stream << (char)('E' + (diff - 5) * 5);
                            break;
                        default:
                            stream << diff;
                            separatedata(stream);
                            stream << currentstr + diff;
                    }
                } else {  // If char is not in charmap
                    stream << diff;
                    separatedata(stream);
                    stream << currentstr + diff;
                }
                    
            }
            separatedata(stream);

            stream.flush();

            char* swaptmp = currentstr;
            currentstr = prevstr;
            prevstr = swaptmp;
        } else {
            break;
        }
    }

    fputs(stream.str().c_str(), fptgt);
}

int main(int argc, char** argv) {
    if (argc < 4) {
        printf("%s: usage: %s [src] [target] [readable?]\n", argv[0], argv[0]);
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

    compress(fpsrc, fptgt);

end:
    fclose(fpsrc);
    fclose(fptgt);
}