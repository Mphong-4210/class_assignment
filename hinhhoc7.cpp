#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("Haidtron.inp", "r", stdin);
    freopen("Haidtron.out", "w", stdout);

    ll x1, y1, r1, x2, y2, r2;
    if (!(cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2)) return 0;

    ll d2 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    ll sub = (r1 - r2) * (r1 - r2);
    ll sum = (r1 + r2) * (r1 + r2);

    if (d2 < sub) cout << 3;      
    else if (d2 == sub) cout << 1;   
    else if (d2 < sum) cout << 2;   
    else if (d2 == sum) cout << 4;  
    else cout << 5;                 

    return 0;
}
