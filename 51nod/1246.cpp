#include <iostream>
using namespace std;

int main() {
    int n, k, c;
    cin >> n >> k >> c;
    if (c <= k / n * n)
        cout << c << endl;
    else
        cout << c + n - k / (k / n + 1) << endl;
    return 0;
}