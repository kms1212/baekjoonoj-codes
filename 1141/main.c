#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

void orderlistaslength(char** list, int cnt) {
    char** tmp = (char**)malloc(sizeof(char*) * cnt);
    memcpy(tmp, list, sizeof(char*) * cnt);
    char** tmp2 = (char**)malloc(sizeof(char*) * cnt);
    memcpy(tmp2, list, sizeof(char*) * cnt);

    int index = 0;
    for (int i = 0; i < 51; i++) {
        for (int j = 0; j < cnt; j++) {
            if (tmp2[j][i] == 0 && tmp[j] != NULL) {
                list[index] = tmp[j];
                tmp[j] = NULL;
                index++;
            }
        }
    }
    free(tmp);
    free(tmp2);
}

int main(int argc, char** argv) {
    int wordcount;
    scanf("%d", &wordcount);

    int result = 0;

    char** wordlist = (char**)malloc(sizeof(char*) * wordcount);
    for (int i = 0; i < wordcount; i++) {
        wordlist[i] = (char*)malloc(sizeof(char) * 51);
        scanf("%s", wordlist[i]);
    }

    orderlistaslength(wordlist, wordcount);
    for (int i = wordcount - 1; i >= 0; i--) {
        printf("%s\n", wordlist[i]);

        if (wordlist[i] == NULL)
            continue;

        for (int j = 0; j < i; j++) {
            int tmp = 0;
            if (wordlist[j] == NULL)
                continue;
            for (int k = 0; k < strlen(wordlist[i]); k++)
                if (wordlist[i][k] == wordlist[j][k])
                    tmp++;
            if (tmp == strlen(wordlist[j])) {
                printf("%s contains %s\n", wordlist[i], wordlist[j]);
                wordlist[j] = NULL;
            }
        }
        result++;
        wordlist[i] = NULL;
        printf("%d\n", result);
    }

    for (int i = 0; i < wordcount; i++)
        free(wordlist[i]);
    free(wordlist);

    printf("%d\n", result);
}