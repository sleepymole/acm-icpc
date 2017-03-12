#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int pow(int a, int n) {
    int r = 1;
    while (n) {
        if (n % 2) r *= a;
        a *= a;
        n /= 2;
    }
    return r;
}
int work(int n) {  //计算所有的n位数有多少个1
    if (n == 1) return 1;
    if (n == 0) return 0;
    return 10 * work(n - 1) + pow(10, n - 1);
}
int solve(int num) {  // 12
    if (num == 0) return 0;
    if (num < 10) return 1;
    char str[15];
    sprintf(str, "%d", num);
    int n = strlen(str);
    int ans = 0;
    ans += work(n - 1);
    int lead = str[0] - '0';
    for (int i = 1; i < lead; i++) {
        if (i == 1)
            ans += work(n - 1) + pow(10, n - 1);
        else
            ans += work(n - 1);
    }
    int r = num % pow(10, n - 1);
    ans += solve(r);
    if (lead == 1) ans += r + 1;
    return ans;
}
int main() {
    int n;
    while (cin >> n) {
        cout << solve(n) << endl;
    }
    return 0;
}