#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
#define all(s) s.begin(), s.end()
using namespace std;
typedef long long ll;
using Long = ll;
typedef long double ld;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
#define Repi0(i, n) for (ll i = n - 1; i >= 0; i--)
#define Repi1(i, n) for (ll i = n; i >= 1; i--)
#define POT(x) ((x) * (x))
const ll MX = 1e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);

ll valores[MX], valores2[MX];
ll resolver(ll perFilas, ll n) {
    ll resp = 0, pos = -1;
    valores[n + 1] = 0;
    for (ll i = 1; i <= n + 1; i++) {
        valores2[i] = valores[i];
    }
    ll ag = 0;
    for (ll i = 1; i <= n; i++) {
        // if (pos < i - 1) {
        //     ag = 0;
        // }
        ag += (valores2[i] / perFilas);
        // pos = i;
        valores2[i] = valores2[i] % perFilas;
        if (valores2[i] + valores2[i + 1] >= perFilas) {
            // pos = i + 1;
            ag++;
            valores2[i + 1] -= (perFilas - valores2[i]);
        }
        resp = max(resp, ag);
    }
    return resp;
}
int main() {
    inic;
    inic2;
    ll t;
    cin >> t;
    while (t--) {
        ll n, k, tot = 0;
        cin >> n >> k;
        Rep1(i, n) {
            ll l;
            cin >> l;
            tot += l;
            valores[i] = l;
        }
        ll ini = 1, fin = tot / k;
        while (ini < fin) {
            ll med = (ini + fin) / 2;
            // cout << ini << " asdad " << fin << "medio: " << med << " Resultado "
            //      << resolver(med, n) << endl;
            if (resolver(med, n) >= k) {
                ini = med + 1;
            } else {
                fin = med;
            }
        }
        // cout << "Inicio assdasdas " << ini << endl;
        if (resolver(ini, n) >= k) {
            cout << k * ini << endl;
        } else {
            if (ini > 1) {
                ini--;
                if (resolver(ini, n) >= k) {
                    cout << k * ini << endl;
                } else {
                    cout << 0 << endl;
                }
            } else {
                cout << 0 << endl;
            }
        }
    }
    return 0;
}
