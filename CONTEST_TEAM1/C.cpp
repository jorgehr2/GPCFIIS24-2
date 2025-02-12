#include <bits/stdc++.h>
#define pb push_back
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
#define all(s) s.begin(), s.end()
using namespace std;
typedef long long ll;
#define Rep0(i, n) for (ll i = 0; i < (ll)n; i++)
#define Rep1(i, n) for (ll i = 1; i <= (ll)n; i++)
#define Repi0(i, n) for (ll i = n - 1; i >= 0; i--)
#define Repi1(i, n) for (ll i = n; i >= 1; i--)
#define POT(x) ((x) * (x))
const ll MX = 1e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e18;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);
typedef long double ld;
typedef unsigned long long ull;
const int ALPH = 256;

char valores[52][52];
int main() {
    inic;
    inic2;
    ll n, m;
    cin >> n >> m;
    Rep1(i, n) {
        Rep1(j, m) {
            cin >> valores[i][j];
        }
    }
    ll cont = 0;
    set<char> se;
    Rep1(i, n - 1) {
        Rep1(j, m - 1) {
            if (valores[i][j] == 'f' || valores[i][j] == 'a' || valores[i][j] == 'c' ||
                valores[i][j] == 'e') {
                se.insert(valores[i][j]);
            }
            if (valores[i][j + 1] == 'f' || valores[i][j + 1] == 'a' ||
                valores[i][j + 1] == 'c' || valores[i][j + 1] == 'e') {
                se.insert(valores[i][j + 1]);
            }
            if (valores[i + 1][j + 1] == 'f' || valores[i + 1][j + 1] == 'a' ||
                valores[i + 1][j + 1] == 'c' || valores[i + 1][j + 1] == 'e') {
                se.insert(valores[i + 1][j + 1]);
            }
            if (valores[i + 1][j] == 'f' || valores[i + 1][j] == 'a' ||
                valores[i + 1][j] == 'c' || valores[i + 1][j] == 'e') {
                se.insert(valores[i + 1][j]);
            }
            if (se.size() == 4) {
                // cout<<"Para i: "<<i<<"j: "<<j<<endl;
                cont++;
            }
            // if(i==1 && j==2){
            //     cout<<se.size()<< " asfdadsad " <<endl;
            // }
            se.clear();
        }
    }
    cout << cont << endl;
    return 0;
}