#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

bool c (int a, int b) {
    return a > b;
}

int s(std::vector<int>& a, std::vector<int>& b, int n) {
    int result = 0;
    for (int i = 0; i < n; i++)
        result += a[i] * b[i];
    return result;
}

int main() {
    int arrsize;
    scanf("%d", &arrsize);
    std::vector<int> a, b;

    for (int i = 0; i < arrsize; i++) {
        int val;
        scanf("%d", &val);
        a.push_back(val);
    }
    for (int i = 0; i < arrsize; i++) {
        int val;
        scanf("%d", &val);
        b.push_back(val);
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end(), c);

    printf("%d\n", s(a, b, arrsize));
}