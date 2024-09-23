#include<bits/stdc++.h>
using namespace std;

int s, n;
const int MAX_N = 12;
int x[MAX_N];
vector<int> l;
bool used[MAX_N];
set<vector<int>> all_sums;

void findAllDistinctsSum(int pos, int sum){
    if(pos == n){
        if(sum == s){
            all_sums.insert(l);
        }
        return;
    }
    findAllDistinctsSum(pos + 1, sum);
    if(sum + x[pos] <= s){
        l.push_back(pos);
        used[pos] = true;
        findAllDistinctsSum(pos + 1, sum + x[pos]);
        l.pop_back();
        used[pos] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin >> s >> n && n != 0){
        l.clear();
        all_sums.clear();
        for(int i = 0; i < n; i++){
            used[i] = false;
        }
        for(int i = 0; i < n; i++){
            cin >> x[i];
        }
        findAllDistinctsSum(0, 0);
        cout << "Sums of " << s << ":\n";
        if(all_sums.empty()){
            cout << "NONE\n";
        } else {
            set<vector<int>> sums;
            for(auto it = all_sums.begin(); it != all_sums.end(); it++){
                vector<int> sum = *it;
                vector<int> answer;
                for(int i = 0; i < sum.size(); i++){
                    answer.push_back(x[sum[i]]);
                }
                if(sums.find(answer) == sums.end()){
                    for(int i = 0; i < answer.size(); i++){
                        if(i) cout << '+';
                        cout << answer[i];
                    }
                    cout << '\n';
                    sums.insert(answer);
                }
            }
        }   
    }
    return 0;
}