#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 5e5 + 5;

int n;
ll ans=0,tot;
int a[N],trie[N][100],num[N],tree[N];
string s;

void insert(string s,int x){
    int p=0;
    for(int i=0;i<s.size();i++){
        if(!trie[p][s[i]-'A'])trie[p][s[i]-'A']=++tot;
        p=trie[p][s[i]-'A'];
    }
    num[p]=x;
}

int get(string s){
    int p=0;
    for(int i=0;i<s.size();i++){
        p=trie[p][s[i]-'A'];
    }
    return num[p];
}

int lowbit(int x){
    return x&(-x);
}

void add(int x,int k){
    for(;x<=n;x+=lowbit(x))tree[x]+=k;
}

ll query(int x){
    ll tmp=0;
    for(;x;x-=lowbit(x)){
        tmp+=tree[x];
    }
    return tmp;
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
    n=read();
    for(int i=1;i<=n;i++){
        cin>>s;
        insert(s,i);
    }
    for(int i=1;i<=n;i++){
        cin>>s;
        a[i]=get(s);
    }
    for(int i=1;i<=n;i++){
        add(a[i],1);
        ans+=i-query(a[i]);
    }
    printf("%lld",ans);
    system("pause");
}