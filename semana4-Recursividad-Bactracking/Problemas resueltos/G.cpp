#include<bits/stdc++.h>
using namespace std;

const int N = 8;
int queen_col[N];
int score[N][N];

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

int findBestConfig(int row){
    if(row == N) {
        return 0; // configuration is complete
    }
    // make a new configuration with any possible value (0 - n-1)
    int highest_score = 0;
    for(int col_value = 0; col_value < N; col_value++){
        if(!canSetTheSquare(row, col_value)){ // pruning
            continue;
        }
        queen_col[row] = col_value;
        highest_score = max(highest_score, findBestConfig(row + 1) + score[row][col_value]);
        queen_col[row] = -1;
    }
    return highest_score;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin >> tests;
    for(int test = 1; test <= tests; test++){
        for(int i = 0; i < N; i++){
            queen_col[i] = -1;
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> score[i][j];
            }
        }
        string answer = to_string(findBestConfig(0));
        cout << string(5 - answer.size(), ' ') << answer << '\n';
    }
    return 0;
}