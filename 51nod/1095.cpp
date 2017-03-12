#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
using namespace std;
int BKDR_hash(char *str) {
    unsigned int seed = 131;
    unsigned int hash = 0;
    while (*str) {
        hash = hash * seed + (*str++);
    }
    return (hash & 0x7FFFFFFF);
}
int main() {
    int N;
    cin >> N;
    map<int, int> mp1;
    map<int, int> mp2;
    char str[20];
    int hash, len;
    for (int i = 0; i < N; i++) {
        scanf("%s", str);
        hash = BKDR_hash(str);
        mp1[hash]++;
        len = strlen(str);
        sort(str, str + len);
        hash = BKDR_hash(str);
        mp2[hash]++;
    }
    int Q, hash1, hash2;
    cin >> Q;
    while (Q--) {
        scanf("%s", str);
        len = strlen(str);
        hash1 = BKDR_hash(str);
        sort(str, str + len);
        hash2 = BKDR_hash(str);
        cout << mp2[hash2] - mp1[hash1] << endl;
    }
    return 0;
}