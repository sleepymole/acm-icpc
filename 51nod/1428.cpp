#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 10001;
struct Activity {
    int s, e;
    bool operator<(const Activity& rhs) const {
        return s < rhs.s || (s == rhs.s && rhs.e < rhs.e);
    }
} a[maxn];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].s >> a[i].e;
    }
    sort(a, a + n);
    priority_queue<int, vector<int>, greater<int> > q;
    q.push(a[0].e);
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (a[i].s < q.top())
            ans++;
        else
            q.pop();
        q.push(a[i].e);
    }
    cout << ans << endl;
    return 0;
}