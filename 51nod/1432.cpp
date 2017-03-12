#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 10000;
int w[maxn];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    sort(w, w + n);
    int ans = 0, p = 0, q = n - 1;
    while (true) {
        if (p > q) break;
        if (w[p] + w[q] <= m) {
            p++;
            q--;
            ans++;
        } else {
            q--;
            ans++;
        }
        if (p == q) {
            ans++;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}