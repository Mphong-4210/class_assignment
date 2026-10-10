#include<bits/stdc++.h>
using namespace std;
long long nhan(long long a,long long b,long long m){
    a%=m;
    b%=m;
    long long s=0;
    while(b>0){
        if(b%2==1)
            s=(s+a)%m;
        a=(a+a)%m;
        b/=2;
    }
    return s;
}
int main(){
    long long a,b,c,m;
    cin>>a>>b>>c>>m;
    long long x[3]={a,b,c};
    sort(x,x+3);
    long long p,q;
    if(x[1]<0){
        p=-x[0];
        q=-x[1];
    }
    else{
        p=x[1];
        q=x[2];
    }
    cout<<nhan(p,q,m);
    return 0;
}
