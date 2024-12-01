#include <bits/stdc++.h>
#define pb push_back
typedef long long ll;

using namespace std;
const ll MX = 1e5 + 2;

vector<ll> adj[MX];
bool val[MX];
ll distancia_minima[MX], padre[MX];
void bfs(vector<ll> &vec) {
    queue<ll> dd;
    for (ll i = 0; i < vec.size(); i++) {
        dd.push(vec[i]);
        distancia_minima[vec[i]] = 0;
    }

    while (!dd.empty()) {
        ll valor = dd.front();
        cout << valor << " aasd " << endl;
        dd.pop();
        for (ll i = 0; i < adj[valor].size(); i++) {
            if (val[adj[valor][i]] == false) {
                distancia_minima[adj[valor][i]] = distancia_minima[valor] + 1;
                val[adj[valor][i]] = true;
                dd.push(adj[valor][i]);
            }
        }
    }
}

int main() {
    ll n;
    cin >> n;
    ll as = n;
    while (as--) {
        ll a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<ll> qqq = {1, 2}; // roots
    bfs(qqq);

    return 0;
}