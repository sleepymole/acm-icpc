#include <iostream>
using namespace std;
typedef long long ll;
int main() {
    int n;
    cin >> n;
    ll x, max = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x + sum >= 0)
            sum += x;
        else
            sum = 0;
        if (sum > max) max = sum;
    }
    cout << max << endl;
    return 0;
}