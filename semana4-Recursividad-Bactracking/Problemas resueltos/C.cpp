#include<bits/stdc++.h>
using namespace std;

const int LEN = 4;
int cells[LEN][LEN];

bool canSetTheCell(int row, int col, int value){
    // Check in the row "row"
    for(int c = 0; c < LEN; c++){
        if(c == col) {
            continue;
        }
        if(cells[row][c] == value){
            return false;
        }
    }
    // Check in the column "col"
    for(int r = 0; r < LEN; r++){
        if(r == row){
            continue;
        }
        if(cells[r][col] == value){
            return false;
        }
    }
    // Check in the corresponding 2x2 board
    /*+-----+-----+*/
    /*|*****|*****|*/
    /*|*0,0*|*0,1*|*/
    /*|*****|*****|*/
    /*+-----+-----+*/
    /*|*****|*****|*/
    /*|*1,0*|*1,1*|*/
    /*|*****|*****|*/
    /*+-----+-----+*/
    int row_board = row / 2, col_board = col / 2;
    for(int r = row_board * 2; r < row_board * 2 + 2; r++){
        for(int c = col_board * 2; c < col_board * 2 + 2; c++){
            if(r == row && c == col){
                continue;
            }
            if(cells[r][c] == value){
                return false;
            }
        }
    }
    return true;
}

bool findSudoku(int row, int col){
    if(row == LEN){ // configuration is complete
        return true;
    }
    if(col == LEN){ // row is complete, go to the next row
        return findSudoku(row + 1, 0);
    }
    if(1 <= cells[row][col] && cells[row][col] <= 4){ // cell is complete, go to the next column
        return findSudoku(row, col + 1);
    } else { // make a new configuration with any possible value (1 - 4)
        for(int value = 1; value <= 4; value++){
            if(!canSetTheCell(row, col, value)){ // pruning
                continue;
            }
            cells[row][col] = value; // make
            if(findSudoku(row, col + 1)){ // find a sudoku with a new configuration
                return true;
            }
            cells[row][col] = 0; // undo
        }
        return false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin >> tests;
    for(int test = 1; test <= tests; test++){
        for(int i = 0; i < LEN; i++){
            for(int j = 0; j < LEN; j++){
                char number;
                cin >> number;
                if(number == '*') {
                    cells[i][j] = 0;
                } else {
                    cells[i][j] = number - '0';
                }
            }
        }
        bool search_a_sol = findSudoku(0, 0);
        cout << "Case #" << test << ":\n";
        for(int i = 0; i < LEN; i++){
            for(int j = 0; j < LEN; j++){
                cout << cells[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}