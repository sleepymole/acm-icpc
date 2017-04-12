#include <assert.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
typedef __int128 int128;
const int MAXS = 1 << 21;
ll P[20], S[20][20], K, M, MAX;
char buf[MAXS];
int ptr;
inline void init() { fread(buf, 1, MAXS, stdin); }
inline char GetChar() { return buf[ptr++]; }
int cnt;
inline ll Read() {
    ll x = 0;
    char ch = GetChar();
    while (ch < '0' || ch > '9') ch = GetChar();
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = GetChar();
    }
    return x;
}

void exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) {
        x = a;
        y = 0;
    } else {
        exgcd(b, a % b, y, x);
        y -= x * (a / b);
    }
}

ll inverse(ll a, ll m) {
    ll x, y;
    exgcd(a, m, x, y);
    return (x + m) % m;
}

ll A[MAXS], B[MAXS];
int alen, blen;
int n, state;
void dfs(int pos, ll num, ll X[], int &len) {
    if ((state & ((1 << n) - 1)) == 0) return;
    if (pos == n) {
        X[len++] = num;
        return;
    }
    if (state & (1 << pos)) {
        for (int i = 1; i <= S[pos][0]; i++) {
            dfs(pos + 1, (num + S[pos][i]) % M, X, len);
        }
    } else {
        dfs(pos + 1, num, X, len);
    }
}

int ub(int s, int e, ll x[], ll v) {
    if (s == e) return e;
    if (x[s] > v) return s;
    if (x[e - 1] <= v) return e;
    while (s < e) {
        int mid = (s + e) >> 1;
        if (x[mid] > v)
            e = mid;
        else
            s = mid + 1;
    }
    return e;
}

int lb(int s, int e, ll x[], ll v) {
    if (s == e) return e;
    if (x[s] >= v) return s;
    if (x[e - 1] < v) return e;
    while (s < e) {
        int mid = (s + e) >> 1;
        if (x[mid] >= v)
            e = mid;
        else
            s = mid + 1;
    }
    return e;
}

ll calc(ll k) {
    int pos = ub(0, blen, B, k - A[0]);
    int pos1 = lb(pos, blen, B, M - A[0]);
    int pos2 = ub(pos, blen, B, M + k - A[0]);
    ll ret = pos + pos2 - pos1;
    for (int i = 1; i < alen; i++) {
        ll v = A[i];
        pos = ub(0, pos, B, k - v);
        pos1 = lb(pos, pos1, B, M - v);
        pos2 = ub(pos, pos2, B, M + k - v);
        ret += pos + pos2 - pos1;
    }
    return ret;
}

int main() {
    init();
    int t = Read();
    K = Read(), M = 1, MAX = 1, n = 0;
    while (t--) {
        S[n][0] = Read();
        P[n] = Read();
        for (int i = 1; i <= S[n][0]; i++) S[n][i] = Read();
        if (P[n] != 1) {
            MAX = MAX * S[n][0];
            M = M * P[n];
            n++;
        }
    }
    for (int i = 0; i < n; i++) {
        ll inv = inverse(M / P[i], P[i]);
        for (int j = 1; j <= S[i][0]; j++) {
            S[i][j] = int128(M / P[i] * S[i][j]) * inv % M;
        }
    }
    ll d = MAX;
    state = 0;
    for (int i = 0; i < (1 << n); i++) {
        ll tmp = 1;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                tmp *= S[j][0];
            }
        }
        if (abs(MAX / tmp - tmp) < d) {
            d = abs(MAX / tmp - tmp);
            state = i;
        }
    }
    dfs(0, 0, A, alen);
    state = ~state;
    dfs(0, 0, B, blen);
    sort(A, A + alen);
    sort(B, B + blen);
    ll k = K % MAX;
    if (k == 0) k = MAX;
    ll ans = 0;
    if (alen == 0) {
        ans = (B[k - 1] + ((K - k) / MAX) % mod * (M % mod)) % mod;
    } else if (blen == 0) {
        ans = (A[k - 1] + ((K - k) / MAX) % mod * (M % mod)) % mod;
    } else {
        ll l = 0, r = M;
        while (r - l > 1) {
            ll mid = (l + r) / 2;
            if (calc(mid) >= k)
                r = mid;
            else
                l = mid;
        }
        ans = (r + ((K - k) / MAX) % mod * (M % mod)) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}