#include <cmath>
#include <iostream>
using namespace std;

bool check(int x) {
    int s = (int) (sqrt(x) + 0.5);
    return x == s * s;
}

int main() {
    int n;
    cin >> n;
    bool flag = false;
    for (int i = 0; i * i <= n; i++) {
        if (check(n - i * i)) {
            int j = (int) (sqrt(n - i * i) + 0.5);
            if (i <= j) cout << i << " " << j << endl;
            flag = true;
        }
    }
    if (!flag) cout << "No Solution" << endl;
    return 0;
}