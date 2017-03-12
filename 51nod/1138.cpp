#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    n *= 2;
    vector<int> ans;
    for (int k = 2; k * k < n; k++) {
        if (n % k == 0) {
            int x = n / k - k + 1;
            if (x > 0 && x % 2 == 0) {
                ans.push_back(x / 2);
            }
        }
    }
    sort(ans.begin(), ans.end());
    if (ans.size() == 0) cout << "No Solution" << endl;
    vector<int>::iterator it;
    for (it = ans.begin(); it != ans.end(); it++) {
        cout << (*it) << endl;
    }
    return 0;
}