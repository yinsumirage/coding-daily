#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e2+5;

int pre[N],rak[N],sum[N],siz[N],tru[N],tot;

void init(int n){
    for(int i=1;i<=n;i++){
        pre[i]=i;rak[i]=1;siz[i]=1;sum[i]=i;
    }
}

int find(int x){
    if(pre[x]==x)return x;
    return pre[x]=find(pre[x]);
}

bool join(int x,int y){
    if(tru[x])x=tru[x];
    if(tru[y])y=tru[y];
    x=find(x),y=find(y);
    if(x==y)return false;
    if(rak[x]>rak[y]){
        pre[y]=x;
        siz[x]+=siz[y];
        sum[x]+=sum[y];
    }
    else {
        if(rak[x]==rak[y])rak[y]++;
        pre[x]=y;
        siz[y]+=siz[x];
        sum[y]+=sum[x];
    }
    return true;
}

void move(int x,int y){
    int tmp=x;
    x=find(x);y=find(y);
    if(x==y)return;
    tru[tmp]=++tot;
    pre[tru[tmp]]=y;
    siz[y]++;
    sum[y]+=tmp;
    siz[x]--;
    sum[x]-=tmp;
}

void query(int x){
    if(tru[x])x=tru[x];
    x=find(x);
    printf("%d %d\n",siz[x],sum[x]);
}

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
    int n,m;
    while(1){
        scanf("%d %d",&n,&m);
        if(tot>n)init(tot);
        else init(n);
        tot=n;
        while(m--){
            int op=read(),p=read();
            if(op==1){
                int q=read();
                join(p,q);
            }
            else if(op==2){
                int q=read();
                move(p,q);
            }
            else{
                query(p);
            }
        }
        for(int i=1;i<=tot;i++){
            tru[i]=0;
        }
    }
    system("pause");
}