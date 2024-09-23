#include<bits/stdc++.h>
using namespace std;

string s, t;
int targetScore;

double findProbability(int pos, int score){
    if(pos == t.size()){ // config is complete
        return score == targetScore;
    }
    if(t[pos] == '+'){
        return findProbability(pos + 1, score + 1);
    } else if(t[pos] == '-'){
        return findProbability(pos + 1, score - 1);
    } else {
        return 0.5 * (findProbability(pos + 1, score + 1) + findProbability(pos + 1, score - 1)); // the prob of get score by using + or - command
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> s >> t;
    targetScore = 0;
    for(int i = 0; i < s.size(); i++){
        targetScore += s[i] == '+';
        targetScore -= s[i] == '-';
    }
    cout << fixed << setprecision(9) << findProbability(0, 0) << '\n';
}