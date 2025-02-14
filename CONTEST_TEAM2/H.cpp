#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;

#define sz(v) (int)v.size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fore(i, s, e) for (int i = s; i < e; ++i)
#define forn(i, n) fore(i, 0, n)
#define pb push_back
#define pf push_front
#define fst first
#define snd second
#define endl '\n'
#define fastio ios::sync_with_stdio(false), cin.tie(nullptr)
#define debug(x) cout << #x << " = " << x << endl;

using pll = pair<ll, ll>;

// Auxiliary functions
ll dist2(ll x1, ll y1, ll x2, ll y2) {
    ll dx = x1 - x2, dy = y1 - y2;
    return dx * dx + dy * dy;
}

bool collinear(pll vA, pll vB) {
    return vA.fst * vB.snd == vA.snd * vB.fst;
}

void solve(int tc) {
    ll ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    if (dist2(ax, ay, bx, by) == dist2(bx, by, cx, cy) and
        !collinear({ax - bx, ay - by}, {ax - cx, ay - cy})) {
        cout << "Yes" << endl;
    } else cout << "No" << endl;
}

int32_t main() {
    fastio;
    int T = 1;
    // cin >> T;
    fore(i, 1, T + 1) {
        solve(i);
    }
    return 0;
}