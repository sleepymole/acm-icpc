#include <iostream>
#include <vector>

std::vector<int> prime;
int count(int m, int n) {
    if (n == 0) return m;
    if (n == 1) return m - m / prime[0];
    return count(m, n - 1) - count(m / prime[n - 1], n - 1);
}

int main() {
    int T;
    std::cin >> T;
    while (T--) {
        int x, p, k;
        std::cin >> x >> p >> k;
        prime.clear();
        for (int i = 2; i * i <= p; ++i) {
            if (p % i == 0) {
                prime.push_back(i);
                while (p % i == 0) p /= i;
            }
        }
        if (p > 1) prime.push_back(p);
        int n = prime.size();
        k += count(x, n);
        int l = 1, r = 2e7;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (count(m, n) >= k)
                r = m;
            else
                l = m;
        }
        std::cout << r << "\n";
    }
    return 0;
}