#include <iostream>
using namespace std;

int main() {
    int n, l;
    while (cin >> n >> l) {
        int x;
        int minLen = 0, maxLen = 0;
        for (int i = 0; i < n; i++) {
            cin >> x;
            minLen = max(minLen, min(x, l - x));
            maxLen = max(maxLen, max(x, l - x));
        }
        cout << minLen << " " << maxLen << endl;
    }
    return 0;
}