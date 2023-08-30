#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int n,ans;
char s[N];
char ss[N];
int d1[N];

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

void Manacher(int len){
    memset(d1,0,sizeof(d1));
    for(int i=0,l=0,r=-1;i<len;i++){
        int k=(i>r)?1:min(d1[l+r-i],r-i+1);
        while(i-k>=0&&i+k<len&&ss[i-k]==ss[i+k])k++;
        d1[i]=k--;
        if(i+k>r){
            l=i-k;r=i+k;
        }
    }
    int Ma=1;
    for(int i=0;i<=len/2;i++){
        if(d1[i]==i+1)
        Ma=max(Ma,d1[i]-1);
    }
    for(int i=len-1;i>len/2;i--){
        if(d1[i]==len-i)
        Ma=max(Ma,d1[i]-1);
    }
    ans+=Ma;
    printf("%lld\n",ans);
}

signed main() {
    //fastio;
    n=read();
    while(n--){
        ans=0;
        scanf("%s",s+1);
        int len=strlen(s+1);
        int i,p;
        if(len==1){
            printf("1\n");
            continue;
        }
        for(i=1,p=1;i<=len/2;i++){
            if(s[i]!=s[len-i+1]){
                p=0;
                break;
            }
        }
        ans+=i*2-2;
        if(p==1){
            if(len%2==1)ans++;
            printf("%lld\n",ans);
            continue;
        }
        else {
            int tot=0;
            for(int j=i;j<=len-i+1;j++){
                ss[tot*2]='#';  
                ss[tot*2+1]=s[j];     
                tot++;         
            }
            ss[2*tot]='#';
            Manacher(tot*2+1);
        }
    }
    system("pause");
}