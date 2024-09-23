#include<bits/stdc++.h>
using namespace std;

const int N = 10;
int k;
int c[N];
bool used[N];
vector<int> permutation;

bool findPermutation(long long sum){
    if(permutation.size() == N){
        return true;
    }
    for(int value = 0; value < N; value++){
        if(used[value]) continue;
        long long new_sum = sum + 1LL * c[permutation.size()] * value;
        if(new_sum > k) continue;
        permutation.push_back(value);
        used[value] = true;
        if(findPermutation(new_sum)){
            return true;
        }
        permutation.pop_back();
        used[value] = false;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin >> tests;
    for(int test = 0; test < tests; test++){
        for(int i = 0; i < N; i++){
            used[i] = false;
        }
        permutation.clear();
        for(int i = 0; i < N; i++){
            cin >> c[i];
        }
        cin >> k;
        if(findPermutation(0)){
            for(int i = 0; i < N; i++){
                cout << permutation[i] << ' ';
            }
            cout << '\n';
        } else cout << "-1\n";
    }
}