#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

void calc(int cnt, int skip) {
    int current = skip - 1;
    std::vector<int> list, result;
    for (int i = 0; i < cnt; i++) {
        list.push_back(i + 1);
    }

    for (int i = 0; i < cnt; i++) {
        result.push_back(list[current]);
        list.erase(list.begin() + current);
        if (list.size() != 0)
            current = (current + skip - 1) % list.size();
    }

    printf("<%d", result[0]);
    for (int i = 1; i < cnt; i++) {
        printf(", %d", result[i] == 0 ? 7 : result[i]);
    }
    printf(">\n");
}

int main() {
    int cnt, skip;
    scanf("%d %d", &cnt, &skip);
    calc(cnt, skip);
}