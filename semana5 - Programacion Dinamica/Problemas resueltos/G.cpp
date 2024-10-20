#include<bits/stdc++.h>
using namespace std;

string a, b;
const int MAX_N = 2000;
int dp[MAX_N + 1][MAX_N + 1];

int editDistance(int n, int m){
    if(n == 0) return m;
    if(m == 0) return n;
    int &ans = dp[n][m];
    if(ans != -1) return ans;
    if(a[n - 1] == b[m - 1]) {
        ans = editDistance(n - 1, m - 1);
    } else {
        ans = 1 + min({editDistance(n, m - 1), editDistance(n - 1, m), editDistance(n - 1, m - 1)});
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for(int t = 0; t < T; t++){
        cin >> a >> b;
        memset(dp, -1, sizeof dp);
        cout << editDistance(a.size(), b.size()) << '\n';
    }
    return 0;
}