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
const ll MX = 1e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);
typedef long double ld;
typedef unsigned long long ull;

int main() {
    inic;
    inic2;
    string s;
    cin >> s;
    char anterior = '#';
    ll cant_max = -1, actual = 0;
    for (ll i = 0; i < s.size(); i++) {
        if (s[i] != anterior) {
            actual = 1;
        } else {
            actual++;
        }
        anterior = s[i];
        cant_max = max(cant_max, actual); // Siempre se actualiza la máxima cantidad
    }
    cout << cant_max << endl;
    return 0;
}