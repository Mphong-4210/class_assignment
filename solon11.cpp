#include<bits/stdc++.h>
using namespace std;
string tru(string a,int b){
    int i=a.size()-1;
    while(b>0&&i>=0){
        int x=b%10;
        b/=10;
        int y=(a[i]-'0')-x;
        if(y<0){
            y+=10;
            b++;
        }
        a[i]=y+'0';
        i--;
    }
    while(a.size()>1&&a[0]=='0')
        a.erase(0,1);
    return a;
}
string cong(string a,int b){
    int i=a.size()-1;
    while(b>0&&i>=0){
        int x=(a[i]-'0')+b;
        a[i]=x%10+'0';
        b=x/10;
        i--;
    }
    while(b>0){
        a=char(b%10+'0')+a;
        b/=10;
    }
    return a;
}
int tong(string a){
    int s=0;
    for(int i=0;i<a.size();i++)
        s+=a[i]-'0';
    return s;
}
int main(){
    string m,n;
    cin>>m;
    if(m.size()<=3){
        int x=stoi(m);
        int bd=max(1,x-1000);
        for(int i=bd;i<x;i++){
            int t=i,s=i;
            while(t>0){
                s+=t%10;
                t/=10;
            }
            if(s==x){
                cout<<i;
                return 0;
            }
        }
    }
    else{
        n=tru(m,1000);
        for(int i=0;i<1000;i++){
            if(cong(n,tong(n))==m){
                cout<<n;
                return 0;
            }
            n=cong(n,1);
        }
    }
    cout<<0;
}
