#include <iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
int a[20001], n;

int cal(int k) {
    int ans = -INF;
    for (int i = 1; i <= k; i++) {
        int sum = 0;
        for (int j = i; j <= n; j += k) {
            sum += a[j];
        }
        ans = max(ans, sum);
    }
    return ans;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = -INF;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i > 2) ans = max(ans, cal(i));
            if (i > 2) ans = max(ans, cal(n / i));
        }
    }
    cout << ans << endl;
    return 0;
}