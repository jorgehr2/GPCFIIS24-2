#include <bits/stdc++.h>

using namespace std;

void solveGame(int n, vector<int> fst, vector<int> snd)
{
    queue<int> q_fst, q_snd;
    for (int val : fst)
    {
        q_fst.push(val);
    }
    for (int val : snd)
    {
        q_snd.push(val);
    }
    set<queue<int>> s_fst, s_snd;
    int fights = 0;
    while (s_fst.find(q_fst) == s_fst.end() || s_snd.find(q_snd) == s_snd.end())
    {
        s_fst.insert(q_fst);
        s_snd.insert(q_snd);
        fights++;
        int fst_card = q_fst.front();
        int snd_card = q_snd.front();
        q_fst.pop();
        q_snd.pop();
        if (fst_card > snd_card)
        {
            q_fst.push(snd_card);
            q_fst.push(fst_card);
        }
        else
        {
            q_snd.push(fst_card);
            q_snd.push(snd_card);
        }
        if (q_fst.empty())
        {
            cout << fights << ' ' << 2 << '\n';
            return;
        }
        else if (q_snd.empty())
        {
            cout << fights << ' ' << 1 << '\n';
            return;
        }
    }
    cout << -1 << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> fst, snd;
    int sz_fst, sz_snd;
    cin >> sz_fst;
    for (int i = 0; i < sz_fst; i++)
    {
        int val;
        cin >> val;
        fst.push_back(val);
    }
    cin >> sz_snd;
    for (int i = 0; i < sz_snd; i++)
    {
        int val;
        cin >> val;
        snd.push_back(val);
    }
    solveGame(n, fst, snd);
    return 0;
}