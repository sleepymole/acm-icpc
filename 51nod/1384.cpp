#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    string S;
    cin >> S;
    sort(S.begin(), S.end());
    do {
        cout << S << endl;
    } while (next_permutation(S.begin(), S.end()));
    return 0;
}