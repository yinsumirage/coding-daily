#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 5;

int n,a,b,c,ma=0,ji=0,jiji=0;

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

struct ball{
    int x,y,z,num;
}ba[N];

bool cmp(ball t,ball p){
    if(t.y!=p.y)return t.y>p.y;
    else if(t.x!=p.x)return t.x>p.x;
    else return t.z>p.z;
}

int main(){
    n=read();
    for(int i=1;i<=n;i++){
        a=read(),b=read(),c=read();
        if(a<b)swap(a,b);
        if(b<c)swap(b,c);
        if(a<b)swap(a,b);
        if(c>ma)ma=c,ji=i;
        ba[i].x=a,ba[i].y=b,ba[i].z=c;
        ba[i].num=i;
    }
    sort(ba+1,ba+n+1,cmp);
    for(int i=1;i<n;i++){
        if(ba[i].x==ba[i+1].x&&ba[i].y==ba[i+1].y){
            int tp=ba[i].z+ba[i+1].z;
            tp=min(tp,ba[i].y);
            if(tp>ma){
                ma=tp;ji=ba[i].num,jiji=ba[i+1].num;
            }
        }
    }
    if(jiji)printf("2\n%d %d\n",ji,jiji);
    else printf("1\n%d\n",ji);
    system("pause");
}