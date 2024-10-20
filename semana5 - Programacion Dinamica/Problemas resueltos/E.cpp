#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 200000;
int a[MAX_N];
int memo[MAX_N + 1][2];

int dp(int n, int removed){
    if(n == 1){
        return 1;
    }
    int &ans = memo[n][removed];
    if(ans != -1) return ans;
    ans = (a[n - 1] > a[n - 2]) + dp(n - 1, removed);
    if(!removed){
        if(n == 2) ans = max(ans, 1);
        else ans = max(ans, (a[n - 1] > a[n - 3]) + dp(n - 2, 1));
    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    memset(memo, -1, sizeof memo);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp(i, 0));
    }
    cout << ans << '\n';
    return 0;
}