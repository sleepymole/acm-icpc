#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((a + b <= max(c, d)) || (a <= c && b <= d))
        cout << "Polycarp" << endl;
    else
        cout << "Vasiliy" << endl;
    return 0;
}