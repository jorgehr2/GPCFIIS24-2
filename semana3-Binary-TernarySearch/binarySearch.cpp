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

ll getBit(ll x, ll i) {
    return (x >> i) & 1;
}

ll f(ll x) {
    return x;
}

double f2(double x_0) {
    return x_0 * 3.0 / 3.2;
}
int main() {
    inic;
    inic2;
    // la min pos en la que el f(pos) sea mayor o igual a target
    ll n, target;
    cin >> n >> target;
    ll ini = 1, fin = n;
    while (ini < fin) {
        ll med = (ini + fin) / 2;
        if (f(med) < target) {
            ini = med + 1;
        } else {
            fin = med;
        }
    }
    if (f(ini) >= target) {
        cout << ini << endl;
    } else {
        cout << "No hay respuesta" << endl;
    }
    // la max pos en la que el f(pos) sea menor o igual a target
    while (ini < fin) {
        ll med = (ini + fin + 1) / 2;
        if (f(med) <= target) {
            ini = med;
        } else {
            fin = med - 1;
        }
    }
    if (f(ini) <= target) {
        cout << ini << endl;
    } else {
        cout << "No hay respuesta" << endl;
    }
    // Busqueda binaria continua
    ll n2, target2;
    cin >> n2 >> target2;
    ll iteraciones = 80;
    double ini2 = 1, fin2 = n2;
    for (ll i = 1; i <= iteraciones; i++) {
        double med = (ini2 + fin2) / 2;
        if (f(med) < target) {
            ini = med + 1;
        } else {
            fin = med;
        }
    }
    if (f2(ini2) >= target2) {
        cout << ini2 << endl;
    } else {
        cout << "No hay respuesta" << endl;
    }
    return 0;
}
