#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
#define all(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define int ll

void fre(const char *name)
{
    string s = name;
    if (ifstream(s + ".INP").good())
    {
        freopen((s + ".INP").c_str(), "r", stdin);
        freopen((s + ".OUT").c_str(), "w", stdout);
    }
}

typedef pair<int, int> P;

int cat(P p, P q, P r)
{
    return (q.first - p.first) * (r.second - p.second) - (q.second - p.second) * (r.first - p.first);
}

int check(int x)
{
    if (x > 0)
        return 1;
    if (x < 0)
        return -1;
    return 0;
}

signed main()
{
    fast;
    fre("Haidoanthang");

    P a, b, c, d;
    cin >> a.first >> a.second >> b.first >> b.second;
    cin >> c.first >> c.second >> d.first >> d.second;

    int c1 = check(cat(a, b, c)), c2 = check(cat(a, b, d));
    int c3 = check(cat(c, d, a)), c4 = check(cat(c, d, b));

    if (c1 == 0 && c2 == 0 && c3 == 0 && c4 == 0)
    {

        if (a > b)
            swap(a, b);
        if (c > d)
            swap(c, d);
        P l = max(a, c), r = min(b, d);
        if (l > r)
            cout << 4 << "\n";
        else if (l == r)
            cout << 1 << "\n";
        else
            cout << 2 << "\n";
    }
    else
{
    if (c1 * c2 < 0 && c3 * c4 < 0)
        cout << 3 << "\n";         
    else if (c1 * c2 <= 0 && c3 * c4 <= 0)
        cout << 1 << "\n";          
    else
        cout << 4 << "\n";
}

    return 0;
}
