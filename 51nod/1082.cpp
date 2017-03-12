#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 1000010;
ll sum[maxn];
int main() {
    char str[20];
    for (int i = 1; i < maxn; i++) {
        bool flag = true;
        if (i % 7 == 0) flag = false;
        int tmp = i;
        while (tmp) {
            if (tmp % 10 == 7) {
                flag = false;
                break;
            }
            tmp /= 10;
        }
        if (flag)
            sum[i] = sum[i - 1] + (ll) i * i;
        else
            sum[i] = sum[i - 1];
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << sum[n] << endl;
    }
    return 0;
}