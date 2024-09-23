#include<bits/stdc++.h>
using namespace std;

int n;
set<long long> all_luckys;

void generateLuckyNumbers(long long lucky, int x, int y){
    if(lucky > n) return;
    if(lucky > 0){
        all_luckys.insert(lucky);
    }
    long long lucky_adding_x = lucky * 10 + x;
    generateLuckyNumbers(lucky_adding_x, x, y);
    long long lucky_adding_y = lucky * 10 + y;
    generateLuckyNumbers(lucky_adding_y, x, y);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int x = 0; x <= 9; x++){
        for(int y = x + 1; y <= 9; y++){
            for(int init = 1; init <= 9; init++){
                if(init == x or init == y){
                    generateLuckyNumbers(init, x, y);
                }
            }
        }
    }
    cout << all_luckys.size() << '\n';
    return 0;
}