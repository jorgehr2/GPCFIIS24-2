#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 60;
int memo[MAX_N + 1];

int dp(int n){
    if(n == 0) return 1;
    if(n == 1) return 0;
    int &ans = memo[n];
    if(ans != -1) return ans;
    ans = 2 * dp(n - 2);
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    memset(memo, -1, sizeof memo);
    cout << dp(n) << '\n';
    return 0;
}