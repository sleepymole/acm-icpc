#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 5010;
char s[2 * maxn], str[maxn];
int RL[2 * maxn], dp[maxn];

void manacher() {
    int l = 0;
    s[l++] = '#';
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        s[l++] = str[i];
        s[l++] = '#';
    }
    len = 2 * len + 1;
    int pos = 0, maxRight = 0;
    for (int i = 0; i < len; i++) {
        if (i < maxRight)
            RL[i] = min(RL[2 * pos - i], maxRight - i);
        else
            RL[i] = 1;
        while (i - RL[i] >= 0 && i + RL[i] < len &&
               s[i - RL[i]] == s[i + RL[i]])
            RL[i]++;
        if (RL[i] + i - 1 > maxRight) {
            pos = i;
            maxRight = RL[i] + i - 1;
        }
    }
}

int main() {
    scanf("%s", str);
    manacher();
    int len = strlen(str);
    for (int i = 0; i < len; i++) dp[i] = len;
    for (int i = 0; i < len; i++) {
        for (int j = i; j >= 0; j--) {
            if (RL[i + j + 1] > i - j)
                dp[i] = j > 0 ? min(dp[j - 1] + 1, dp[i]) : 1;
        }
    }
    printf("%d\n", dp[len - 1]);
    return 0;
}