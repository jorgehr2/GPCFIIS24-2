#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 5000;
const int MAX_K = 5000;
int dp[MAX_N + 1][MAX_K + 1];
int a[MAX_N];

int kTeams(int n, int k){
    if(n == 0 || k == 0) return 0;
    int &ans = dp[n][k];
    if(ans != -1) return ans;
    ans = max(ans, kTeams(n - 1, k)); // don't take
    int team_from = lower_bound(a, a + n, a[n - 1] - 5) - a;
    ans = max(ans, kTeams(team_from, k - 1) + n - team_from); // take
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    memset(dp, -1, sizeof dp);
    cout << kTeams(n, k) << '\n';
    return 0;
}