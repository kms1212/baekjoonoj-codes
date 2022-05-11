#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[51], resultstr[51];
    int chrcnt[26];
    scanf("%s", str);
    memset(chrcnt, 0, sizeof(int) * 26);

    for (int i = 0; i < strlen(str); i++) {
        (chrcnt[str[i] - 'A'])++;
    }

    int oddcnt = 0;
    int oddidx = -1;

    for (int i = 0; i < 26; i++) {
        if (chrcnt[i] % 2 != 0) {
            oddcnt++;
            oddidx = i;
        }
        chrcnt[i] /= 2;
        if (oddcnt > 1) {
            printf("I'm Sorry Hansoo\n");
            return 0;
        }
    }

    int rstridx = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < chrcnt[i]; j++) {
            resultstr[rstridx] = i + 'A';
            rstridx++;
        }
    }

    if (oddidx != -1) {
        resultstr[rstridx] = oddidx + 'A';
        rstridx++;
    }

    for (int i = 25; i >= 0; i--) {
        for (int j = 0; j < chrcnt[i]; j++) {
            resultstr[rstridx] = i + 'A';
            rstridx++;
        }
    }
            resultstr[rstridx] = 0;

    printf("%s\n", resultstr);
    // chrcnt의 모든 요소를 반으로 나눈 다음(정수 나눗셈) 사전순으로 출력하고 홀수인 요소의 알파벳을 출력한 다음 역순으로 처음 문자열 출력
}