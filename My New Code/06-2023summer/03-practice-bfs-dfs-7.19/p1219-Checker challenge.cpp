#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int h[100],l[100],c[100],d[100];
// h 行 l 列 c 左下 d 左下
int n,total=0;

void queen(int x){ //第x个皇后进行搜索
    if(x>n){ //搜完了 打出来并回溯
        if(total<=2){
            for(int k=1;k<=n;k++){
                printf("%d ",h[k]);
            }
            printf("\n");
        }
        total++;
        return;
    }
    for(int i=1;i<=n;i++){ //枚举每一列
        if(l[i]==0&&c[i+x]==0&&d[x-i+n]==0){ //没有皇后占据
            h[x]=i; //宣布第x行是第i个
            l[i]=1;
            c[i+x]=1;
            d[x-i+n]=1;
            queen(x+1);
            l[i]=0;
            c[i+x]=0;
            d[x-i+n]=0;
        }
    }
}

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

int main() {
    fastio;
    n=read();
    queen(1);
    printf("%d",total);
    //system("pause");
    return 0;
}
