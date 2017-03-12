#include <iostream>
#include <stack>
using namespace std;
const int maxn = 100010;
int a[maxn], dir[maxn];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> dir[i];
    }
    stack<int> q;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (dir[i])
            q.push(a[i]);
        else {
            if (!q.empty()) {
                if (a[i] < q.top())
                    cnt++;
                else {
                    while (!q.empty() && a[i] > q.top()) {
                        cnt++;
                        q.pop();
                    }
                    if (!q.empty()) cnt++;
                }
            }
        }
    }
    while (!q.empty()) q.pop();
    for (int i = n; i >= 1; i--) {
        if (dir[i] == 0)
            q.push(a[i]);
        else {
            if (!q.empty()) {
                if (a[i] < q.top())
                    cnt++;
                else {
                    while (!q.empty() && a[i] > q.top()) {
                        cnt++;
                        q.pop();
                    }
                    if (!q.empty()) cnt++;
                }
            }
        }
    }
    cout << n - cnt / 2 << endl;
    return 0;
}