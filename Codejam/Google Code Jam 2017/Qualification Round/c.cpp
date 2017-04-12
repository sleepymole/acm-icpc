#include <iostream>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
    freopen("/home/xyj/c.out","w",stdout);
    int T;
    cin >> T;
    for (int ca = 1; ca <= T; ca++) {
        ll N, K;
        cin >> N >> K;
        map<ll, ll> mp;
        mp[N] = 1;
        ll count = 1;
        while (K > count) {
            map<ll, ll> tmp;
            K -= count;
            count = 0;
            for (auto x : mp) {
                ll len = x.first;
                ll a = (len - 1) / 2, b = len - 1 - a;
                ll t = x.second;
                if (a > 0) {
                    tmp[a] += t;
                    count += t;
                }
                if (b > 0) {
                    tmp[b] += t;
                    count += t;
                }
            }
            mp = tmp;
        }
        ll x, y;
        if (mp.size() == 1) {
            ll a = mp.begin()->first;
            y = (a - 1) / 2;
            x = a - 1 - y;
        } else {
            ll a = mp.begin()->first;
            ll b = mp.rbegin()->first;
            ll v = K <= mp[b] ? b : a;
            y = (v - 1) / 2;
            x = v - 1 - y;
        }
        if (x < y) swap(x, y);
        cout << "Case #" << ca << ": " << x << " " << y << endl;
    }
    return 0;
}