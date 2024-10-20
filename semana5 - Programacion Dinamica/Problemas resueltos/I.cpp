#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100000;
string str[MAX_N], str_rev[MAX_N];
long long dp[MAX_N + 1][2];
int c[MAX_N];
const long long INF = 1000000LL * 1000000 * 1000000;
bool lexicog[MAX_N][2][2];

long long minEnergy(int n, int rev){
    if(n == 0) return 0;
    long long &ans = dp[n][rev];
    if(ans != -1) return ans;
    bool can_choose_str = lexicog[n - 1][rev][0];
    bool can_choose_str_rev = lexicog[n - 1][rev][1];
    if(!can_choose_str && !can_choose_str_rev) ans = INF;
    else if(can_choose_str && can_choose_str_rev) ans = min(minEnergy(n - 1, 0), minEnergy(n - 1, 1)) + (rev ? c[n - 1]: 0);
    else if(can_choose_str) ans = minEnergy(n - 1, 0) + (rev ? c[n - 1]: 0);
    else  ans = minEnergy(n - 1, 1) + (rev ? c[n - 1]: 0);
    if(ans >= INF) ans = INF;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    for(int i = 0; i < n; i++){
        cin >> str[i];
        str_rev[i] = str[i];
        reverse(str_rev[i].begin(), str_rev[i].end());
    }
    for(int i = 0; i < n; i++){
        if(i == 0) {
            lexicog[i][0][0] = true;
            lexicog[i][0][1] = true;
            lexicog[i][1][0] = true;
            lexicog[i][1][1] = true;
        } else {
            lexicog[i][0][0] = str[i - 1] <= str[i];
            lexicog[i][0][1] = str_rev[i - 1] <= str[i];
            lexicog[i][1][0] = str[i - 1] <= str_rev[i];
            lexicog[i][1][1] = str_rev[i - 1] <= str_rev[i];
        }
    }
    memset(dp, -1, sizeof dp);
    if(minEnergy(n, 0) == INF && minEnergy(n, 1) == INF){
        cout << "-1\n";
    } else {
        cout << min(minEnergy(n, 0), minEnergy(n, 1)) << '\n';
    }
    return 0;
}