#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

ll n,m;
string s;
int cnt=0; //trie的指针

struct Trie{
    int fail; //失配指针
    int vis[26]; //子节点的位置
    int end;  //标记有几个单词以次结尾
}AC[N];

void build(string s){
    int l=s.length();
    int now=0;
    for(int i=0;i<l;i++){
        if(AC[now].vis[s[i]-'a']==0)AC[now].vis[s[i]-'a']=++cnt;
        now=AC[now].vis[s[i]-'a'];
    }
    AC[now].end+=1;
}

void get_fail(){
    queue<int>q;
    for(int i=0;i<26;i++){
        if(AC[0].vis[i]!=0){ //找下第一个节点指啥
            AC[AC[0].vis[i]].fail=0; //指向根节点
            q.push(AC[0].vis[i]);
        }
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<26;i++){  //枚举他所有的子节点
            if(AC[x].vis[i]!=0){
                AC[AC[x].vis[i]].fail=AC[AC[x].fail].vis[i];
                //子节点的fail指针指向当前节点的fail指针指向节点的相同子节点
                q.push(AC[x].vis[i]);
            }
            else AC[x].vis[i]=AC[AC[x].fail].vis[i];
        }
    }
}

int AC_query(string s){
    int l=s.length();
    int now=0,ans=0;
    for(int i=0;i<l;i++){
        now=AC[now].vis[s[i]-'a'];
        for(int t=now;t&&AC[t].end!=-1;t=AC[t].fail){
            ans+=AC[t].end;
            AC[t].end=-1;
        }
    }
    return ans;
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
        build(s);
    }
    AC[0].fail=0;
    get_fail();
    cin>>s;
    printf("%d",AC_query(s));
    system("pause");
}