#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll arr[200000 + 2];

int main() {
    ll n;
    cin >> n;
    for (ll i = 1; i < n; i++) {
        ll num;
        cin >> num;
        arr[num]++;
    }
    for (ll i = 1; i <= n; i++) {
        if (arr[i] == 0) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}