#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 50010;
int arr[maxn], ans[maxn], len;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    ans[1] = arr[1];
    len = 1;
    for (int i = 2; i <= n; i++) {
        if (arr[i] > ans[len]) {
            ans[++len] = arr[i];
        } else {
            int pos = lower_bound(ans + 1, ans + len + 1, arr[i]) - ans;
            ans[pos] = arr[i];
        }
    }
    cout << len << endl;
    return 0;
}