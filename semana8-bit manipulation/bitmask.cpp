#include <bits/stdc++.h>

using namespace std;

typedef long long Long;

Long getBit(Long x, Long i) {
    return (x >> i) & 1LL;
}

void turnOn(Long &x, Long i) {
    x = x | (1LL << i);
}

void turnOff(Long &x, Long i) {
    x = x & (~(1LL << i));
}

void changeBit(Long &x, Long i) {
    x = x ^ (1LL << i);
}

int main() {
    Long n = 3;
    vector<char> v;
    v.push_back('a');
    v.push_back('b');
    v.push_back('c');
    // Cantidad de subconjuntos posibles
    for (Long mask = 0; mask < (1LL << n); mask++) { // O(n * 2^n)
        cout << "{";
        // Recorremos el numero: mask
        for (Long i = 0; i < n; i++) {
            if (getBit(mask, i) == 1) {
                cout << v[i] << " ";
            }
        }
        cout << "}" << endl;
    }
    return 0;
}