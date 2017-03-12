#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int f[1010][1010];
int main() {
    string A, B;
    cin >> A >> B;
    int m = A.size();
    int n = B.size();
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[i - 1] == B[j - 1]) {
                f[i][j] = f[i - 1][j - 1] + 1;
            } else {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    string ans;
    int i = m, j = n;
    while (f[i][j]) {
        if (f[i][j] == f[i - 1][j])
            i--;
        else if (f[i][j] == f[i][j - 1])
            j--;
        else {
            ans.push_back(A[i - 1]);
            i--;
            j--;
        }
    }
    for (int i = ans.size(); i >= 0; i--) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}