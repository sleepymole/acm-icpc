#include<iostream>
using namespace std;
int a[40], x[20], y[20], n;

bool found;
void dfs(int l, int r, int pos) {
    if (pos == n) {
        found = true;
        return;
    }
    if (l == n / 2) {
        y[r] = a[pos];
        if(y[r]==x[r]) dfs(l, r + 1, pos + 1);
    }else if (r == n/2) {
        x[l] = a[pos];
        if (x[l] == y[l]) dfs(l + 1, r, pos + 1);
    }
    else if (l == r) {
        x[l] = a[pos];
        dfs(l + 1, r, pos + 1);
        if (found) return;
        y[r] = a[pos];
        dfs(l, r + 1, pos + 1);
    }
    else {
        x[l] = a[pos];
        if (l > r || (l < r&&x[l] == y[l])) dfs(l + 1, r, pos + 1);
        if (found) return;
        y[r] = a[pos];
        if (l < r || (l > r&&x[r] == y[r])) dfs(l, r + 1, pos + 1);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 0;i < n;i++) {
            cin >> a[i];
        }
        found = false;
        dfs(0, 0, 0);
        if (found) cout << "Good job!!" << endl;
        else cout << "What a pity!" << endl;
    }
    return 0;
}