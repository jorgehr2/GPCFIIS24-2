#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
#define all(s) s.begin(), s.end()
using namespace std;
typedef long long ll;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
#define Repi0(i, n) for (ll i = n - 1; i >= 0; i--)
#define Repi1(i, n) for (ll i = n; i >= 1; i--)
#define POT(x) ((x) * (x))
const ll MX = 2e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);
typedef long double ld;
typedef unsigned long long ull;

ll getBit(ll x, ll i) {
    return (x >> i) & 1;
}

// n nodos , n e [1,1e5];
// m aristas, m e [1,2e6];
vector<ll> adj[MX];
bool usado[MX];
ll cont = 0;
ll profundidad[MX], padre[MX], hijos[MX], tiempo_entrada[MX], tiempo_salida[MX];
void dfs(ll nodo_actual, ll prof, ll pap) {
    cont++;
    tiempo_entrada[nodo_actual] = cont;
    profundidad[nodo_actual] = prof;
    usado[nodo_actual] = true;
    padre[nodo_actual] = pap;
    for (ll i = 0; i < adj[nodo_actual].size(); i++) {
        if (usado[adj[nodo_actual][i]] == false) {
            dfs(adj[nodo_actual][i], prof + 1, nodo_actual);
            hijos[nodo_actual] += hijos[adj[nodo_actual][i]] + 1;
        }
    }
    cont++;
    tiempo_salida[nodo_actual] = cont;
}

int main() {
    inic;
    inic2;
    ll n;
    cin >> n;
    ll cont = n - 1;
    while (cont--) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(3, 0, 3);
    Rep1(i, n) {
        cout << "hijos: " << hijos[i] << endl;
    }
    return 0;
}