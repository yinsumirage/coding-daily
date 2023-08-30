#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

char s[1001];
int nex[N][26];
int n,cnt;
bitset<1001>b[N];

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

void insert(int x){
    scanf("%s",s+1);
    int l=strlen(s+1);
    int now=0;
    for(int i=1;i<=l;i++){
        int to=s[i]-'a';
        if(!nex[now][to]){
            nex[now][to]=++cnt;
        }
        now=nex[now][to];
    }
    b[now][x]=1; // 单词在x行出现了
}

void check(){
    scanf("%s",s+1);
    int l=strlen(s+1);
    int now=0,flag=1;
    for(int i=1;i<=l;i++){
        int to=s[i]-'a';
        if(!nex[now][to]){
            flag=0;
            break;
        }
        now=nex[now][to];
    }
    if(flag){
        for(int i=1;i<=n;i++){
            if(b[now][i]){
                printf("%d ",i);
            }
        }
    }
    printf("\n");
}

signed main() {
    //fastio;
    n=read();
    for(int i=1;i<=n;i++){
        int x=read();
        for(int j=1;j<=x;j++){
            insert(i);
        }
    }
    int m=read();
    for(int i=1;i<=m;i++)check();
    //system("pause");
}