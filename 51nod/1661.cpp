#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 100010;
ll a[maxn], n, k;

ll get_sg(ll x) {
    if (x == 1) return 0;
    if (x % k == 0) return x / k * (k - 1);
    if (x % k != 1)
        return x / k * (k - 1) + x % k - 1;
    else
        return get_sg(x / k);
}

ll ceil(ll x, ll y) {
    if (x % y == 0) return x / y;
    return x / y + 1;
}

int main() {
    ll num, x = 0, y, sg;
    scanf("%lld%lld", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        x ^= get_sg(a[i]);
    }
    if (x == 0) {
        printf("Bob\n");
    } else {
        for (int i = 1; i <= n; i++) {
            y = x ^ get_sg(a[i]);
            if (y == 0)
                y = 1;
            else if (y % (k - 1) == 0)
                y = y / (k - 1) * k;
            else
                y = y / (k - 1) * k + y % (k - 1) + 1;
            while (y < ceil(a[i], k)) {
                y = y * k + 1;
            }
            if (y < a[i]) {
                printf("Alice %d %lld\n", i, y);
                break;
            }
        }
    }
    return 0;
}