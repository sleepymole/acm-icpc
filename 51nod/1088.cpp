#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1010;
char s[maxn * 2];
int RL[maxn * 2];

int manacher(char str[]) {
    int l = 0;
    s[l++] = '#';
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        s[l++] = str[i];
        s[l++] = '#';
    }
    len = 2 * len + 1;
    int pos = 0, MaxRight = 0;
    int MaxLen = 0;
    for (int i = 0; i < len; i++) {
        if (i < MaxRight) {
            RL[i] = min(RL[2 * pos - i], MaxRight - i);
        } else {
            RL[i] = 1;
        }
        while (i - RL[i] >= 0 && i + RL[i] < len &&
               s[i - RL[i]] == s[i + RL[i]]) {
            RL[i]++;
        }
        if (RL[i] + i - 1 > MaxRight) {
            MaxRight = RL[i] + i - 1;
            pos = i;
        }
        MaxLen = max(MaxLen, RL[i]);
    }
    return MaxLen - 1;
}
char str[maxn];
int main() {
    scanf("%s", str);
    cout << manacher(str) << endl;
    return 0;
}