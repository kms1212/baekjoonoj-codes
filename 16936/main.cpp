#include <vector>
#include <cstdio>
#include <cstdint>
#include <cinttypes>
#include <algorithm>

uint64_t primefactorcnt(uint64_t num, uint64_t pf) {
    int result = 0;
    for (; num % pf == 0; result++) {
        num /= pf;
    }
    return result;
}

int main() {
    int cnt;
    scanf("%d", &cnt);
    std::vector<uint64_t> arr, result;
    arr.reserve(cnt);

    for (int i = 0; i < cnt; i++) {
        uint64_t val;
        scanf("%"SCNu64, &val);
        arr.push_back(val);
    }

    uint64_t biggest3pwr = 0;
    uint64_t smallest = UINT64_MAX;
    for (int i = 0; i < cnt; i++) {
        uint64_t value = primefactorcnt(arr[i], 3);
        if ((value > biggest3pwr) || (value == biggest3pwr && arr[i] < smallest)) {
            biggest3pwr = value;
            smallest = arr[i];
        }
    }

    uint64_t val = smallest;
    for (int i = 0; i < cnt; i++) {
        result.push_back(val);
        std::vector<uint64_t>::iterator it = std::find(arr.begin(), arr.end(), val * 2);
        if (it != arr.end()) {
            arr.erase(it);
            val *= 2;
            continue;
        }
        it = std::find(arr.begin(), arr.end(), val / 3);
        if (it != arr.end()) {
            arr.erase(it);
            val /= 3;
            continue;
        }
    }

    for (int i = 0; i < result.size(); i++) {
        printf("%"PRIu64" ", result[i]);
    }
    printf("\n");
}