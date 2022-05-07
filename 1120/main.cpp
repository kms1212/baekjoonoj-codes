#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>



int main(int argc, char** argv) {
    std::vector<int[26]> list;

    for (;;) {
        int charmap[26];
        char tmp[10];

        scanf("%s", tmp);

        if (strcmp(tmp, "-") == 0) {
            break;
        } else {
            for (int i = 0; tmp[i] != 0; i++) {
                charmap[tmp[i] - 'A']++;
            }

            list.push_back(charmap);
        }
    }

    for (;;) {
        char tbl[10];
        scanf("%s", tbl);
        int cnt = 0;

        if (strcmp(tbl, "#") == 0) {
            break;
        } else {
            int tblcharmap[26];

            for (int i = 0; tbl[i] != 0; i++) {
                tblcharmap[tbl[i] - 'A']++;
            }
                
            for (int i = 0; i < list.size(); i++) {
                for (int j = 0; j < 26; j++) {
                    if (tblcharmap[j])
                }
            }
        }
    }
}