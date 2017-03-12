#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans =
        (int) ((n * (log(n) - 1) + 0.5 * log(2 * acos(-1.0) * n)) / (log(10))) +
        1;
    cout << ans << endl;
    return 0;
}