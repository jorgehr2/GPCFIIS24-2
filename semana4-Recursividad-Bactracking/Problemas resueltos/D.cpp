#include<bits/stdc++.h>
using namespace std;

int n;
const int LEN = 15;
int queen_col[LEN];
bool blocked[LEN][LEN];
bool used_col[LEN];
bool used_left_diag[2 * LEN];
bool used_right_diag[2 * LEN];

bool canSetTheSquareOptime(int row, int col_value){
    if(used_col[col_value]) return false;
    if(used_left_diag[row - col_value + n]) return false;
    if(used_right_diag[row + col_value]) return false;
    return true;
}

int findTotNQueenConfig(int row){
    if(row == n) {
        return 1; // configuration is complete
    }
    // make a new configuration with any possible value (0 - n-1)
    int tot_configs = 0;
    for(int col_value = 0; col_value < n; col_value++){
        if(blocked[row][col_value]){ // pruning
            continue;
        }
        if(!canSetTheSquareOptime(row, col_value)){ // pruning
            continue;
        }
        queen_col[row] = col_value; // make
        used_col[col_value] = true;
        used_left_diag[row - col_value + n] = true;
        used_right_diag[row + col_value] = true;
        tot_configs += findTotNQueenConfig(row + 1); // add all possible configurations to the answer
        queen_col[row] = -1; // undo
        used_col[col_value] = false;
        used_left_diag[row - col_value + n] = false;
        used_right_diag[row + col_value] = false;
    }
    return tot_configs;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    while(cin >> n && n != 0){
        for(int r = 0; r < n; r++){
            queen_col[r] = -1;
        }
        for(int i = 0; i < n; i++){
            used_col[i] = false;
        }
        for(int i = 0; i < 2 * n; i++){
            used_left_diag[i] = false;
            used_right_diag[i] = false;
        }
        for(int r = 0; r < n; r++){
            for(int c = 0; c < n; c++){
                char square;
                cin >> square;
                if(square == '*'){
                    blocked[r][c] = true;
                } else {
                    blocked[r][c] = false;
                }
            }
        }
        cout << "Case " << test << ": " << findTotNQueenConfig(0) << '\n';
        test++;
    }
    return 0;
}