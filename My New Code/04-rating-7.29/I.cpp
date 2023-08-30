#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e5 + 5;


ll n,m;
int a[N],live[N];
int zu[N],cnt=0;
set<int> per[N];

inline ll read(){
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

signed main() {
    fastio;
    n=read();
    m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        live[i]=1;
    }
    for(int i=1;i<=m;i++){
        int op=read(),x=read();
        if(op==1){
            int y=read();
            if(live[x]==0||live[y]==0)continue;
            if(zu[x]==zu[y]&&zu[x]!=0)continue;
            if(zu[x]==0&&zu[y]==0){
                cnt++;
                zu[y]=zu[x]=cnt;
                per[cnt].insert(y);
                per[cnt].insert(x);
            }
            else if(zu[x]==0){
                zu[x]=zu[y];
                per[zu[y]].insert(x);
            }
            else if(zu[y]==0){
                zu[y]=zu[x];
                per[zu[y]].insert(y);
            }
            else {
                for(auto j=per[zu[y]].begin();j!=per[zu[y]].end();j++){
                    per[zu[x]].insert(*j);
                }
                per[zu[y]].clear();
            }
        }
        if(op==2){
            if(live[x]==0)printf("-1\n");
            else {
                int mi=0x3f3f3f3f;
                int hao=N-5;
                int zuhao=zu[x];
                int power;
                if(zuhao==0){
                    printf("%d\n",a[x]);
                    live[x]=0;
                }
                for(auto j=per[zuhao].begin();j!=per[zuhao].end();j++){
                    power=a[*j];
                    if(mi>power){
                        mi=power;hao=*j;
                    }
                    else if(mi==power){
                        if(hao>*j)hao=*j;
                    }
                }
                printf("%d\n",mi);
                live[hao]=0;
                per[zuhao].erase(hao);
            }
        }
    }
    //system("pause");
}