#include <iostream>
using namespace std;
const int maxn = 1000010;
int prime[maxn], cnt = 1;
bool sgn[maxn];

void get_prime() {
    for (int i = 2; i < maxn; i++) {
        if (!sgn[i]) {
            prime[cnt++] = i;
            for (int j = i + i; j < maxn; j += i) {
                sgn[j] = true;
            }
        }
    }
}

int main() {
    get_prime();
    int n;
    cin >> n;
    for (int i = 1; i < cnt; i++) {
        if (prime[prime[i]] >= n) {
            cout << prime[prime[i]] << endl;
            break;
        }
    }
    return 0;
}