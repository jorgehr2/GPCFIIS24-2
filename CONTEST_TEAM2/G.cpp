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

ll rest_mod(ll a, ll b, ll c) {
    return ((a % c) - (b % c) + c) % c;
}
ll sum_mod(ll a, ll b, ll c) {
    return (a % c + b % c) % c;
}
ll pot_mod(ll a, ll b, ll c) {
    if (b == 0) {
        return 1 % c;
    }
    int temp = pot_mod(a, b / 2, c);
    temp = (temp * temp) % c;
    if (b % 2 == 0) return temp;
    return (temp * (a % c)) % c;
}
ll mult_mod(ll a, ll b, ll c) {
    return (((a % c) * (b % c)) % c);
}
ll fastPow(ll a, ll b, ll c) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1 == 1) ans = mult_mod(ans, a, c);
        a = mult_mod(a, a, c);
        b >>= 1;
    }
    return ans;
}
ll modInverse(ll a, ll c) {
    return fastPow(a, MOD - 2, c);
}
ll divide(ll a, ll b, ll c) {
    return mult_mod(a, modInverse(b, c), c);
}

ll division(ll n, ll k) {
    return (n % MOD * fastPow(k, MOD - 2, MOD) % MOD) % MOD;
}

ll resolver(ll n, vector<ll> &vec) {
    ll tot = 1;
    for (ll i = 1; i <= n - vec.size() + 1; i++) {
        tot = mult_mod(tot, i, MOD);
    }
    // cout << "Total: " << tot << '\n';
    ll parc = 1;
    for (ll i = 0; i < vec.size(); i++) {
        if (vec[i] != 0) {
            // cout << " qeqweqv " << vec[i] << '\n';
            for (ll j = 1; j <= vec[i]; j++) {
                parc = mult_mod(parc, j, MOD);
            }
        }
        if (i > 0 && i < vec.size() - 1) {
            tot = mult_mod(tot, fastPow(2, vec[i] - 1, MOD), MOD);
        }
    }
    // cout << "Total Nuevo: " << tot << '\n';
    // cout << "Divisor: " << parc << '\n';
    return divide(tot, parc, MOD);
}

int main() {
    inic;
    inic2;
    ll n, m;
    cin >> n >> m;
    vector<ll> vec, valores;
    Rep1(i, m) {
        ll l;
        cin >> l;
        vec.pb(l);
    }
    sort(vec.begin(), vec.end());
    ll izquierda = vec[0] - 1;
    valores.pb(izquierda);
    for (ll i = 0; i < vec.size() - 1; i++) {
        valores.pb(vec[i + 1] - vec[i] - 1);
    }
    ll derecha = n - vec[vec.size() - 1];
    valores.pb(derecha);
    cout << resolver(n, valores) << '\n';
    return 0;
}