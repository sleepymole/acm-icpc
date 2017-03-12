#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1000010;
int a[maxn];

int main() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        a[x]++;
    }
    int ans = 1;
    for (int i = 2; i < maxn; i++) {
        int cnt = 0;
        for (int j = i; j < maxn; j += i) {
            cnt += a[j];
            if (cnt >= 2) {
                ans = i;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}