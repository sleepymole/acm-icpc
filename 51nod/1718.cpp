#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int64_t n;
    cin >> n;
    int ans[] = {2, 1, -1, -2, -1, 1};
    cout << ans[n % 6] << endl;
    return 0;
}