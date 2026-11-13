#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;
typedef float fl;
typedef long double ldb;
typedef unsigned long long ull;
typedef string str;
#define vll vector<ll>
#define pll pair<ll,ll>
#define mll map<ll,ll>
#define dq deque<ll>
#define ret return
#define si size()
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define bend(x) (x).begin(), (x).end()
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define FORN(i,a,b) for(int i=(a); i>=(b); i--)
// Phong

const ll INF = 4e18, NINF = -4e18;
const int MAXN=1e6+42, MAXM=1e3, MOD=1000000007;
const int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

int n;
ll x[505], y[505];

void manhphong(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void ffopen(string name){
    string infile=name + ".inp";
    string outfile=name + ".out";
    if(FILE* f = fopen(infile.c_str(), "r")){
        fclose(f);
        freopen(infile.c_str(), "r", stdin);
        freopen(outfile.c_str(), "w", stdout);
    }
}

void solve(){
    if (!(cin >> n)) ret;
    FOR(i, 0, n - 1) cin >> x[i] >> y[i];

    ll ans = 0;
    FOR(i, 0, n - 1){
        map<pll, ll> cnt;
        FOR(j, 0, n - 1){
            if(j == i) continue;
            ll a = x[j] - x[i], b = y[j] - y[i];
            ll g = __gcd(llabs(a), llabs(b));
            a /= g; b /= g;
            cnt[{a, b}]++;
        }
        
        for(auto &p : cnt){
            ll a = p.fi.fi, b = p.fi.se;
            auto it = cnt.find({-b, a});
            if(it != cnt.end()) ans += p.se * it->se;
        }
    }
    cout << ans << el;
}

signed main(){
    ffopen("CTAMGIACV");

    manhphong();

    solve();
    
    ret 0;
}

/*
    ____  _                         
   / __ \| |__   ___  _ __   __ _ 
  / /_/ | '_ \ / _ \| '_ \ / _` |
  \___  | | | | (_) | | | | (_| |
  (_)   |_| |_|\___/|_| |_|\__, |
                           |___/                         
*/
