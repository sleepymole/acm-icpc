#include <iostream>
#include <set>
using namespace std;
const int maxn = 100010;
set<int> p;
int a, b, tail;

int dfs(int x) {
    int ret = 1;
    p.erase(x);
    if (p.count(a - x)) ret += dfs(a - x);
    if (p.count(b - x)) ret += dfs(b - x);
    if (ret == 1) tail = x;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p.insert(x);
    }
    bool found = true;
    while (!p.empty()) {
        int x = *p.begin();
        int cnt = dfs(x);
        if (cnt % 2 && x + x != a && x + x != b && tail + tail != a &&
            tail + tail != b) {
            found = false;
            break;
        }
    }
    if (found)
        puts("YES");
    else
        puts("NO");
    return 0;
}