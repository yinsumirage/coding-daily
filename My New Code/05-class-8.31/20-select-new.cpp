#include<iostream>
using namespace std;
typedef long long ll;
const int N = 2e5 + 20;

int n;
int d=0,x=0,dn,xn,ds,xs;
int D[N],X[N];
char s[N];

int main(){
    cin>>n;
    cin>>s;
    while(1){
        d=x=ds=xs=dn=xn=0;
        for(int i=0;i<n;i++){
            if(s[i]=='D'){
                if(x==0){
                    if(xn>0)xs++;
                    else d++;
                    dn++;
                    D[dn]=i;
                }
                else if(x>0){
                    x--;
                }
            }
            else {
                if(d==0){
                    if(dn>0)ds++;
                    else x++;
                    xn++;
                    X[xn]=i;
                }
                else if(d>0){
                    d--;
                }
            }
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
                s[n]='X';
                n++;
            }
            else {
                ds++;
                s[n]='D';
                n++;
            }
        }
        while(dn>ds){
            s[n]='D';
            n++;
            ds++;
        }
        while(xn>xs){
            s[n]='X';
            n++;
            xs++;
        }
    }
    system("pause");
}