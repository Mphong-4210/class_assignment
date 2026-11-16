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
const int MAXN=1e3+42, MAXM=1e3, MOD=1000000007;
const int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

struct Diem {
    ll x, y;
};

int n;
Diem tg[1005][3];
bool daTham[1005];

ll tichCheo(Diem O, Diem A, Diem B) {
    ret (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

bool thuocDoan(Diem P, Diem A, Diem B) {
    ret tichCheo(A, B, P) == 0 && min(A.x, B.x) <= P.x && P.x <= max(A.x, B.x) && min(A.y, B.y) <= P.y && P.y <= max(A.y, B.y);
}

bool khacDau(ll a, ll b) {
    ret (a > 0 && b < 0) || (a < 0 && b > 0);
}

bool doanCat(Diem A, Diem B, Diem C, Diem D) {
    if (khacDau(tichCheo(A, B, C), tichCheo(A, B, D)) && khacDau(tichCheo(C, D, A), tichCheo(C, D, B))) ret true;
    ret thuocDoan(C, A, B) || thuocDoan(D, A, B) || thuocDoan(A, C, D) || thuocDoan(B, C, D);
}

bool trongTamGiac(Diem P, int i) {
    ll c1 = tichCheo(tg[i][0], tg[i][1], P);
    ll c2 = tichCheo(tg[i][1], tg[i][2], P);
    ll c3 = tichCheo(tg[i][2], tg[i][0], P);
    bool coDuong = (c1 > 0 || c2 > 0 || c3 > 0);
    bool coAm = (c1 < 0 || c2 < 0 || c3 < 0);
    ret !(coDuong && coAm);
}

bool coDiemChung(int i, int j) {
    FOR(a, 0, 2) {
        FOR(b, 0, 2) {
            if (doanCat(tg[i][a], tg[i][(a + 1) % 3], tg[j][b], tg[j][(b + 1) % 3])) ret true;
        }
    }
    ret trongTamGiac(tg[i][0], j) || trongTamGiac(tg[j][0], i);
}

void loang(int u) {
    daTham[u] = true;
    FOR(v, 0, n - 1) {
        if (!daTham[v] && coDiemChung(u, v)) loang(v);
    }
}

void manhphong(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void ffopen(string name){
    string infile = name + ".inp";
    string outfile = name + ".out";
    if(FILE* f = fopen(infile.c_str(), "r")){
        fclose(f);
        freopen(infile.c_str(), "r", stdin);
        freopen(outfile.c_str(), "w", stdout);
    }
}

void solve(){
    if (!(cin >> n)) ret;
    FOR(i, 0, n - 1) {
        FOR(k, 0, 2) {
            cin >> tg[i][k].x >> tg[i][k].y;
        }
    }

    int soVung = 0;
    FOR(i, 0, n - 1) {
        if (!daTham[i]) {
            soVung++;
            loang(i);
        }
    }
    cout << soVung << el;
}

signed main(){
    ffopen("CACTAMGIAC");

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
