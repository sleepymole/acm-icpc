#include <cstdint>
#include <iostream>
#include <queue>
#include <set>

const int MAXN = 300010;
const int N = 1000000;
int divisor[N + 1], a[MAXN];
int64_t _data[MAXN];

inline void add(int x, int n, int v) {
    for (int i = x; i <= n; i += i & (-i)) {
        _data[i] += v;
    }
}

inline int64_t sum(int x) {
    int64_t res = 0;
    for (int i = x; i; i -= i & (-i)) {
        res += _data[i];
    }
    return res;
}

void init_divisor() {
    for (int i = 1; i <= N; ++i) {
        for (int j = i; j <= N; j += i) {
            ++divisor[j];
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, m;
    std::cin >> n >> m;
    std::set<int> index;
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        add(i, n, a[i]);
        if (a[i] > 2) {
            index.insert(i);
        }
    }
    init_divisor();
    while (m--) {
        int t, l, r;
        std::cin >> t >> l >> r;
        if (t == 1) {
            std::queue<int> tmp;
            auto last = index.upper_bound(r);
            for (auto it = index.lower_bound(l); it != last; ++it) {
                int index = *it;
                add(index, n, divisor[a[index]] - a[index]);
                a[index] = divisor[a[index]];
                if (a[index] <= 2) {
                    tmp.push(index);
                }
            }
            while (!tmp.empty()) {
                index.erase(tmp.front());
                tmp.pop();
            }
        } else {
            std::cout << sum(r) - sum(l - 1) << "\n";
        }
    }
    return 0;
}