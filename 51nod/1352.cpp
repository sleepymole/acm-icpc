#include <iostream>
using namespace std;
typedef long long ll;

void gcd(ll a, ll b, ll &d, ll &x, ll &y) {
    if (!b) {
        d = a;
        x = 1;
        y = 0;
    } else {
        gcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}

ll ceil(ll x, ll y) {  //向上取整
    ll s = x / y;
    return (s < 0 || x % y == 0) ? s : s + 1;
}

ll floor(ll x, ll y) {  //向下取整
    ll s = x / y;
    return (s > 0 || x % y == 0) ? s : s - 1;
}
int main() {
    int t;
    cin >> t;
    ll n, a, b;
    while (t--) {
        cin >> n >> a >> b;
        ll x, y, d;
        gcd(a, b, d, x, y);
        if ((n + 1) % d != 0)
            cout << 0 << endl;
        else {
            x *= (n + 1) / d;
            y *= (n + 1) / d;
            a /= d;
            b /= d;
            ll l = max(ceil(1 - x, b), ceil(y - n, a));
            ll r = min(floor(n - x, b), floor(y - 1, a));
            if (r >= l)
                cout << r - l + 1 << endl;
            else
                cout << 0 << endl;
        }
    }
    return 0;
}