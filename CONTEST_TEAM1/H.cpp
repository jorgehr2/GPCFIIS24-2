/*
...............................................................................
./////////////..............//\\............./////////////////..\\..........//.
.//........................//..\\............//..................\\........//..
.//.......................//....\\...........//...................\\......//...
.//......................//......\\..........//....................\\....//....
.//.....................//........\\.........//.....................\\..//.....
.//....................//..........\\........//......................\\//......
.////////////.........//////////////\\......./////////////////........//.......
.//..................//..............\\.....................//........//.......
.//.................//................\\....................//........//.......
.//................//..................\\...................//........//.......
.//...............//....................\\..................//........//.......
.//..............//......................\\.................//........//.......
./////////////..//........................\\..////////////////........//.......
...............................................................................
*/
#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (Long i = 0; i < (Long)n; i++)
#define debug(x) cout << #x << " = " << x << endl;
#define pb push_back
#define pf push_front
#define all(x) x.begin(), x.end()
#define FIN                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

using Long = long long;

using Path = pair<Long, int>;
const Long INF = 1e18;

struct Graph {
    vector<vector<pair<int, Long>>> adj;
    vector<int> parent;
    vector<Long> d;

    Graph(int n) {
        adj.resize(n);
    }

    void addEdge(int u, int v, Long w) {
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w});
    }

    void dijkstra(int s) { // O(E log V)
        int n = adj.size();
        parent = vector<int>(n, -1);
        d = vector<Long>(n, INF);
        priority_queue<Path, vector<Path>, greater<Path>> q;
        d[s] = 0;
        q.push({d[s], s});
        while (!q.empty()) {
            auto [weight, u] = q.top();
            q.pop();
            if (weight != d[u]) continue;
            for (auto [v, w] : adj[u]) {
                if (d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                    parent[v] = u;
                    q.push({d[v], v});
                }
            }
        }
    }
};

const Long c = 26;
Long change[c][c];

int main() {
    FIN;
    Graph G = Graph(c);
    REP(i, c) {
        REP(j, c) {
            Long d;
            cin >> d;
            G.addEdge(i, j, d);
        }
    }
    string s, r;
    cin >> s;
    r = s;
    int n = s.size();
    reverse(all(r));

    Graph G2 = G;

    REP(i, c) {
        G2 = G;
        G2.dijkstra(i);
        REP(j, c) {
            change[i][j] = G2.d[j];
        }
    }

    Long cost = 0;
    REP(i, n / 2) {
        if (s[i] != r[i]) {
            int a = s[i] - 'a', b = r[i] - 'a';
            Long mi = 27 * 1e6;
            REP(u, c) {
                mi = min(mi, change[a][u] + change[b][u]);
            }
            cost += mi;
        }
    }
    cout << cost << endl;

    return 0;
}