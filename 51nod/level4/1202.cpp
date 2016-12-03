#include<iostream>
#include<cstdio>
using namespace std;
const int P = 1000000007;
const int maxn = 100010;
int a[maxn], f[maxn], id[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        if (id[a[i]]) f[i] = (2LL * f[i - 1] - f[id[a[i]] - 1]) % P;
        else f[i] = (2LL * f[i - 1] + 1) % P;
        id[a[i]] = i;
    }
    printf("%d\n", (f[n] + P) % P);
    return 0;
}