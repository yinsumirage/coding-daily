#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int n,m,k=0;
char s[N];
int len[N],num[N],fail[N];
int cur,pos,trie[N][26],tot=1;

int getfail(int x,int i){
    while(i-len[x]-1<0||s[i-len[x]-1]!=s[i])x=fail[x];
    return x;
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

signed main() {
    //fastio;
    cin>>(s);
    n=strlen(s);
    fail[0]=1;
    len[1]=-1;
    for(int i=0;i<n;i++){
        if(i>=1)s[i]=(s[i]-97+k)%26+97;
        pos=getfail(cur,i);
        if(!trie[pos][s[i]-'a']){
            fail[++tot]=trie[getfail(fail[pos],i)][s[i]-'a'];
            trie[pos][s[i]-'a']=tot;
            len[tot]=len[pos]+2;
            num[tot]=num[fail[tot]]+1;
        }
        cur=trie[pos][s[i]-'a'];
        k=num[cur];
        printf("%d ",k);
    }
    system("pause");
}