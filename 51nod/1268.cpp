#include <iostream>
using namespace std;
typedef long long ll;
int main() {
    ll n, k, a[25];
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool found = false;
    for (int i = 0; i < (1 << n); i++) {
        ll sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) sum += a[j];
        }
        if (sum == k) {
            found = true;
            break;
        }
    }
    if (found)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}