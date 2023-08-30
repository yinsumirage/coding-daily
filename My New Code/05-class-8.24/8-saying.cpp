#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 5;

int n,tot=0,ans=0;
ll x[N];
ll base=233;
ll mod=1e9+7;
string s;

ll hash0(string s){
    ll l=s.size();
    ll ans=0;
    for(int i=0;i<l;i++){
        ans=(ans*base+(ll)s[i])%mod;
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


int main(){
    n=read();
    for(int i=1;i<=n;i++){
        cin>>s;
        if(s.size()>10)x[++tot]=hash0(s);
    }
    sort(x+1,x+tot+1);
    for(int i=1;i<=tot;i++){
        if(x[i]!=x[i-1])ans++;
    }
    printf("%d\n",ans);
    system("pause");
}