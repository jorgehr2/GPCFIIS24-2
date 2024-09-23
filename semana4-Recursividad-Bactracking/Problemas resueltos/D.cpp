#include<bits/stdc++.h>
using namespace std;

int n;
const int LEN = 15;
int queen_col[LEN];
bool blocked[LEN][LEN];

bool canSetTheSquare(int row, int col_value){
    // Check any queen in the same column
    for(int r = 0; r < row; r++){
        if(queen_col[r] == col_value){
            return false;
        }
    }
    // Check any queen in the left diagonal
    /*+--------+*/
    /*|Q*******|*/
    /*|********|*/
    /*|**Q*****|*/
    /*+--------+*/
    for(int r = 0; r < row; r++){
        if(r - queen_col[r] == row - col_value){
            return false;
        }
    }
    // Check any queen in the right diagonal
    /*+--------+*/
    /*|****Q***|*/
    /*|********|*/
    /*|**Q*****|*/
    /*+--------+*/
    for(int r = 0; r < row; r++){
        if(r + queen_col[r] == row + col_value){
            return false;
        }
    }
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
        if(!canSetTheSquare(row, col_value)){ // pruning
            continue;
        }
        queen_col[row] = col_value; // make
        tot_configs += findTotNQueenConfig(row + 1); // add all possible configurations to the answer
        queen_col[row] = -1; // undo
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