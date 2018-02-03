#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>

const int MAXN = 200010;

int vis[MAXN], num[MAXN];

std::unordered_set<int> graph[MAXN];

int main() {
    int n, m;
    std::cin >> n >> m;
    while (m--) {
        int x, y;
        std::cin >> x >> y;
        graph[x].insert(y);
        graph[y].insert(x);
    }
    std::unordered_set<int> node;
    for (int i = 1; i <= n; ++i) {
        node.insert(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            std::queue<int> Q;
            Q.push(i);
            node.erase(i);
            vis[i] = i;
            while (!Q.empty()) {
                int u = Q.front();
                Q.pop();
                std::queue<int> tmp;
                for (auto v : node) {
                    if (graph[u].find(v) == graph[u].end()) {
                        Q.push(v);
                        vis[v] = i;
                        tmp.push(v);
                    }
                }
                while (!tmp.empty()) {
                    node.erase(tmp.front());
                    tmp.pop();
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        ++num[vis[i]];
    }
    std::sort(num + 1, num + n + 1);
    int first = 1;
    while (!num[first]) ++first;
    std::cout << n - first + 1 << "\n";
    for (int i = first; i < n; ++i) {
        std::cout << num[i] << " ";
    }
    std::cout << num[n] << std::endl;
    return 0;
}