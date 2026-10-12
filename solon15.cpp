#include<bits/stdc++.h>
using namespace std;
long long ucln(long long a,long long b){
    while(b!=0){
        long long r=a%b;
        a=b;
        b=r;
    }
    return a;
}
string nhan(string a,long long b){
    string s="";
    long long nho=0;
    for(int i=a.size()-1;i>=0;i--){
        long long x=(a[i]-'0')*b+nho;
        s+=char(x%10+'0');
        nho=x/10;
    }
    while(nho>0){
        s+=char(nho%10+'0');
        nho/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}
long long du(string a,long long b){
    long long r=0;
    int n=a.size();
    for(int i=0;i<n;i++){
        r=(r*10+a[i]-'0')%b;
    }
    return r;
}
int main(){
    int n;
    cin>>n;
    long long a[105];
    for(int i=0;i<n;i++)
        cin>>a[i];
    long long g=a[0];
    for(int i=1;i<n;i++)
        g=ucln(g,a[i]);
    string b="1";
    for(int i=0;i<n;i++){
        long long r=du(b,a[i]);
        long long d=ucln(r,a[i]);
        b=nhan(b,a[i]/d);
    }
    cout<<g<<endl;
    cout<<b;
    return 0;
}
