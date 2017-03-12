#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll C, Hr, Hb, Wr, Wb;
    cin >> C >> Hr >> Hb >> Wr >> Wb;
    ll ans = 0;
    for (int i = 0; i * i <= C; i++) {
        if (i * Wr <= C) ans = max(ans, i * Hr + (C - i * Wr) / Wb * Hb);
        if (i * Wb <= C) ans = max(ans, (C - i * Wb) / Wr * Hr + i * Hb);
    }
    cout << ans << endl;
    return 0;
}
