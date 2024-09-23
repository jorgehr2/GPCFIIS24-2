#include<bits/stdc++.h>
using namespace std;

int n, t;
const int MAX_H = 10;
double glass[MAX_H][MAX_H];

void fillGlasses(int row, int col, double vol){
    if(row == n) return;
    if(col == n) return;
    glass[row][col] += vol;
    if(glass[row][col] > 1){
        double exceed = glass[row][col] - 1;
        fillGlasses(row + 1, col, exceed / 2.0);
        fillGlasses(row + 1, col + 1, exceed / 2.0);
        glass[row][col] = 1;
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> t;
    fillGlasses(0, 0, t);
    int answer = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            answer += glass[i][j] == 1;
        }
    }
    cout << answer << '\n';
    return 0;
}