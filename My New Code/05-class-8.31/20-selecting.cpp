#include<iostream>
#include<string.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5 + 5;

int n;
int d=0,x=0,dn,xn,ds,xs;
int D[N],X[N];
char s[N];

inline ll read(){//read和cin不能同时处理字符
    ll x=0,f=1;
    char c=getchar();
    while(c>'9'||c<'0'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c^48);
        c=getchar();
    }
    return x*f;
}

int main(){
    n=read();
    cin>>s;
    while(1){
        d=x=ds=xs=dn=xn=0;
        for(int i=0;i<n;i++){
            if(s[i]=='D'){
                if(x==0){
                    d++;
                    D[++dn]=i;
                }
                else if(x>0){
                    x--;
                }
            }
            else {
                if(d==0){
                    x++;
                    X[++xn]=i;
                }
                else if(d>0){
                    d--;
                }
            }
        }
        while(x>0&&dn>ds){
            ds++;
            x--;
        }
        while(d>0&&xn>xs){
            xs++;
            d--;
        }
        if(xn==xs&&dn>ds){
            printf("D\n");
            break;
        }
        if(dn==ds&&xn>xs){
            printf("X\n");
            break;
        }
        n=0;
        while(dn>ds&&xn>xs){
            if(D[ds+1]>X[xs+1]){
                xs++;                    
                s[n++]='X';
            }
            else {
                ds++;
                s[n++]='D';
            }
        }
        while(dn>ds){
            s[n++]='D';
            ds++;
        }
        while(xn>xs){
            s[n++]='X';
            xs++;
        }
    }
    system("pause");
}