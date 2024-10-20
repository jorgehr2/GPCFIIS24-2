#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100;
const int MAX_S = 100 * 1000;

int v[MAX_N];
int dp[MAX_N + 1][MAX_S + 1];

int subsetSum(int n, int sum){
    if(n == 0) {
        if(sum == 0) return 1;
        else return 0;
    }
    if(sum == 0) return 1;
    int &ans = dp[n][sum];
    if(ans != -1) return ans;
    ans = subsetSum(n - 1, sum) or subsetSum(n - 1, sum - v[n - 1]);
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        int n;
        cin >> n;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];
        }
        memset(dp, -1, sizeof dp);
        int64_t ans = 0;
        for(int i = 0; i <= sum; i++){
            if(subsetSum(n, i)) {
                ans += i;
            }
        }
        cout << ans << '\n';
    }
}