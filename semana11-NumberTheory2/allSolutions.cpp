#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll extendedGcd(ll a, ll b, ll &x, ll &y) {
	if(b == 0){
		x = a >= 0 ? 1: -1, y = 0;
		return abs(a);
	} else {
		ll x2, y2, g = extendedGcd(b, a % b , x2, y2);
		x = y2, y = x2 - (a / b) * y2;
		return g;
	}
}

bool diophantine(ll a, ll b, ll c, ll &x, ll &y, ll &g) {
    if(a == 0 && b == 0){
		if(c != 0) 
            return false;
		else {
			x = y = g = 0;
			return true;
		}
	} else {
        g = extendedGcd(a, b, x, y);
        if (c % g != 0) 
            return false;
        else {
            x *= c / g, y *= c / g;
            return true;
        }
    }
}

ll divDown(ll a, ll b){
    ll d = abs(a) / abs(b);
    if((a > 0 && b > 0) || (a < 0 && b < 0))
        return d;
    else
        return a % b == 0 ? -d: -d - 1;
}

ll divUp(ll a, ll b){
    ll d = abs(a) / abs(b);
    if((a > 0 && b > 0) || (a < 0 && b < 0))
        return a % b ? d: d + 1;
    else
        return -d;
}

vector<pair<ll, ll>> getAllSolutions(ll a, ll b, ll c, ll lx, ll rx, ll ly, ll ry) {
    ll x0, y0, g;
    if (!diophantine(a, b, c, x0, y0, g)) 
        return {};
    vector<pair<ll, ll>> sols;
	ll k_min, k_max;
    if(b > 0){
        k_min = divUp((lx - x0) * g , b);
        k_max = divDown((rx - x0) * g , b);
    } else {
        k_min = divUp((rx - x0) * g , b);
        k_max = divDown((lx - x0) * g , b);
    }
    if(a > 0){
        k_min = max(k_min , divUp((y0 - ry) * g , a));
        k_max = min(k_max, divDown((y0 - ly) * g , a) );
    } else {
        k_min = max(k_min, divUp((y0 - ly) * g , a));
        k_max = min(k_max, divDown((y0 - ry) * g , a));
    }
	for(ll k = k_min; k <= k_max; k++)
		sols.push_back(make_pair(x0 + k * (b / g) , y0 - k * (a / g)));
	return sols;
}
