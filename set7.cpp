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

void solve(){
    string s;
    cin>>s;
    int n=l(s);

    set<ll> primes;
    for(int i=0;i<n;i++){
        ll cur=0;
        for(int j=i;j<n;j++){
            cur=cur*10+(s[j]-'0');
            if(isPrime(cur)) primes.insert(cur);
        }
    }

    if(primes.empty()) cout<<"NO PRIMES";
    else cout<<l(primes);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ffopen("PRIME");
    solve();
    return 0;
}
