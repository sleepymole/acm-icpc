#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int ca = 1; ca <= T; ca++) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        int n = s.length(), ans = 0;
        for (int i = 0; i + k <= n; i++) {
            if (s[i] == '-') {
                for (int j = i; j < i + k; j++) {
                    s[j] = s[j] == '-' ? '+' : '-';
                }
                ans++;
            }
        }
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (s[i] == '-') {
                flag = false;
                break;
            }
        }
        cout << "Case #" << ca << ": ";
        if (flag)
            cout << ans << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}