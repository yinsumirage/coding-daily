#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

ll n,m,l;
ll ans=0x3f3f3f3f;
string s,y;


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

vector<int> pre(string s){
    int l=s.size();
    vector<int>pi(l);
    for(int i=1;i<l;i++){
        int j=pi[i-1];
        while(j>0&&s[i]!=s[j])j=pi[j-1];
        if(s[i]==s[j])j++;
        pi[i]=j;
    }
    return pi;
}

void findsame(string yuan,string mode){
    string cur=mode+'#'+yuan;
    int siz1=yuan.size();
    int siz2=mode.size();
    vector<int>v;
    vector<int>pi=pre(cur);
    for(int i=siz2+1;i<=siz1+siz2;i++){
        if(pi[i]==siz2)v.push_back(i-2*siz2);
    }
    for(int i=0;i<v.size();i++){
        printf("%d\n",v[i]+1); //打印mode在yuan中出现位置
    }
    for(int i=0;i<siz2;i++){
        printf("%d ",pi[i]); //打印pi数组长度
    }
}

signed main() {
    fastio;
    cin>>s;
    cin>>y;
    findsame(s,y);
    //system("pause");
}