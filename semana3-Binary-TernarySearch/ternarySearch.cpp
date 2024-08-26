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

ll f(ll i);

ll ternarySearch(ll low, ll high) { // O(log n)
    while (high - low > 2) {
        ll m1 = low + (high - low) / 3;
        ll m2 = high - (high - low) / 3;
        // si se necesita minimo, cambiar a >
        if (f(m1) < f(m2)) low = m1;
        else high = m2;
    }
    ll maxi = f(low);
    for (ll i = low + 1; i <= high; i++) {
        maxi = max(maxi, f(i)); // si se necesita minimo, cambiar a min
    }
    return maxi;
}
int main() {
    inic;
    inic2;
    return 0;
}