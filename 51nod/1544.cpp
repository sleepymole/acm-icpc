#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 50000;
int P;

struct Matrix {
    int data[2][2];
    Matrix operator*(const Matrix& rhs) const {
        Matrix ret = {0, 0, 0, 0};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    ret.data[i][j] =
                        (ret.data[i][j] + (ll) data[i][k] * rhs.data[k][j]) % P;
                }
            }
        }
        return ret;
    }
    Matrix operator^(ll n) {
        Matrix ret = {1, 0, 0, 1}, base = *this;
        while (n) {
            if (n & 1) ret = ret * base;
            base = base * base;
            n >>= 1;
        }
        return ret;
    }
};

struct Modify {
    ll j;
    int v;
    bool operator<(const Modify& rhs) const { return j < rhs.j; };
} e[N + 1];

Matrix D[N][16];
void init(int s[], int n) {
    for (int i = 0; i < n; i++) D[i][0] = {0, s[i], 1, s[(i + 1) % n]};
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            D[i][j] = D[i][j - 1] * D[i + (1 << (j - 1))][j - 1];
        }
    }
}

Matrix query(int l, int r) {
    Matrix ret = {1, 0, 0, 1};
    while (l <= r) {
        int k = 0;
        while (l + (1 << (k + 1)) - 1 <= r) k++;
        ret = ret * D[l][k];
        l = l + (1 << k);
    }
    return ret;
}

Matrix calc(ll l, ll r, int n) {
    if (l > r) return {1, 0, 0, 1};
    ll x = (l / n + 1);
    ll y = r / n;
    if (x > y) return query(l % n, r % n);
    return query(l % n, n - 1) * (query(0, n - 1) ^ (y - x)) * query(0, r % n);
}

int s[N + 1];
int main() {
    ios::sync_with_stdio(false);
    ll k;
    int n, m;
    cin >> k >> P >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    cin >> m;
    for (int i = 0; i < m; i++) cin >> e[i].j >> e[i].v;
    if (P == 1 || k == 0) {
        cout << "0\n";
        return 0;
    }
    if (k == 1) {
        cout << "1\n";
        return 0;
    }
    sort(e, e + m);
    init(s, n);
    Matrix ans = {1, 0, 0, 1};
    ll p = 0;
    k -= 2;
    bool found = false;
    for (int i = 0; i < m; i++) {
        if (e[i].j - 2 >= k) {
            ans = ans * calc(p, k, n);
            found = true;
            break;
        }
        ans = ans * calc(p, e[i].j - 2, n) *
              (Matrix){0, s[(e[i].j - 1) % n], 1, e[i].v};
        if (k == e[i].j - 1) {
            found = true;
            break;
        }
        while (i + 1 < m && e[i + 1].j == e[i].j + 1) {
            ans = ans * (Matrix){0, e[i].v, 1, e[i + 1].v};
            if (k == e[i].j) {
                found = true;
                break;
            }
            i++;
        }
        if (found) break;
        ans = ans * (Matrix){0, e[i].v, 1, s[(e[i].j + 1) % n]};
        if (k == e[i].j) {
            found = true;
            break;
        }
        p = e[i].j + 1;
    }
    if (!found) ans = ans * calc(p, k, n);
    cout << ans.data[1][1] << endl;
    return 0;
}