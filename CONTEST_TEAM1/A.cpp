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
const ll MOD = 998244353;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);
typedef long double ld;
typedef unsigned long long ull;
const int ALPH = 256;

pair<ll, ll> operador(pair<ll, ll> x, pair<ll, ll> y) {
    // return max(x, y);
    if (x.first >= y.first) {
        return x;
    }
    return y;
    // return x + y;
}

struct SegmentTree {
    pair<ll, ll> t[2 * MX];
    int n;

    void clear(int n) {
        for (int i = 1; i <= 2 * n; i++) {
            t[i].first = 0;
            t[i].second = 0;
        }
        this->n = n;
    }

    void build(vector<ll> &a, ll id, ll tl, ll tr) { // O(n)
        if (tl == tr) {
            t[id].first = a[tl - 1];
            t[id].second = tl;
        } else {
            ll tm = (tl + tr) / 2;
            ll left = id + 1;
            ll right = id + 2 * (tm - tl + 1);
            build(a, left, tl, tm);
            build(a, right, tm + 1, tr);
            t[id] = operador(t[left], t[right]);
        }
    }

    void build(vector<ll> &a) {
        n = a.size();
        build(a, 1, 1, n);
    }

    pair<ll, ll> query(ll l, ll r, ll id, ll tl, ll tr) { // O(logn)
        // if (tr < l || tl > r || l>R) return 0; //Dependiendo lo que te pidan
        if (l <= tl && tr <= r) return t[id];
        ll tm = (tl + tr) / 2;
        ll left = id + 1;
        ll right = id + 2 * (tm - tl + 1);
        if (r < tm + 1) return query(l, r, left, tl, tm);
        else if (tm < l) return query(l, r, right, tm + 1, tr);
        else return operador(query(l, r, left, tl, tm), query(l, r, right, tm + 1, tr));
    }

    pair<ll, ll> query(ll l, ll r) {
        assert(n > 0);
        return query(l, r, 1, 1, n);
    }

    void update(ll pos, ll val, ll id, ll tl, ll tr) { // O(logn)
        if (tl == tr) {
            t[id].first += val;
        } else {
            ll tm = (tl + tr) / 2;
            ll left = id + 1;
            ll right = id + 2 * (tm - tl + 1);
            if (pos <= tm) update(pos, val, left, tl, tm);
            else update(pos, val, right, tm + 1, tr);
            t[id] = operador(t[left], t[right]);
        }
    }

    void update2(ll pos, ll val, ll id, ll tl, ll tr) { // O(logn)
        if (tl == tr) {
            t[id].first = val;
        } else {
            ll tm = (tl + tr) / 2;
            ll left = id + 1;
            ll right = id + 2 * (tm - tl + 1);
            if (pos <= tm) update2(pos, val, left, tl, tm);
            else update2(pos, val, right, tm + 1, tr);
            t[id] = operador(t[left], t[right]);
        }
    }

    void update(ll pos, ll val) {
        assert(n > 0);
        update(pos, val, 1, 1, n);
    }
    void update2(ll pos, ll val) {
        assert(n > 0);
        update2(pos, val, 1, 1, n);
    }

} st;

struct vals {
    ll d, v, t;
};

vector<vals> vec;
set<ll> se;
map<ll, ll> ids;
int main() {
    inic;
    inic2;
    ll n;
    cin >> n;
    Rep1(i, n) {
        ll d, v, t;
        cin >> d >> v >> t;
        se.insert(d);
        se.insert(d - t);
        vec.pb({d, v, t});
    }

    ll cont = 0;
    for (set<ll>::iterator it = se.begin(); it != se.end(); it++) {
        cont++;
        ids[*it] = cont;
        // rev_ids[cont]=*it;
    }
    vector<ll> temp;
    Rep1(i, cont) {
        temp.pb(0);
    }
    st.build(temp);
    // cout<<st.query(1,-1).first<<endl;
    st.update(ids[vec[0].d], vec[0].v);
    // cout<<"Estoy actualizando i: "<<ids[vec[0].d]<<" equiv: "<<vec[0].d<< " con el valor:
    // "<< vec[0].v <<endl;
    for (ll i = 1; i < vec.size(); i++) {
        ll jj = ids[vec[i].d - vec[i].t];
        ll jj2 = ids[vec[i].d];
        pair<ll, ll> rp = st.query(jj, jj2);
        if (rp.second == jj2) {
            st.update(rp.second, vec[i].v);
            // cout<<"Estoy actualizando i: "<<rp.second<<" equiv: "<<vec[i].d<< " con el
            // valor: "<< vec[i].v <<endl;
        } else {
            st.update2(jj2, rp.first + vec[i].v);
            // cout<<"Estoy asignando i: "<<ids[vec[i].d]<<" equiv: "<<vec[i].d<< "con el
            // valor: "<< rp.first <<"  "<< vec[i].v<<" "<< rp.first + vec[i].v <<endl;
        }
        // cout<<"--------------"<<endl;
        // for(ll i=1;i<=cont;i++){
        //     cout<<st.query(i,i).first<<" ";
        // }cout<<endl;
        // cout<<"--------------"<<endl;
    }
    ll mayor = 0;
    Rep1(i, cont) {
        pair<ll, ll> pp = st.query(i, i);
        mayor = max(mayor, pp.first);
    }
    cout << mayor << endl;
    return 0;
}