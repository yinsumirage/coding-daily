#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int hap[6005];
vector<int> worker[6005];
int upper[6005];
int f[6005][2];

void dfs(int x){
    for(int j=0;j<worker[x].size();j++){
        int i=worker[x][j];  // x的下属放在vector内
        dfs(i);
        f[x][0]+=max(f[i][0],f[i][1]); //上司不去时，取下属两种情况的最大值
        f[x][1]+=f[i][0];              //上司去时，去下属不去的值
    }
    f[x][1]+=hap[x];
}

signed main() {
    fastio;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>hap[i];
    }
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        worker[y].push_back(x);
        upper[x]=y;
    }
    for(int i=1;i<=n;i++){
        if(upper[i]==0){
            dfs(i);
            printf("%d\n",max(f[i][1],f[i][0]));
            break;
        }
    }
    system("pause");
    return 0;
}