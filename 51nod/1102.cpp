#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;
const int maxn = 50010;
int a[maxn], l[maxn], r[maxn];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    stack<int> q;
    for (int i = 1; i <= n; i++) {
        if (q.empty())
            l[i] = i;
        else {
            while (!q.empty() && a[i] < a[q.top()]) q.pop();
            if (q.empty())
                l[i] = 1;
            else
                l[i] = q.top() + 1;
        }
        q.push(i);
    }
    while (!q.empty()) q.pop();
    for (int i = n; i >= 1; i--) {
        if (q.empty())
            r[i] = i;
        else {
            while (!q.empty() && a[i] < a[q.top()]) q.pop();
            if (q.empty())
                r[i] = n;
            else
                r[i] = q.top() - 1;
        }
        q.push(i);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, (ll)(r[i] - l[i] + 1) * a[i]);
    }
    cout << ans << endl;
    return 0;
}