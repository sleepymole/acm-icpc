#include<iostream>
#include<cstring>
#include<stdint.h>
#include<cstdio>
#include<map>
using namespace std;
const int P = 1000000007;
const int maxn = 1000;
int a[maxn];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 0;i < n;i++) {
            scanf("%d", &a[i]);
        }
        map<int, int>f;
        for (int i = 1;i*i <= k;i++) {
            if (k%i == 0) f[i] = f[k / i] = 0;
        }
        map<int, int>::iterator it;
        for (int i = 0;i < n;i++) {
            it = f.end(); it--;
            for(;;it--) {
                int val = it->first*a[i];
                if (f.count(val)) f[val] = (f[val] + it->second) % P;
                if (it == f.begin()) break;
            }
            if (f.count(a[i])) f[a[i]]++;
        }
        printf("%d\n", f[k]);
    }
    return 0;
}