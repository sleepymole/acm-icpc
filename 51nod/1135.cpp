#include <iostream>
using namespace std;
const int maxn = 100010;
typedef long long ll;
int prime[maxn], cnt;
bool sgn[maxn];
int factor[20], tot;
void get_prime() {
    for (int i = 2; i < maxn; i++) {
        if (!sgn[i]) {
            prime[cnt++] = i;
            for (int j = i + i; j < maxn; j += i) {
                sgn[j] = true;
            }
        }
    }
}
int quick_mod(int a, int n, int p) {
    int r = 1;
    while (n) {
        if (n % 2) r = (ll) r * a % p;
        a = (ll) a * a % p;
        n /= 2;
    }
    return r;
}

bool check(int x, int p) {
    for (int i = 0; i < tot; i++) {
        if (quick_mod(x, (p - 1) / factor[i], p) == 1) return false;
    }
    return true;
}
int main() {
    get_prime();
    int p;
    cin >> p;
    int k = p - 1;
    for (int i = 0; i < cnt; i++) {
        if (k % prime[i] == 0) {
            factor[tot++] = prime[i];
            while (k % prime[i] == 0) {
                k /= prime[i];
            }
        }
        if (k == 1) break;
    }
    if (k > 1) factor[tot++] = k;
    int x;
    for (x = 2; x < p; x++) {
        if (check(x, p)) break;
    }
    cout << x << endl;
    return 0;
}