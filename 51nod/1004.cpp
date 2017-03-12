#include <iostream>
using namespace std;

int pow(int a, int n) {
    int r = 1;
    while (n) {
        if (n % 2) r = r * a % 10;
        a = a * a % 10;
        n /= 2;
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    cout << pow(n % 10, n) << endl;
    return 0;
}