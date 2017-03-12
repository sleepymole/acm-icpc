#include <cmath>
#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll ans = (ll)((n * (log(n) - 1) + 0.5 * log(2 * acos(-1.0) * n)) /
                      (log(10))) +
                 1;
        cout << ans << endl;
    }
    return 0;
}