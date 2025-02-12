#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define all(v) v.begin(), v.end()

const double PI = acos(-1);

const int N = 1e5 + 5;
vector<int> g[N];

int which_tree[N];
bool vis[N];
int indegree[N];
int tIn[N];
int tOut[N];
int timer;
int root[N];
int depth[N];
int anc[N][18];
vector<int> nodes;

void dfs(int u, int tree, int cur_root) {
    which_tree[u] = tree;
    root[u] = cur_root;
    tIn[u] = timer++;
    nodes.push_back(u);
    vis[u] = true;
    for (int v : g[u]) {
        if (!vis[v]) {
            depth[v] = depth[u] + 1;
            anc[v][0] = u;
            dfs(v, tree, cur_root);
        }
    }
    tOut[u] = timer++;
}

bool isAncestor(int u, int v) {
    return tIn[u] <= tIn[v] && tOut[u] >= tOut[v];
}

int lca(int u, int v) { // O(log n)
    if (isAncestor(u, v)) return u;
    int bits = 31 - __builtin_clz(depth[u]);
    for (int i = bits; i >= 0; i--) {
        if (anc[u][i] != -1 && !isAncestor(anc[u][i], v)) {
            u = anc[u][i];
        }
    }
    return anc[u][0];
}

bool onPath(int a, int b, int c) {
    int x = lca(a, b);
    if (isAncestor(x, c) && isAncestor(c, a)) return true;
    if (isAncestor(x, c) && isAncestor(c, b)) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        if (i != v and v != -1) {
            g[v].push_back(i);
            indegree[i]++;
        }
    }
    int n_tree = 0;
    for (int i = 0; i < n; ++i) {
        if (!vis[i] and indegree[i] == 0) {
            anc[i][0] = -1;
            depth[i] = 0;
            timer = 0;
            nodes.clear();
            dfs(i, n_tree++, i);
            int m = nodes.size();
            for (int j = 1; (1 << j) < m; ++j) {
                for (int k : nodes) {
                    if (anc[k][j - 1] != -1) {
                        anc[k][j] = anc[anc[k][j - 1]][j - 1];
                    } else anc[k][j] = -1;
                }
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        if (u == v) {
            cout << "Yes" << endl;
            continue;
        }
        if (which_tree[u] != which_tree[v]) cout << "No" << endl;
        else {
            int root_a = root[u], root_b = root[v];
            assert(root_a == root_b);
            if (onPath(u, root_a, v)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}