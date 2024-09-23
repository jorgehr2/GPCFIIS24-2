#include<bits/stdc++.h>
using namespace std;

int cap, items;
const int N = 2005;
const int MAX_CAP = 2005;
int w[N], b[N];
int memo[N][MAX_CAP];

int dp(int pos, int cur_cap){
    if(pos == items){
        return 0;
    }
    int &ans = memo[pos][cur_cap];
    if(ans != -1){
        return ans;
    }
    ans = dp(pos + 1, cur_cap); // don't take the pos item
    if(cur_cap >= w[pos]){ // take the pos item
        ans = max(ans, b[pos] + dp(pos + 1, cur_cap - w[pos]));
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> cap >> items;
    for(int i = 0; i < items; i++){
        cin >> w[i] >> b[i];
    }
    memset(memo, -1, sizeof memo);
    cout << dp(0, cap) << '\n';
    return 0;
}