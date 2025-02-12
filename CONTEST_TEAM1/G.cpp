#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'
#define all(v) v.begin(), v.end()

const double PI = acos(-1);

long long f(vector<int> &v, vector<int> &w, long long x) {
    long long ans = 0;
    for (int a : v) ans += max(0LL, x - a);
    for (int a : w) ans += max(0LL, (ll)a - x);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> v(n), w(m);
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < m; ++i) cin >> w[i];
    long long l = 0, r = (ll)max(*max_element(all(v)), *max_element(all(w)));
    while (r - l > 2) {
        long long m1 = l + (r - l) / 3;
        long long m2 = r - (r - l) / 3;
        if (f(v, w, m1) > f(v, w, m2)) l = m1;
        else r = m2;
    }
    long long ans = 1e18;
    for (long long i = l; i <= r; ++i) ans = min(ans, f(v, w, i));
    cout << ans << endl;
    return 0;
}