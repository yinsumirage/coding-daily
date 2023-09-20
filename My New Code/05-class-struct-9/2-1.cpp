#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 1e6 + 5;

int n,okk=1;

map<int,string>m;

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
    n=read();
    for(int i=1;i<=n;i++){
        int x=read();
        string s;
        cin>>s;
        m.insert({x,s});
    }
    n=read();
    if(n==0){
        printf("the LIST2 is NULL.\n");
        return 0;
    }
    for(int i=1;i<=n;i++){
        int x=read();
        string s;
        cin>>s;
        if(m.find(x)==m.end()){
            printf("%8d ",x);
            cout<<s;
            printf(" is not in LIST1.\n");
            okk=0;
        }
        else if(m[x]!=s){
            printf("%8d ",x);
            cout<<s;
            printf(" is not in LIST1.\n");
            okk=0;
        }
    }
    if(okk)printf("the records of LIST2 are all in the LIST1.\n");
    system("pause");
}