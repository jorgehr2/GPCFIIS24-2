#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> moves;

void towerOfHanoi(int num_disks, int source, int auxiliary, int destination){
    if(num_disks == 0){
        return;
    }
    towerOfHanoi(num_disks - 1, source, destination, auxiliary);
    moves.push_back(make_pair(source, destination));
    towerOfHanoi(num_disks - 1, auxiliary, source, destination);
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    towerOfHanoi(n, 1, 2, 3);
    cout << moves.size() << '\n';
    for(int i = 0; i < moves.size(); i++){
        cout << moves[i].first << ' ' << moves[i].second << '\n';
    }
    return 0;
}