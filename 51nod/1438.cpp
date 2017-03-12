#include <stdint.h>
#include <cmath>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;
const int N = 64;
const int cap = 4987;
int64_t mat[N][N], sum[N];

struct Hash {
    struct Node {
        int next;
        int64_t val;
    } e[cap];
    int pre[cap], tot;
    Hash() : tot(0) { memset(pre, -1, cap * sizeof(int)); }
    bool find(int64_t val) {
        for (int i = pre[val % cap]; i != -1; i = e[i].next) {
            if (e[i].val == val) return true;
        }
        return false;
    }
    void insert(int64_t val) {
        int index = val % cap;
        e[tot].val = val;
        e[tot].next = pre[index];
        pre[index] = tot++;
    }
};

bool isSqaure(int64_t n) {
    int64_t x = int64_t(sqrt(n) + 0.5);
    return x * x == n;
}

int64_t Sqrt(int64_t n) { return int(sqrt(n) + 0.5); }

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "No Solution" << endl;
        return 0;
    }
    set<int> st;
    set<int>::iterator it;
    for (int i = 1; i <= n * n; i++) {
        st.insert(i);
    }
    Hash h1, h2;
    for (int i = 0; i < n - 1; i++) {
        int m = 0;
        for (int j = 0; j < n - 1; j++) {
            for (it = st.begin(); it != st.end(); it++) {
                if (!h1.find(*it)) {
                    int val = *it;
                    m += val;
                    sum[j] += val;
                    mat[i][j] = val;
                    h1.insert(val);
                    st.erase(val);
                    break;
                }
            }
        }
        int x = sqrt(m);
        while (x * x <= m) x++;
        while (h1.find(x * x - m) || h2.find(x)) x++;
        mat[i][n - 1] = x * x - m;
        sum[n - 1] += x * x - m;
        h1.insert(x * x - m);
        h2.insert(x);
    }
    int m = 0;
    for (int j = 0; j < n - 2; j++) {
        int x = sqrt(sum[j]);
        while (x * x <= sum[j]) x++;
        while (h1.find(x * x - sum[j]) || h2.find(x)) x++;
        mat[n - 1][j] = x * x - sum[j];
        h1.insert(x * x - sum[j]);
        h2.insert(x);
        m += x * x - sum[j];
    }
    int64_t x = sqrt(sum[n - 2]);
    int64_t sy = sqrt(sum[n - 1]);
    while (x * x <= sum[n - 2]) x++;
    while (sy * sy <= sum[n - 1]) sy++;
    while (h1.find(x * x - sum[n - 2]) || h2.find(x)) x++;
    while (h1.find(sy * sy - sum[n - 1]) || h2.find(sy)) sy++;
    int64_t a = m + x * x - sum[n - 2], d = abs(a - sum[n - 1]), y = sy;
    for (;; y++) {
        if (y > 2 * d) {
            x++;
            a = m + x * x - sum[n - 2];
            d = abs(a - sum[n - 1]);
            y = sy;
        }
        if (!isSqaure(a + y * y - sum[n - 1])) continue;
        int z = Sqrt(a + y * y - sum[n - 1]);
        if (!(h2.find(x) || h2.find(y) || h2.find(z) || x == y || x == z ||
              y == z || h1.find(x * x - sum[n - 2]) ||
              h1.find(y * y - sum[n - 1])))
            break;
    }
    mat[n - 1][n - 2] = x * x - sum[n - 2];
    mat[n - 1][n - 1] = y * y - sum[n - 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cin.get();
    cin.get();
    return 0;
}