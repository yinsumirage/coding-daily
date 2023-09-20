#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
const int N = 2e5 + 5;
const int mod = 92084931;

int n,m,now=0,ans=0,shu=1;
int q[N],hao[N],c[N];
int tree[N];

int lowbit(int k){return k&-k;}

void add(int x){
    while(x<=n){
        tree[x]+=1;
        x+=lowbit(x);
    }
}

int sum(int x){
    int ans=0;
    while(x!=0){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}

bool cmp(int i,int j){
    return q[i]<q[j];
}

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
    n=read();m=read();
    for(int i=2;i<=n+1;i++){
        now=read()-m;
        q[i]=q[i-1]+now;
        hao[i]=i;
    }
    if(n==1){
        if(now>0){
            printf("1");return 0;
        }
        else {
            printf("0");return 0;
        }
    }
    hao[1]=1;q[1]=0;
    sort(hao+1,hao+n+2,cmp);
    c[hao[1]]=n-shu;
    for(int i=2;i<=n+1;i++){
        if(q[hao[i]]>q[hao[i-1]])shu++;
        c[hao[i]]=n-shu;
    }
    for(int i=1;i<=n+1;i++){
        add(c[i]);
        ans+=i-sum(c[i]);
        ans%=mod;
        // 核心思路 遍历到一个原序号就给他加1
        // 比如现在遍历到原序为3=p[i]的数
        // add 3 表示小于3 小于4的又出现一个
        // sum[3]就是比3小的数字个数
        // 小于3个说明后面还有比3小的数字在后面 
        // i-sum[p[i]]就是有几个在后面的 就是逆序
    }
    printf("%d\n",ans);
    //system("pause");
}

// #include<bits/stdc++.h>
// #define ll long long
// using namespace std;
// long long read(){
//     long long x=0,f=1;char ch=getchar();
//     while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
//     while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
//     return x*f;
// }
// void write(long long x){
//     if(x<0) putchar('-'),x=-x;
//     if(x>9) write(x/10);
//     putchar(x%10+'0');
// }
// const int N=2e5+10;
// const ll mod=92084931;
// int n;
// ll m,a[N],s[500],len,v[N],sum;
// int discrete(int n,ll *a){
//     int b[N];
//     for(int i=1;i<=n;i++)
//         b[i]=a[i];
//     sort(b+1,b+n+1);
//     int tot=unique(b+1,b+n+1)-(b+1);
//     for(int i=1;i<=n;i++)
//         a[i]=lower_bound(b+1,b+tot+1,a[i])-b;
//     return tot;
// }
// ll ask(int w){
// 	int k=w/len;
// 	ll ans=0;
// 	for(int i=0;i<k;i++)
// 		ans=(ans+s[i])%mod;
// 	for(int i=k*len;i<w;i++)
// 		ans=(ans+v[i])%mod;
// 	return ans;
// }
// void add(int w){
// 	v[w]++;
// 	s[w/len]++;
// }
// int main(){
// 	n=read()+1;m=read();//把下标从2开始统计，这样方面在前面插入0 
// 	for(int i=2;i<=n;i++)
// 		a[i]=read()-m+a[i-1];//把a数组直接当前缀和用 
// 	int tot=discrete(n,a);//离散化 
// 	len=sqrt(tot);
// 	add(a[1]);//插入0 
// 	for(int i=2;i<=n;i++){
// 		sum=(sum+ask(a[i]))%mod;
// 		add(a[i]);
// 	}
// 	write(sum);
//     return 0;
// }