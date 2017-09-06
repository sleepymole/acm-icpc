#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXS = 1010;
char str[MAXS];

int sa[MAXS], rk[MAXS], height[MAXS];
void build_sa(int n, int m) {
    static int sa2[MAXS], b[MAXS];
    memset(b, 0, m * sizeof(int));
    for (int i = 0; i < n; i++) b[rk[i]]++;
    for (int i = 1; i < m; i++) b[i] += b[i - 1];
    for (int i = n - 1; i >= 0; i--) sa[--b[rk[i]]] = i;
    for (int k = 1; k <= n; k <<= 1) {
        for (int i = n - k; i < n; i++) sa2[i + k - n] = i;
        for (int i = 0, p = k; i < n; i++)
            if (sa[i] >= k) sa2[p++] = sa[i] - k;
        memset(b, 0, m * sizeof(int));
        for (int i = 0; i < n; i++) b[rk[sa2[i]]]++;
        for (int i = 1; i < m; i++) b[i] += b[i - 1];
        for (int i = n - 1; i >= 0; i--) sa[--b[rk[sa2[i]]]] = sa2[i];
        memcpy(b, rk, n * sizeof(int));
        for (int i = 1, p = 1; i < n; i++) {
            int x = sa[i - 1] + k < n ? b[sa[i - 1] + k] : 0;
            int y = sa[i] + k < n ? b[sa[i] + k] : 0;
            rk[sa[i]] = b[sa[i - 1]] == b[sa[i]] && x == y ? p - 1 : p++;
        }
        rk[sa[0]] = 0, m = rk[sa[n - 1]] + 1;
        if (m == n) break;
    }
    for (int i = 0, k = 0; i < n - 1; i++) {
        if (k) k--;
        int j = sa[rk[i] - 1];
        while (str[i + k] == str[j + k]) k++;
        height[rk[i]] = k;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        int len = strlen(str);
        for (int i = 0; i < len; i++) rk[i] = str[i];
        rk[len] = 0;
        build_sa(len + 1, 128);
        int ans = 0;
        for (int i = 1; i <= len; i++) ans += len - sa[i] - height[i];
        printf("%d\n", ans);
    }
    return 0;
}