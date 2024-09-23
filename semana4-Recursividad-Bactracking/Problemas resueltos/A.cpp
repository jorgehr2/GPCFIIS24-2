#include <bits/stdc++.h>
using namespace std;

string str;
int n;
set<string> all_answers;

void creatingStrings(string answer, string can_use){
    if (answer.size() == n){
        all_answers.insert(answer);
        return;
    }
    for(int pos = 0; pos < can_use.size(); pos++){
        char chr = can_use[pos];
        string new_answer = answer + chr;
        string new_can_use = can_use;
        new_can_use.erase(new_can_use.begin() + pos);
        creatingStrings(new_answer, new_can_use);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> str;
    n = str.size();
    creatingStrings("", str);
    cout << all_answers.size() << '\n';
    for(auto it = all_answers.begin(); it != all_answers.end(); it++){
        cout << *it << '\n';
    }
    return 0;
}