#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
const double Pi = acos(-1.0);

int main() {
    double S;
    cin >> S;
    double ans = sqrt(S * S * S / 72 / Pi);
    printf("%lf\n", ans);
    return 0;
}