#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 8010;
const int zero = 8000;
int a[maxn], b[maxn * 2];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        memset(b, 0, sizeof(b));
        int ans = 0, sum = 0;
        b[zero] = 1;
        for (int j = 1; j < i; j++) {
            sum += a[j] > a[i] ? 1 : -1;
            b[zero + sum]++;
        }
        ans += b[zero + sum];
        for (int j = i + 1; j <= n; j++) {
            sum += a[j] > a[i] ? 1 : -1;
            ans += b[zero + sum];
        }
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}