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
const ll MX = 3e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);

ll resps[MX], qwe[MX];
vector<ll> posi[MX];
vector<pair<ll, ll>> totales;
ll type1[MX];
int main() {
    inic;
    inic2;
    ll ag = 0, n, q, maximo = -1;
    cin >> n >> q;
    vector<pair<ll, ll>> vpa;
    Rep0(i, q) {
        ll type, numero;
        cin >> type >> numero;
        if (type == 1) {
            type1[ag] = i;
            ag++;
        }
        if (type == 2) {
            posi[numero].pb(i);
        }
        if (type == 3) {
            numero--;
            if (type1[numero] > maximo) {
                totales.pb({type1[numero], i});
                // cout << "Hasta: " << type1[numero] << endl;
                maximo = type1[numero];
            }
        }
        vpa.pb({type, numero});
    }
    for (ll i = 0; i < vpa.size(); i++) {
        if (vpa[i].first == 1) {
            // cout << "Aumento 1: " << i << endl;
            resps[i]++;
            vector<ll>::iterator it =
                lower_bound(posi[vpa[i].second].begin(), posi[vpa[i].second].end(), i);
            ll asd;
            if (it != posi[vpa[i].second].end()) {
                asd = (*it);
                // resps[(*it) + 1]--;
            } else {
                asd = vpa.size();
            }
            vector<pair<ll, ll>>::iterator it2 =
                lower_bound(totales.begin(), totales.end(), make_pair(i, i));
            if (it2 != totales.end()) {
                asd = min(asd, (*it2).second);
            }
            // cout << "Disminuyo 1: " << asd << endl;
            resps[asd]--;
        }
    }
    ll tot = 0;
    for (ll i = 0; i < q; i++) {
        tot += resps[i];
        cout << tot << '\n';
    }
    return 0;
}
