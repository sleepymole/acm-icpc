#include <iostream>
using namespace std;
typedef long long ll;

void format(ll &x) {
    if (x > 0)
        x = 1;
    else if (x < 0)
        x = -1;
}
bool check(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
    ll a = (y2 - y1) * x3 - (x2 - x1) * y3 + x2 * y1 - x1 * y2;
    ll b = (y2 - y1) * x4 - (x2 - x1) * y4 + x2 * y1 - x1 * y2;
    ll c = (y4 - y3) * x1 - (x4 - x3) * y1 + x4 * y3 - x3 * y4;
    ll d = (y4 - y3) * x2 - (x4 - x3) * y2 + x4 * y3 - x3 * y4;
    format(a);
    format(b);
    format(c);
    format(d);
    return (a * b <= 0) & (c * d <= 0);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if (check(x1, y1, x2, y2, x3, y3, x4, y4))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}