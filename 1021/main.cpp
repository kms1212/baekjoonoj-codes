#include <deque>
#include <iostream>
#include <cstdio>

void rotater(std::deque<int>* deque, int loopcnt, int* calccnt) {
    for (int i = 0; i < loopcnt; i++) {
        int value = deque->back();
        deque->pop_back();
        deque->push_front(value);
    }
    (*calccnt) += loopcnt;
}

void rotatel(std::deque<int>* deque, int loopcnt, int* calccnt) {
    for (int i = 0; i < loopcnt; i++) {
        int value = deque->front();
        deque->pop_front();
        deque->push_back(value);
    }
    (*calccnt) += loopcnt;
}

int main() {
    std::deque<int> deque;
    int cnt, numcnt, calccnt = 0;
    scanf("%d %d", &cnt, &numcnt);
    for (int i = 0; i < cnt; i++) deque.push_back(i + 1);

    for (int i = 0; i < numcnt; i++) {
        int num, numindex = -1;
        scanf("%d", &num);

        for (int i = 0; i < deque.size(); i++)
            if (deque[i] == num)
                numindex = i;

        if (numindex > deque.size() / 2) {
            rotater(&deque, deque.size() - numindex, &calccnt);
        } else {
            rotatel(&deque, numindex, &calccnt);
        }
        deque.pop_front();
        /*printf("%d\n", deque.front());
        for (int i = 0; i < deque.size(); i++) {
            printf("%d ", deque[i]);
        }
        printf("\n");*/
    }

    printf("%d\n", calccnt);
}