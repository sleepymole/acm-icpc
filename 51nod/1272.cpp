#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 50010;
int a[maxn];

int main() {
    vector<int> q;
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (q.size() == 0 || a[q.back()] > a[i]) {
            q.push_back(i);
        } else {
            int l = 0, r = q.size() - 1;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (a[q[mid]] <= a[i])
                    r = mid;
                else
                    l = mid;
            }
            if (a[q[l]] <= a[i]) r = l;
            ans = max(ans, i - q[r]);
        }
    }
    cout << ans << endl;
    return 0;
}