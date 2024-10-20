#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100000;
int a[MAX_N];
long long dp[MAX_N + 1][5];
const long long INF = 1000000LL * 1000000 * 1000000;
string s;
const string hard = "hard";

long long easyProblem(int n, int pfx){
    if(pfx == 0) return INF;
    if(n == 0) return 0;
    long long &ans = dp[n][pfx];
    if(ans != -1) return ans;
    if(s[n - 1] == hard[pfx - 1]){
        ans = min(easyProblem(n - 1, pfx - 1), easyProblem(n - 1, pfx) + a[n - 1]);
    } else {
        ans = easyProblem(n - 1, pfx);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << easyProblem(n, 4) << '\n';
    return 0;
}