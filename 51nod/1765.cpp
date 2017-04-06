#include <cmath>
#include <cstdio>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    long long sum = (ll) n * (n - 1) / 2;
    printf("%.6f\n", 1.0 * sum / m);
    return 0;
}