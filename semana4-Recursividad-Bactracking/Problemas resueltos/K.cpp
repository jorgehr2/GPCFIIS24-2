#include<bits/stdc++.h>
using namespace std;

int n;
const int MAX_N = 16;
const int MAX_SUM_ADJ = 31;
bool used[MAX_N + 1];
bool is_prime[MAX_SUM_ADJ + 1];
vector<int> permutation;

void findPermutation(){
    if(permutation.size() == n){
        if(is_prime[permutation.front() + permutation.back()]){
            for(int i = 0; i < n; i++){
                if(i) cout << ' ';
                cout << permutation[i];
            }
            cout << '\n';
        }
        return;
    }
    for(int value = 1; value <= n; value++){
        if(used[value]) continue;
        if(!is_prime[permutation.back() + value]) continue;
        permutation.push_back(value);
        used[value] = true;
        findPermutation();
        permutation.pop_back();
        used[value] = false;
    }
    return;
}

bool checkPrime(int num){
    for(int d = 2; d * d <= num; d++){
        if(num % d == 0) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 2; i <= MAX_SUM_ADJ; i++){
        is_prime[i] = checkPrime(i);
    }
    int test = 1;
    while(cin >> n){
        for(int i = 1; i <= n; i++){
            used[i] = false;
        }
        permutation = {1};
        used[1] = true;
        if(test > 1) cout << '\n';
        cout << "Case " << test << ":\n";
        findPermutation();
        test++;
    }
    return 0;
}