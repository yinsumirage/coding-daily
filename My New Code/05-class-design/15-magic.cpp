#include<iostream>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;

int n,a[N],ji=0,row=2,biao=0,bia=0,x;

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
    for(int i=1;i<=n;i++){
        x=read();
    }
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=1;i<=n;i++){
        if(a[i]==1){
            ji=i;break;
        }
    }
    for(int i=ji+1;i<=n;i++){
        if(a[i]!=row){
            biao=1;
            break;
        }
        row++;
    }
    if(!biao){
        if(ji!=1&&a[ji-1]!=0){
            bia=1;
        }
        else {
            for(int i=ji-2,j=1;i>0;i--){
                if(a[i]<=n-j&&a[i]!=0){
                    bia=1;
                    break;
                }
                j++;
            }
        }
        if(!bia){
            printf("%d\n",ji-1);
        }
        else printf("%d\n",n+ji);
        system("pause");
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==0)continue;
        else{
            if(a[i]<i+1){
                bia=max(bia,i+1-a[i]);
            }
        }
    }
    printf("%d\n",n+bia);
    system("pause");
}