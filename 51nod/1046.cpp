#include <iostream>
using namespace std;
typedef long long ll;

int pow(int a, int n, int mod) {
    int r = 1;
    while (n) {
        if (n % 2) r = (ll) r * a % mod;
        a = (ll) a * a % mod;
        n /= 2;
    }
    return r;
}

int main() {
    int a, n, mod;
    cin >> a >> n >> mod;
    cout << pow(a, n, mod) << endl;
    return 0;
}