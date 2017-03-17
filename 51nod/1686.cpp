#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 100010;
int a[maxn], b[maxn], n;
long long k;

bool check(int x) {
    if (x <= 1) return true;
    memset(b, 0, sizeof(b));
    int p = 0, q = 0;
    long long tot = 0, carry = 0;
    while (q < n) {
        int tmp = p;
        b[a[q]]++;
        if (b[a[q]] == x) {
            while (b[a[p]] != x) {
                b[a[p++]]--;
            }
            tot += p - tmp + carry + 1;
            carry += p - tmp + 1;
            b[a[p++]]--;
        } else {
            tot += carry;
        }
        q++;
    }
    return tot >= k;
}

int main() {
    scanf("%d%lld", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b, b + n);
    unique(b, b + n);
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(b, b + n, a[i]) - b + 1;
    }
    int l = 0, r = n;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%d\n", l);
    return 0;
}