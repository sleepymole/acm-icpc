#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> v[1001];
int main() {
    int n, H, h, p;
    cin >> n >> H;
    for (int i = 0; i < n; i++) {
        cin >> h >> p;
        if (H - h < n)
            v[H - h].push_back(p);
        else
            v[n].push_back(p);
    }
    int ans = 0, s = 0;
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 1; i <= n; i++) {
        while ((int) q.size() >= i) {
            s -= q.top();
            q.pop();
        }
        for (int j = 0; j < (int) v[i].size(); j++) {
            q.push(v[i][j]);
            s += v[i][j];
        }
        while ((int) q.size() > i + 1) {
            s -= q.top();
            q.pop();
        }
        ans = max(ans, s);
    }
    cout << ans << endl;
    return 0;
}