#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <map>

int pwr(int x, int n) {
    if (n == 0)
        return 1;
    for (int tmp = x; n > 1; n--)
        x *= tmp;
    return x;
}

int checkPrime(int n) {
    if (n == 1)
        return 0;
    else if (!(n % 2))
        return n == 2;
    else {
        for (int i = 3; i <= sqrt(n); i++)
            if(n % i == 0)
                return 0;
        return 1;
    }
}

void factorize(std::map<int, int>* list, int num) {
    list->clear();
    int k = 2;
	while (num != 1) {
		if (num % k == 0) {
            (*list)[k] = (*list)[k] + 1;
			num /= k;
		}
		else {
			k++;
		}
	}
}

int main(int argc, char** argv) {
    std::map<int, int> map;
    int cnt;

    scanf("%d", &cnt);

    for (int i = 0; i < cnt; i++) {
        std::map<int, int> list;
        int num;
        scanf("%d", &num);

        factorize(&list, num);
        for (std::map<int, int>::iterator i = list.begin(); i != list.end(); i++) {
            if (map[(*i).first] < (*i).second)
                map[(*i).first] = (*i).second;
        }
    }

    int num = 1;
    for (std::map<int, int>::iterator i = map.begin(); i != map.end(); i++) {
        num *= pwr((*i).first, (*i).second); 
    }

    printf("%d\n", num);
}