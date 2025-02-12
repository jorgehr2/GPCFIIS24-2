#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    set<string> S = {"purple", "green", "blue", "orange", "red", "yellow"};
    map<string, string> M;
    M["purple"] = "Power";
    M["green"] = "Time";
    M["blue"] = "Space";
    M["orange"] = "Soul";
    M["red"] = "Reality";
    M["yellow"] = "Mind";
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        S.erase(s);
    }
    vector<string> ans;
    for (string s : S) {
        ans.push_back(M[s]);
    }
    cout << ans.size() << endl;
    for (string s : ans) cout << s << endl;
}