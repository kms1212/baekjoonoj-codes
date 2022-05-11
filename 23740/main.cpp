// clang++ -g main.cpp -o main -std=c++17

#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>

typedef std::tuple<int, int, int> businfo;

bool cstart(businfo& a, businfo& b) {
    return std::get<0>(a) < std::get<0>(b);
}
bool cend(businfo& a, businfo& b) {
    return std::get<1>(a) < std::get<1>(b);
}

int main() {
    int cnt;
    scanf("%d", &cnt);

    std::vector<businfo> list, result;

    for (int i = 0; i < cnt; i++) {
        int start, end, price;
        scanf("%d %d %d", &start, &end, &price);
        list.push_back(std::make_tuple(start, end, price));
    }

    std::sort(list.begin(), list.end(), cstart);

    std::vector<businfo>::iterator previt = list.begin();
    for (int i = 1; i < list.size(); i++) {
        if (std::get<0>(list[i]) != std::get<0>(*previt)) {
            std::sort(previt, list.begin() + i, cend);
            previt = list.begin() + i;
        }
    }
    std::sort(previt, list.end(), cend);

    int start = std::get<0>(list[0]), end = std::get<1>(list[0]), price = std::get<2>(list[0]);
    for (int i = 1; i < list.size(); i++) {
        int cstart = std::get<0>(list[i]), cend = std::get<1>(list[i]), cprice = std::get<2>(list[i]);
            printf("!%d: %d %d %d, %d %d %d\n", i, cstart, cend, cprice, start, end, price);
        if (cstart <= end) {
            end = end > cend ? end : cend;
            price = price < cprice ? price : cprice;
        } else {
            result.push_back(std::make_tuple(start, end, price));
            start = cstart;
            end = cend;
            price = cprice;
        }
    }
    result.push_back(std::make_tuple(start, end, price));
    printf("%lu\n", result.size());
    for (int i = 0; i < result.size(); i++) {
        printf("%d %d %d\n", std::get<0>(result[i]), std::get<1>(result[i]), std::get<2>(result[i]));
    }
}