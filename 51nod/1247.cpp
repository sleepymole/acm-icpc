#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll a, b, x, y;
        cin >> a >> b >> x >> y;
        if (gcd(a, b) == gcd(x, y))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}