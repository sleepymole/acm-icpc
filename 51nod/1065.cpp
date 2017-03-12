#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f;
const int maxn = 50010;

int main() {
    int n;
    ll x, sum = 0;
    cin >> n;
    vector<pair<ll, ll> > a;
    ll ans = INF;
    for (int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
        ;
        a.push_back(make_pair(sum, i));
        if (sum > 0) ans = min(ans, sum);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++) {
        if (a[i].first < a[i + 1].first && a[i].second < a[i + 1].second) {
            ans = min(ans, a[i + 1].first - a[i].first);
        }
    }
    cout << ans << endl;
    return 0;
}