#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

const double PI = acos(-1);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, R, r;
    cin >> n >> R >> r;
    cout << fixed << setprecision(6) << (double)R * r * sin(PI / n) * n << endl;
}