#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
const ll MX = 2e5 + 2;

ll tamanio[MX], lider[MX], minimo[MX];
ll find_lider(ll nodo) {
    if (lider[nodo] == nodo) {
        return nodo;
    }
    // lider[nodo] = find_lider(lider[nodo]);
    return find_lider(lider[nodo]);
}
vector<ll> historial;
void join(ll nodo_a, ll nodo_b) {
    nodo_a = find_lider(nodo_a);
    nodo_b = find_lider(nodo_b);
    if (nodo_a != nodo_b) {
        if (tamanio[nodo_a] >= tamanio[nodo_b]) {
            tamanio[nodo_a] += tamanio[nodo_b];
            lider[nodo_b] = nodo_a;
        } else {
            tamanio[nodo_b] += tamanio[nodo_a];
            lider[nodo_a] = nodo_b;
        }
    }
}

void rollback() {
    if (historial.size() == 0) {
        return;
    }
    ll u = historial.back();
    ll v = lider[u];
    historial.pop_back();
    if (u == v) {
        return;
    }
    tamanio[v] -= tamanio[u];
    lider[u] = u;
}

ll valores[MX];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    fill(tamanio, tamanio + n + 1, 1);
    iota(lider, lider + n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        cin >> valores[i];
        minimo[i] = valores[i];
    }
    ll m;
    cin >> m;
    for (ll i = 1; i <= m; i++) {
        ll a, b;
        cin >> a >> b;
        join(a, b);
    }

    ll a, b;
    cin >> a >> b;
    while (lider[a] != a) {
        a = lider[a];
    }
    while (lider[b] != b) {
        b = lider[b];
    }
    if (a == b) {
        cout << "Estan en el mismo grupo";
    }
    rollback();
    return 0;
}
