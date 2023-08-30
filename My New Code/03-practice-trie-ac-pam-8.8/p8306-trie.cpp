#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 3e6 + 5;

int n,m,T;
int ans=0x3f3f3f3f;
int t[N][130],cnt[N],tot;
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

int getnum(char x){
    if(x>='A'&&x<='Z')return x-'A';
    else if(x>='a'&&x<='z')return x-'a'+26;
    else return x-'0'+52;
}

void insert(char s[]){
    int p=0,l=strlen(s);
    for(int i=0;i<l;i++){
        int c=getnum(s[i]);
        if(!t[p][c])t[p][c]=++tot;
        p=t[p][c]; //从p这个节点指向c
        cnt[p]++;
    }
}

int find(char s[]){
    int p=0,l=strlen(s);
    for(int i=0;i<l;i++){
        int c=getnum(s[i]);
        if(!t[p][c])return 0;
        p=t[p][c];
    }
    return cnt[p];
}

signed main() {
    //fastio;
    T=read();
    while(T--){
        n=read();m=read();
        for(int i=0;i<tot;i++){
            for(int j=0;j<=128;j++){
                t[i][j]=0;
            }
        }
        for(int i=0;i<=tot;i++)cnt[i]=0;
        tot=0;
        for(int i=0;i<n;i++){
            cin>>s;
            insert(s);
        }
        for(int i=0;i<m;i++){
            cin>>s;
            printf("%d\n",find(s));
        }
    }

    //system("pause");
}