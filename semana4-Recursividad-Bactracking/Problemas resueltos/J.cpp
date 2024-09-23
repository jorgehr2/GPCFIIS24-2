#include<bits/stdc++.h>
using namespace std;

int n;
const int MAX_N = 20;
int weights[MAX_N];

long long findMinDiff(int pos, long long weight_diff){
    if(pos == n) return abs(weight_diff);
    return min(findMinDiff(pos + 1, weight_diff + weights[pos]), findMinDiff(pos + 1, weight_diff - weights[pos]));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> weights[i];
    }
    cout << findMinDiff(0, 0) << '\n';
    return 0;
}