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

vector<ll> v;
vector<ll> low;
bool a[500005];
ll n, error, e, vis, c, i, j;

int main() {
    inic;
    inic2;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> e;
        v.push_back(e);
    }
    sort(v.begin(), v.end());

    j = n / 2;
    i = 0;
    while (i < n && j < n) {
        if (v[j] >= v[i] * 2 && a[i] == 0 && a[j] == 0) {
            a[i] = 1;
            a[j] = 1;
            j++;
            i++;
        } else j++;
    }

    for (i = 0; i < n; i++) {
        // cout << a[i] << " ";
        if (a[i] == 0) vis++;
        if (a[i] == 1) c++;
    }
    cout << vis + c / 2 << endl;
    return 0;
}