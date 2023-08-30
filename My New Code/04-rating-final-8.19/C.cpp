#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e5 + 5;

int n,m;
int ans=0x3f3f3f3f;
char s[N];
int a[27][27];
int ji[27];
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
signed main() {
    //fastio;
    scanf("%s",s);
    int l=strlen(s);
    int shu;
    for(int i=0;i<l;i++){
        shu=s[i]-'a';
        ji[shu]++;
        for(int j=0;j<=26;j++){
            a[j][shu]+=ji[j];
        }
        a[shu][shu]--;
    }
    int ma=0;
    for(int i=0;i<=26;i++){
        for(int j=0;j<=26;j++){
            ma=max(ma,a[i][j]);
        }
    }
    printf("%d",ma);
    system("pause");
}