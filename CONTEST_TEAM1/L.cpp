#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<ll, int> f;
    set<ll> S;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        int s;
        cin >> s;
        vector<ll> values;
        for (int j = 0; j < s; ++j) {
            ll x;
            cin >> x;
            values.push_back(x);
        }
        if (t == 1) {
            cnt++;
            for (ll x : values) f[x]++;
        } else {
            for (ll x : values) S.insert(x);
        }
    }
    const ll TOT = 1e18;
    if (!cnt) cout << TOT - S.size() << endl;
    else {
        int ans = 0;
        for (auto it : f) {
            if (it.second == cnt and S.count(it.first) == 0) ans++;
        }
        cout << ans << endl;
    }
}