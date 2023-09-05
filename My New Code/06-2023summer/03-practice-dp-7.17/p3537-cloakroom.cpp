#include <bits/stdc++.h>
using namespace std;

struct node{
    int a,b,c,line;
    bool operator<(const node& x)const{
        return a<x.a;
    }
}obj[1005],que[1000005];

int bm[100005]; //在sum c为k时，b最小值最大化
int ans[1000005]={0};


int main() {
    ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    int n,p;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>obj[i].c>>obj[i].a>>obj[i].b;
    }
    cin>>p;
    for(int i=1;i<=p;i++){
        cin>>que[i].a>>que[i].b>>que[i].c;
        que[i].line=i;
    }
    sort(obj+1,obj+n+1);
    sort(que+1,que+p+1);
    bm[0]=1e9;
    for(int i=1,j=1;i<=p;i++){
        for(;j<=n&&obj[j].a<=que[i].a;j++){
            for(int k=100000;k>=obj[j].c;k--){
                bm[k]=max(bm[k],min(bm[k-obj[j].c],obj[j].b));
            }
            if(bm[que[i].b]>que[i].a+que[i].c) ans[que[i].line]=1;
        }
    }
    for(int i=1;i<=p;i++){
        puts(ans[i]?"TAK":"NIE");
    }
    return 0;
}