#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll A, B, P, Q, d;
        cin >> A >> B;
        P = A + 3 * B;
        Q = 4 * (A + B);
        d = gcd(P, Q);
        P /= d;
        Q /= d;
        cout << P << "/" << Q << endl;
    }
    return 0;
}