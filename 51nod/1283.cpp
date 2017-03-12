#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int S;
    cin >> S;
    int x = (int) (sqrt(S) + 0.5);
    while (S % x != 0) x--;
    cout << 2 * (x + S / x) << endl;
    return 0;
}