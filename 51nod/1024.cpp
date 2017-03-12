#include <iostream>
#include <set>
using namespace std;
typedef long long ll;
const int mod1 = 1321897392;
const int mod2 = 1043728649;
const int mod3 = 1037218478;
int kpow(int a, int n, int p) {
    int r = 1;
    while (n) {
        if (n % 2) r = (ll) r * a % p;
        a = (ll) a * a % p;
        n /= 2;
    }
    return r;
}

int main() {
    int m, n, a, b;
    cin >> m >> n >> a >> b;
    set<int> s1;
    set<int> s2;
    set<int> s3;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x = kpow(a + j, b + i, mod1);
            int y = kpow(a + j, b + i, mod2);
            int z = kpow(a + j, b + i, mod3);
            if (s1.find(x) == s1.end() && s2.find(y) == s2.end() &&
                s3.find(z) == s3.end())
                ans++;
            s1.insert(x);
            s2.insert(y);
            s3.insert(z);
        }
    }
    cout << ans << endl;
    return 0;
}