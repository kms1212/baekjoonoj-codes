#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>

bool cmp1(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    return a.first < b.first;
}

bool cmp2(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    return a.second < b.second;
}

int main() {
    int cnt, ccnt;
    scanf("%d %d", &cnt, &ccnt);
    std::vector< std::pair<int, int> > distlist;

    int prevval;
    scanf("%d", &prevval);
    distlist.reserve(cnt - 1);
    for (int i = 0; i < cnt - 1; i++) {
        int currval;
        scanf("%d", &currval);
        distlist.push_back(std::make_pair(currval - prevval, i));
        prevval = currval;
    }

    std::sort(distlist.begin(), distlist.end(), cmp1);
    distlist.erase(distlist.begin() + ccnt * 2, distlist.end());
    std::sort(distlist.begin(), distlist.end(), cmp2);

    for (int i = 0; i < distlist.size(); i++) {
        if (distlist[i].first == -1)
            continue;
        if (i != 0)
            distlist[i - 1].first = -1;
        if (i != distlist.size() - 1)
            distlist[i + 1].first = -1;
    }


    for (int i = 0; i < distlist.size(); i++) {
        if (distlist[i].first != -1)
            printf("%d\n", distlist[i].first);
    }
}
