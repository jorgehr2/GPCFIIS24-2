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
const ll MX = 5e3 + 2;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);

ll cant[MX][MX];
int main() {
    inic;
    inic2;
    ll n, m;
    cin >> n >> m;
    Rep1(i, n) {
        string s;
        cin >> s;
        for (ll j = s.size() - 1; j >= 0; j--) {
            if (s[j] == '1') {
                cant[i][j + 1] = cant[i][j + 2] + 1;
            } else {
                cant[i][j + 1] = 0;
            }
        }
    }
    vector<ll> usar;
    ll resp = 0;
    Rep1(j, m) {
        Rep1(i, n) {
            usar.pb(cant[i][j]);
        }
        sort(usar.begin(), usar.end());
        Repi0(i, usar.size()) {
            resp = max(resp, usar[i] * (usar.size() - i));
        }
        usar.clear();
    }
    cout << resp << endl;

    return 0;
}