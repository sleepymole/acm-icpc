#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 50010;
long long ans;
int a[maxn], num;

void dfs(int pos) {
    int tmp = a[pos] + a[pos - 1];
    ans += tmp;
    for (int i = pos; i < num - 1; i++) {
        a[i] = a[i + 1];
    }
    num--;
    int j;
    for (j = pos - 1; j > 0 && a[j - 1] < tmp; j--) {
        a[j] = a[j - 1];
    }
    a[j] = tmp;
    while (j >= 2 && a[j] >= a[j - 2]) {
        int d = num - j;
        dfs(j - 1);
        j = num - d;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        a[num++] = a[i];
        while (num >= 3 && a[num - 1] >= a[num - 3]) dfs(num - 2);
    }
    while (num > 1) dfs(num - 1);
    printf("%lld\n", ans);
    return 0;
}