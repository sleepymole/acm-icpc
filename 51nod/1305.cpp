#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 100010;
typedef long long ll;
int a[maxn];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 1) break;
        for (int j = i + 1; j < n; j++) {
            int x = (ll)(a[i] + a[j]) / (a[i] * a[j]);
            if (x == 0) break;
            ans = ans + x;
        }
    }
    cout << ans << endl;
    return 0;
}