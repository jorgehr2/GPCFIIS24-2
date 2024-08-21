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
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);
typedef long double ld;
typedef unsigned long long ull;

ll getBit(ll x, ll i) {
    return (x >> i) & 1;
}

vector<ll> vec;
map<char, ll> ma;
ll total_pos[MX], acumulado_inverso[MX];
int main() {
    inic;
    inic2;
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        Rep1(i, m) {
            ll l;
            cin >> l;
            vec.pb(l);
            total_pos[l]++;
        }
        sort(vec.begin(), vec.end());
        for (ll i = n; i >= 1; i--) {
            acumulado_inverso[i] = total_pos[i];
            acumulado_inverso[i] += acumulado_inverso[i + 1];
        }
        for (ll i = 0; i < s.size(); i++) {
            ma[s[i]]++;
            ma[s[i]] += acumulado_inverso[i + 1];
        }
        for (char p = 'a'; p <= 'z'; p++) {
            cout << ma[p] << " ";
        }
        cout << endl;

        vec.clear();
        ma.clear();
        Rep1(i, n + 1) {
            acumulado_inverso[i] = 0;
            total_pos[i] = 0;
        }
    }

    return 0;
}