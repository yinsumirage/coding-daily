#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int n,s1=0;
priority_queue<int,vector<int>,greater<int> >q1;
//priority_queue<int,vector<int>,less<int> >q2;

ll read(){
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
    for(int i=1,x;i<=n;i++){
        x=read();
        q1.push(x);
        //q2.push(x);
    }
    for(int i=1,x,y;i<n;i++){
        x=q1.top();
        q1.pop();
        y=q1.top();
        q1.pop();
        s1+=x+y;
        q1.push(x+y);
        // x=q2.top();
        // q2.pop();
        // y=q2.top();
        // q2.pop();
        // s2+=x+y;
        // q2.push(x+y);
    }
    printf("%d",s1);
    //system("pause");
}