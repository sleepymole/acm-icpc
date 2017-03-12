#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int x, r = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        r ^= x;
    }
    cout << (x % 2 ? 'A' : 'B') << endl;
    return 0;
}