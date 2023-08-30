#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

int pre[N],rak[N];

void init(int n){
    for(int i=1;i<=n;i++){
        pre[i]=i;rak[i]=1;
    }
}

int find(int x){
    if(pre[x]==x)return x;
    return pre[x]=find(pre[x]);
}

bool isSame(int x,int y){
    return find(x)==find(y);
}

bool join(int x,int y){
    x=find(x);y=find(y);
    if(x==y)return false;
    if(rak[x]>rak[y])pre[y]=x;
    else{
        if(rak[x]==rak[y])rak[y]++;
        pre[x]=y;
    }
    return true;
}