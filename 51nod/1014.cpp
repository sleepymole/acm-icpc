#include <iostream>
using namespace std;
typedef long long ll;
int main() {
    int P, A;
    cin >> P >> A;
    bool flag = false;
    for (int i = 0; i <= P; i++) {
        if ((ll) i * i % P == A) {
            flag = true;
            cout << i << " ";
        }
    }
    if (!flag) cout << "No Solution";
    cout << endl;
    return 0;
}