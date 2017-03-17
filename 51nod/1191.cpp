#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
const int maxn = 50010;
int B[maxn];

struct A {
    int d, p;
    bool operator<(const A& rhs) const {
        return p > rhs.p || (p == rhs.p && d > rhs.d);
    }
};

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    multiset<int, greater<int>> st;
    for (int i = 0; i < n; i++) {
        int b;
        scanf("%d", &b);
        st.insert(b);
    }
    priority_queue<A> q;
    for (int i = 0; i < m; i++) {
        int d, p;
        scanf("%d%d", &d, &p);
        q.push({d, p});
    }
    long long ans = 0;
    multiset<int, greater<int>>::iterator it;
    while (st.size() && q.size()) {
        A tmp = q.top();
        q.pop();
        it = st.lower_bound(tmp.d);
        if (it != st.end()) {
            ans += tmp.p;
            st.erase(it);
        }
    }
    if (st.size())
        puts("No Solution");
    else
        printf("%lld\n", ans);
    return 0;
}