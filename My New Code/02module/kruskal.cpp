#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
#define fup(i,j,k) for(i=j;i<=k;++i)
#define fdo(i,j,k) for(i=j;i>=k;--i)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int i;
int f[N],n,m;
// n是节点数 m是道路数
struct edge{
    int x,y,z;
}e[N*4];

//！！！！！！要用两个结构存边
//一个记录一开始的边
//一个记录建立最小生成数里面的边

void add(int u,int v,int w){}

bool cmp(edge a,edge b){
    return a.z<b.z;
} //小于就是从小到大排序———最小生成树

int find(int x){ //并查集寻找父节点-代表元
    if(f[x]!=x)f[x]=find(f[x]);//用递归的方式将所有的点上级都设为根节点
    return f[x]; 
}

void kruskal(){
    sort(e+1,e+m+1,cmp);
    fup(i,1,n){
        f[i]=i;  //初始化并查集
    }
    fup(i,1,m){ //将并查集内的他们连起来，有相同上级时就会成环，不连
        if(find(e[i].x)!=find(e[i].y)){
            f[find(e[i].x)]=find(e[i].y);
            add(e[i].x,e[i].y,e[i].z);
            add(e[i].y,e[i].x,e[i].z);
        }
    }
}
