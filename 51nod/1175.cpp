#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 50010;
int nums[MAX], sorted[MAX], root[MAX];

int cnt;
struct TMD {
    int sum, L_son, R_son;
} Tree[MAX << 5];

inline int CreateNode(int _sum, int _L_son, int _R_son) {
    int idx = ++cnt;
    Tree[idx].sum = _sum;
    Tree[idx].L_son = _L_son;
    Tree[idx].R_son = _R_son;
    return idx;
}

void Insert(int &root, int pre_rt, int pos, int L, int R) {
    root = CreateNode(Tree[pre_rt].sum + 1, Tree[pre_rt].L_son,
                      Tree[pre_rt].R_son);
    if (L == R) return;
    int M = (L + R) >> 1;
    if (pos <= M)
        Insert(Tree[root].L_son, Tree[pre_rt].L_son, pos, L, M);
    else
        Insert(Tree[root].R_son, Tree[pre_rt].R_son, pos, M + 1, R);
}

int Query(int S, int E, int L, int R, int K) {
    if (L == R) return L;
    int M = (L + R) >> 1;
    int sum = Tree[Tree[E].R_son].sum - Tree[Tree[S].R_son].sum;
    if (K > sum)
        return Query(Tree[S].L_son, Tree[E].L_son, L, M, K - sum);
    else
        return Query(Tree[S].R_son, Tree[E].R_son, M + 1, R, K);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
        sorted[i] = nums[i];
    }
    sort(sorted + 1, sorted + n + 1);
    int num = unique(sorted + 1, sorted + 1 + n) - sorted - 1;
    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(sorted + 1, sorted + num + 1, nums[i]) - sorted;
        Insert(root[i], root[i - 1], pos, 1, num);
    }
    int l, r, k, q;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d%d", &l, &r, &k);
        l++, r++;
        int pos = Query(root[l - 1], root[r], 1, num, k);
        printf("%d\n", sorted[pos]);
    }
    return 0;
}