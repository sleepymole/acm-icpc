#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int L[3] = {0}, R[3] = {0}, p = 0, q = 0;
        string str;
        cin >> str;
        int n = str.length();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += p + q;
            if (str[i] == 'R') {
                if (!L[0])
                    L[0] = 1, p++;
                else if (!R[0])
                    R[0] = 1, q++;
            } else if (str[i] == 'G') {
                if (!L[1])
                    L[1] = 1, p++;
                else if (!R[1])
                    R[1] = 1, q++;
            } else {
                if (!L[2])
                    L[2] = 1, p++;
                else if (!R[2])
                    R[2] = 1, q++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}