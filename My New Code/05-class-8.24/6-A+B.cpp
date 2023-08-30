#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 5;

int t;
char a[N],b[N],c[N],a1[N],b1[N];

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
    t=read();
    while(t--){
        scanf("%s %s",a1,b1);
        int la=strlen(a1),lb=strlen(b1),l=max(la,lb),las=0,anslen=0;
        for(int i=0;i<la;i++){
            a[i]=a1[la-i-1];
        }
        for(int i=0;i<lb;i++){
            b[i]=b1[lb-i-1];
        }
        for(int i=0;i<l;i++){
            if(a[i]=='1'){
                if(b[i]=='1'){
                    if(las){
                        c[i]='1';
                        las=1;
                    }
                    else {
                        c[i]='0';
                        las=1;
                    }
                }
                else{
                    if(las){
                        c[i]='0';
                        las=1;
                    }
                    else {
                        c[i]='1';
                        las=0;
                    }
                }
            }
            else {
                if(b[i]=='1'){
                    if(las){
                        c[i]='0';
                        las=1;
                    }
                    else{
                        c[i]='1';
                        las=0;
                    }
                }
                else{
                    c[i]=las+'0';
                    las=0;
                }
            }
        }
        if(las==1){
            anslen=l+1;
            c[l]='1';
        }
        else anslen=l;
        for(int i=1;i<=2+anslen-la;i++)printf(" ");
        for(int i=0;i<la;i++)printf("%c",a1[i]);
        printf("\n");
        printf("+");
        for(int i=1;i<2+anslen-lb;i++)printf(" ");
        for(int i=0;i<lb;i++)printf("%c",b1[i]);
        printf("\n");
        for(int i=1;i<=anslen+2;i++)printf("-");
        printf("\n");printf("  ");
        for(int i=anslen-1;i>=0;i--)printf("%c",c[i]);
        printf("\n");
        for(int i=0;i<la;i++)a[i]=0;
        for(int i=0;i<lb;i++)b[i]=0;
    }
    system("pause");
}