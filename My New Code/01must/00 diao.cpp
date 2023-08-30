#include<bits/stdc++.h>
#define db double
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define LL long long
#define ldb long double
#define pdd pair<db,db>
#define pll pair<LL,LL>
#define pil pair<int,LL>
#define pli pair<LL,int>
#define pii pair<int,int>
#define pip pair<int,pii>
#define ppi pair<pii,int>
#define ppp pair<pii,pii>
#define pss pair<pair<char,char>,pair<char,char>>
#define fr first
#define sc second
#define mp make_pair
#define id(x,y) ((x-1)*m+y)
using namespace std;
const int mxn=1e6+10,mxm=5010,N=1e6,infi=1e9,mod=1e9+7,inv2=(mod+1)/2,inv3=(mod+1)/3;
const int v1=37,v2=53,M1=323323323,M2=998244353;
const int dx[]={0,1,0,-1},
    dy[]={1,0,-1,0};
const db PI=acos(-1),eps=1e-10;
const LL infl=1e18;
int DB_cmp(db x,db y) {if(fabs(x-y)<eps) return 0; if(x<y) return -1; return 1;}
template<class T> inline void chkmax(T &x,const T y) {if(y>x) x=y;}
template<class T> inline void chkmin(T &x,const T y) {if(y<x) x=y;}
template<class T> inline void upd(T &x,const T y) {if((x+=y)>=mod) x-=mod;}
template<class T> inline int Add(const T x,const T y) {if(x+y>=mod) return x+y-mod; return x+y;}
template<class T> inline T my_gcd(T a,T b) {if(!a||!b) return a|b; for(T c=a%b;c;a=b,b=c,c=a%b); return b;}
inline int _pow(int k,int i){
    int t=1;
    for(;i;i>>=1,k=1ll*k*k%mod)
        if(i&1)
            t=1ll*t*k%mod;
    return t;
}
inline int _pow(int k,int i,int M){
    int t=1;
    for(;i;i>>=1,k=1ll*k*k%M)
        if(i&1)
            t=1ll*t*k%M;
    return t;
}
LL rd(){
    static LL sl,fh,ch;
    sl=0;fh=1;ch=getchar();
    while(ch<'0'||'9'<ch) {if(ch=='-') fh=-1; ch=getchar();}
    while('0'<=ch&&ch<='9') sl=sl*10+ch-'0',ch=getchar();
    return sl*fh;
}
int n,m,a[mxn],b[mxn];
LL res,ans;
int main(){
//  freopen("data.in","r",stdin);
//  for(int TT=rd();TT;--TT)
    {
        n=rd();
        for(int i=1;i<=n;++i) a[i]=rd();
        sort(a+1,a+n+1);
        m=rd();
        for(int i=1;i<=m;++i) b[i]=rd();
        sort(b+1,b+m+1);
        for(int j=1,i=1;i<=m;++i)
        {
            for(;j<=n&&a[j]<=b[i];++j) res+=a[j];
            ans+=res+1ll*b[i]*(n-j+1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}