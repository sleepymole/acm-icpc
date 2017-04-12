#include <iostream>
using namespace std;
typedef long long ll;
int digit[20];

int main() {
    int T;
    cin >> T;
    for (int ca = 1; ca <= T; ca++) {
        ll N;
        cin >> N;
        int len = 0;
        ll tmp = N;
        while (tmp) {
            digit[len++] = tmp % 10;
            tmp /= 10;
        }
        int l = 0, r = len - 1;
        while (l < r) swap(digit[l++], digit[r--]);
        int pos = -1;
        for (int i = 0; i < len - 1; i++) {
            if (digit[i] > digit[i + 1]) {
                pos = i;
                break;
            }
        }
        ll ans = 0;
        if (pos == -1)
            ans = N;
        else {
            digit[pos]--;
            int p = pos;
            for (int i = pos - 1; i >= 0; i--) {
                if (digit[i] > digit[i + 1]) {
                    digit[i]--;
                    p = i;
                } else {
                    break;
                }
            }
            for (int i = p + 1; i < len; i++) digit[i] = 9;
            if (digit[0] <= 0) {
                len--;
                for (int i = 0; i < len; i++) digit[i] = 9;
            }
            for (int i = 0; i < len; i++) {
                ans = ans * 10 + digit[i];
            }
        }
        cout << "Case #" << ca << ": " << ans << endl;
    }
    return 0;
}