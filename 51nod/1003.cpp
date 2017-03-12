#include <iostream>
using namespace std;

int solve(int n) {
    int r = 1, k = 0;
    while (5 * r <= n) {
        r *= 5;
        k++;
    }
    int ans = 0;
    while (k) {
        ans += n / r;
        k--;
        r /= 5;
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}