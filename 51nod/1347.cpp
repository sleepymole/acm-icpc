#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1000010;
char str[maxn];

bool check(char *s, int len) {
    if (len % 2) return false;
    int mid = len / 2;
    for (int i = 0; i < len; i++) {
        if (s[i] != s[(i + mid) % len]) {
            return false;
        }
    }
    return true;
}
int main() {
    scanf("%s", str);
    int len = strlen(str);
    if (check(str, len))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}