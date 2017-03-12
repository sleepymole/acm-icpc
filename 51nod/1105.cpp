#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 50010;
ll a[maxn], b[maxn];
int n, k;

ll judge(ll x) {
    ll sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] * b[n - 1] <= x) break;
        sum += n - (lower_bound(b, b + n, x / a[i] + 1) - b);
    }
    return sum;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &a[i], &b[i]);
    }
    sort(a, a + n);
    sort(b, b + n);
    ll l = a[0] * b[0], r = b[n - 1] * b[n - 1], mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (judge(mid) < k)
            r = mid;
        else
            l = mid + 1;
    }
    printf("%lld\n", r);
    return 0;
}