#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define l(s) (int)s.size()

void ffopen(string file){
    if(fopen((file+".inp").c_str(),"r")){
        freopen((file+".inp").c_str(),"r",stdin);
        freopen((file+".out").c_str(),"w",stdout);
    }
}

bool isPrime(ll v){
    if(v<2) return false;
    for(ll i=2;i*i<=v;i++)
        if(v%i==0) return false;
    return true;
}

int n;
vector<ll> res;

void gen(ll cur,int len){
    if(len==n){
        res.push_back(cur);
        return;
    }
    for(int d:{1,3,7,9}){
        ll nxt=cur*10+d;
        if(isPrime(nxt)) gen(nxt,len+1);
    }
}

void solve(){
    cin>>n;

    for(int d:{2,3,5,7}) gen(d,1);

    cout<<l(res)<<"\n";
    for(int i=0;i<l(res);i++)
        cout<<res[i]<<" \n"[i==l(res)-1];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ffopen("SIEUNT");
    solve();
    return 0;
}
