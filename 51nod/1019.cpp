#include <iostream>
using namespace std;
int a[50010];
int b[50010];
int count;

void merge(int *a, int *b, int l, int r) {
    int mid = (l + r) / 2;
    int i = l, k = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else {
            b[k++] = a[j++];
            count += (mid - i + 1);
        }
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
}

void mergesort(int *a, int *b, int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    mergesort(b, a, l, mid);
    mergesort(b, a, mid + 1, r);
    merge(a, b, l, r);
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    mergesort(a, b, 0, n - 1);
    cout << count << endl;
    return 0;
}