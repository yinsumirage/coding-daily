#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e5 + 5;

int n,m;
int ans=0x3f3f3f3f;

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


signed main() {
    //fastio;
    int l[N],r[N],bad=0,lt=0,rt=0;
    char s[20],s1[20];
    while(n=read()){
        scanf("%s",s);
        scanf("%s",s1);
        if(s1[0]=='l'){
            l[++lt]=n;
        }
        else if(s1[0]=='h'){
            r[++rt]=n;
        }
        if(s[0]=='r'){
            for(int i=1;i<=lt;i++){
                if(bad==1)break;
                if(l[i]>=n)bad=1;
            }
            for(int i=1;i<=rt;i++){
                if(bad==1)break;
                if(r[i]<=n)bad=1;
            }
            if(bad)printf("Tom is dishonest\n");
            else printf("Tom may be honest\n");
            memset(l,0,sizeof(l));
            memset(r,0,sizeof(r));
            lt=0,rt=0,bad=0;
            continue;
        }
    }
    //system("pause");
}