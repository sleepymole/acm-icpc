#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
const int maxlen = 1000000;
char str[maxlen + 10];
int sum[maxlen + 10], low[maxlen + 10];

int main() {
    scanf("%s", str);
    int n = strlen(str);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + (str[i - 1] == '(' ? 1 : -1);
    }
    stack<int> q;
    q.push(0);
    for (int i = 1; i <= n; i++) {
        while (!q.empty() && sum[i] < sum[q.top()]) q.pop();
        if (q.empty() || sum[i] > sum[q.top()])
            low[i] = i;
        else
            low[i] = low[q.top()];
        q.push(i);
    }
    int ans = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i - low[i] == ans)
            cnt++;
        else if (i - low[i] > ans) {
            ans = i - low[i];
            cnt = 1;
        }
    }
    if (ans == 0) cnt = 1;
    cout << ans << " " << cnt << endl;
    return 0;
}