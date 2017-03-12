#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, l;
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > q;
    while (n--) {
        cin >> l;
        q.push(l);
    }
    int ans = 0;
    while (q.size() >= 2) {
        int x1 = q.top();
        q.pop();
        int x2 = q.top();
        q.pop();
        ans += x1 + x2;
        q.push(x1 + x2);
    }
    cout << ans << endl;
    return 0;
}