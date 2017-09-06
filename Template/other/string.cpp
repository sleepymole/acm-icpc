#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 2000010;

void pre_kmp(char x[], int n, int fail[]) {
    int i = 0, j = fail[0] = -1;
    while (i < n) {
        while (-1 != j && x[i] != x[j]) j = fail[j];
        if (x[++i] == x[++j])
            fail[i] = fail[j];
        else
            fail[i] = j;
    }
}

int p[MAXN];
int manacher(const char* str) {
    static char s[MAXN];
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        s[2 * i] = '#';
        s[2 * i + 1] = str[i];
    }
    s[2 * len] = '#';
    len = 2 * len + 1;
    int pos = 0, max_right = 0, res = 0;
    for (int i = 0; i < len; i++) {
        p[i] = 1;
        if (i < max_right) p[i] = min(p[2 * pos - i], max_right - i + 1);
        while (i - p[i] >= 0 && i + p[i] < len && s[i - p[i]] == s[i + p[i]])
            p[i]++;
        if (p[i] + i - 1 > max_right) {
            max_right = p[i] + i - 1;
            pos = i;
        }
        res = max(res, p[i]);
    }
    return res - 1;
}

int main() {
    cout << manacher("abcdabc") << endl;
    return 0;
}