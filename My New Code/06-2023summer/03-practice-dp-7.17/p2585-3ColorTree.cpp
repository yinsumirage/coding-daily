#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

//二叉树建树，用邻接矩阵 建树很厉害，好好学
//tree[i][0]左节点 tree[i][1]右节点

int node=0; //访问过的节点数
int tree[N][2]; //树
string s; //接收字符串

int f[N][2]; // 0是不染色，1是染色

void dfs(int root){
    node++;
    if(s[root]=='0')return;
    if(s[root]=='1'){
        tree[root][0]=root+1;
        dfs(root+1);
    }
    if(s[root]=='2'){
        tree[root][0]=root+1;
        dfs(root+1);
        tree[root][1]=node+1;
        dfs(node+1);
    }
}

signed main() {
    fastio;
    cin>>s;
    s='0'+s;
    dfs(1);
    for(int i=node;i>=1;i--){ //只需要看左右两个枝条是否染色，向上推最大值
        f[i][1]=f[tree[i][0]][0]+f[tree[i][1]][0]+1;
        f[i][0]=max(f[tree[i][0]][1]+f[tree[i][1]][0],f[tree[i][1]][1]+f[tree[i][0]][0]);
    }
    printf("%d ",max(f[1][0],f[1][1]));
    for (int i=node;i>=1;i--){
        f[i][1]=f[tree[i][0]][0]+f[tree[i][1]][0]+1;
        f[i][0]=min(f[tree[i][0]][1]+f[tree[i][1]][0],f[tree[i][0]][0]+f[tree[i][1]][1]);
    }
    printf("%d",min(f[1][1],f[1][0]));
    system("pause");
    return 0;
}