#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, X, x;
    cin >> N >> X;
    vector<int> y;
    for (int i = 0; i < N; i++) {
        cin >> x;
        if ((x & (~X)) == 0) {
            y.push_back(x);
        }
    }
    int ans = y.size();
    for (int i = 0; i <= 30; i++) {
        if (((1 << i) & X) == 0) continue;
        int tot = 0;
        for (int j = 0; j < y.size(); j++) {
            if (y[j] & (1 << i)) tot++;
        }
        ans = min(ans, tot);
    }
    cout << ans << endl;
    return 0;
}