#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 2000000;
ll d[N], cnt;

int main() {
    ll A;
    cin >> A;
    for (ll i = 2; i * i <= A; i++) {
        if (A % i == 0) {
            d[cnt++] = i;
            if (i * i != A) {
                d[cnt++] = A / i;
            }
        }
    }
    if (A > 1) d[cnt++] = A;
    map<ll, vector<ll>> mp;
    for (int i = 0; i < cnt; i++) {
        ll x = d[i] - 1;
        if (x == 1) continue;
        for (ll j = 2; j * j <= x; j++) {
            if (x % j == 0) {
                while (x % j == 0) x /= j;
                if (x == 1) mp[j].push_back(d[i]);
                break;
            }
        }
        if (x == d[i] - 1) mp[x].push_back(x + 1);
    }
    map<ll, ll> f;
    f[A] = 1;
    for (auto x : mp) {
        vector<pair<ll, ll>> v;
        for (ll y : x.second) {
            for (auto z : f) {
                if (z.first % y == 0) {
                    v.push_back(make_pair(z.first / y, z.second));
                }
            }
        }
        for (auto y : v) {
            f[y.first] += y.second;
        }
    }
    cout << f[1] << endl;
    return 0;
}