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

vector<ll> vec;
int main() {
    inic;
    inic2;
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        ll num;
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end());
    ll actual = 0, rp = 0;
    for (auto x : vec) {
        if (x >= actual) {
            rp++;
            actual += x;
        }
    }
    cout << rp << endl;
    return 0;
}