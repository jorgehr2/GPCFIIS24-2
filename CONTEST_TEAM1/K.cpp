#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
#define all(s) s.begin(), s.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
#define Repi0(i, n) for (ll i = n - 1; i >= 0; i--)
#define Repi1(i, n) for (ll i = n; i >= 1; i--)
#define POT(x) ((x) * (x))
const ll MX = 1e5 + 2, MX2 = 8e2 + 5;
const ll MOD = 998244353;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);

ll combine(ll a, ll b) {
    return a + b;
}
ll sum_mod(ll a, ll b, ll c = MOD) {
    return a + b;
    // return ((a % c) + (b % c)) % c;
}
ll mult_mod(ll a, ll b, ll c = MOD) {
    return a * b;
    // return (((a % c) * (b % c)) % c);
}
struct SegmentTree {
    ll t[2 * MX];
    ll lazy[2 * MX];
    ll n;

    void clear(ll n) {
        for (ll i = 0; i < 2 * n; i++) {
            t[i] = 0;
            lazy[i] = 0;
        }
        this->n = n;
    }

    void build(vector<ll> &a, ll id, ll tl, ll tr) { // O(n)
        lazy[id] = 0;
        if (tl == tr) {
            t[id] = a[tl];
        } else {
            ll tm = (tl + tr) / 2;
            ll left = id + 1;
            ll right = id + 2 * (tm - tl + 1);
            build(a, left, tl, tm);
            build(a, right, tm + 1, tr);
            t[id] = combine(t[left], t[right]);
        }
    }

    void build(vector<ll> &a) {
        n = a.size();
        build(a, 1, 0, n - 1);
    }

    void push(ll id, ll tl, ll tr) { // O(1)
        ll tm = (tl + tr) / 2;
        ll left = id + 1;
        ll right = id + 2 * (tm - tl + 1);
        ll szLeft = tm - tl + 1;
        ll szRight = tr - tm;
        // Apply the lazy value of the node to the children
        t[left] = sum_mod(t[left], mult_mod(lazy[id], szLeft));
        t[right] = sum_mod(t[right], mult_mod(lazy[id], szRight));

        // Aggregate the lazy value
        lazy[left] = sum_mod(lazy[left], lazy[id]);
        lazy[right] = sum_mod(lazy[right], lazy[id]);

        // Restart the lazy value
        lazy[id] = 0;
    }

    ll query(ll l, ll r, ll id, ll tl, ll tr) { // O(logn)
        if (l <= tl && tr <= r) return t[id];
        ll tm = (tl + tr) / 2;
        ll left = id + 1;
        ll right = id + 2 * (tm - tl + 1);
        push(id, tl, tr);
        if (r < tm + 1) return query(l, r, left, tl, tm);
        else if (tm < l) return query(l, r, right, tm + 1, tr);
        else return combine(query(l, r, left, tl, tm), query(l, r, right, tm + 1, tr));
    }

    ll query(ll l, ll r) {
        assert(n > 0);
        return query(l, r, 1, 0, n - 1);
    }

    void update(ll l, ll r, ll val, ll id, ll tl, ll tr) { // O(logn)
        if (tr < l || tl > r) return;
        if (l <= tl && tr <= r) {
            ll sz = tr - tl + 1;
            // Apply the lazy value
            t[id] = sum_mod(t[id], mult_mod(val, sz));
            // Aggregate the lazy value
            lazy[id] = sum_mod(lazy[id], val);
        } else {
            ll tm = (tl + tr) / 2;
            ll left = id + 1;
            ll right = id + 2 * (tm - tl + 1);
            push(id, tl, tr);
            update(l, r, val, left, tl, tm);
            update(l, r, val, right, tm + 1, tr);
            t[id] = combine(t[left], t[right]);
        }
    }

    void update(ll l, ll r, ll val) {
        assert(n > 0);
        update(l, r, val, 1, 0, n - 1);
    }
} st;

vector<ll> vec, vec2, vec3, vec4;
ll agreg[MX], valos[MX];
int main() {
    inic;
    inic2;
    ll n;
    cin >> n;
    Rep1(i, n) {
        ll l;
        cin >> l;
        vec3.pb(0);
        vec.pb(l);
    }
    ll tot = 0;
    Rep1(i, n) {
        ll l;
        cin >> l;
        vec4.pb(l), tot += l;
        valos[i - 1] = tot;
        vec2.pb(tot);
    }
    st.build(vec3);
    // cout << upper_bound(vec2.begin(), vec2.end(), vec[0]) - vec2.begin() << " adsdas " <<
    // endl;
    for (ll i = 0; i < vec.size(); i++) {
        ll pos = -1;
        if (i == 0) {
            pos = upper_bound(vec2.begin(), vec2.end(), vec[i]) - (vec2.begin());
        } else {
            pos = upper_bound(vec2.begin(), vec2.end(), vec[i] + vec2[i - 1]) - (vec2.begin());
        }
        // cout << "Pos: " << pos << endl;
        if (pos - 1 < vec.size() && pos > i) {
            st.update(i, pos - 1, 1);
            // cout << "Act: " << i << " adas " << pos - 1 << " " << 1 << endl;
        }
        if (pos < vec.size()) {
            if (i > 0) {
                ll dd = vec[i] - (valos[pos - 1] - valos[i - 1]);
                // cout << valos[pos - 1] << " wewewe " << valos[i - 1] << endl;
                // agreg[pos] += (vec4[pos] - dd);
                agreg[pos] += dd;
                // cout << "Agreg en pos: " << pos << " : " << dd << endl;
            } else {
                ll dd = vec[i] - (valos[pos - 1]);
                // cout << vec4[pos] << " qeqwqweqweqwe " << dd << endl;
                // agreg[pos] += (vec4[pos] - dd);
                agreg[pos] += dd;
                // cout << "Agreg en pos: " << pos << " : " << dd << endl;
            }
        }
    }
    for (ll i = 0; i < vec.size(); i++) {
        cout << st.query(i, i) * vec4[i] + agreg[i] << " ";
    }
    cout << endl;
    return 0;
}