#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N = 500010;
int a[N + 1], n;

bool check(int pos) {
    if (pos * 2 > n) return false;
    for (int i = 1;i <= pos;i++) {
        if (a[i] * 2 > a[n - pos + i]) return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int l = 0, r = n / 2 + 1;
    while (r-l>1) {
        int mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    printf("%d\n", n - l);
    return 0;
}