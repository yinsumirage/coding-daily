#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e6 + 5;

int n;
int a[N];
int qian[N];
int q[N],hh=1,tt=0,ans=0;
// 要维护出一段区间中的最小值 还是单调队列好

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

int main(){
    n=read();
    for(int i=1;i<=n;i++){
        // 开双倍数组 断链为环
        a[i]=read();
        a[i+n]=a[i];
    }
    for(int i=1;i<2*n;i++){
        qian[i]=qian[i-1]+a[i];
    }
    for(int i=1;i<2*n;i++){
        while(hh<=tt&&max(i-n+1,1)>q[hh])hh++;
        while(hh<=tt&&qian[i]<=qian[q[tt]])tt--;
        q[++tt]=i;
        if(i-n+1>0&&qian[q[hh]]>=qian[i-n])ans++;
    }
    printf("%d\n",ans);
    system("pause");
}


// #include<bits/stdc++.h>
// using namespace std;
// int a,som;
// int s[1000001],m[1000001][21];
// inline int r() {//快读 
// 	int s=0,w=1;
// 	char ch=getchar();
// 	while(ch<'0'||ch>'9') {
// 		if(ch=='-')w=-1;
// 		ch=getchar();
// 	}
// 	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
// 	return s*w;
// }
// inline int query(int n,int l){//求区间最小值 
// 	int p=log2(l-n+1);
// 	return min(m[n][p],m[l-(1<<p)+1][p]);
// }
// int main() {
// 	a=r();
// 	memset(m,0x7f,sizeof(m));//初始化为inf 
// 	for(int i=1; i<=a; i++) {
// 		s[i]=r();
// 		s[i]+=s[i-1];//前缀和维护 
// 		m[i][0]=s[i];
// 	}
// 	for(int i=1; (1<<i)<=a; i++)
// 		for(int j=1; j+(1<<i)-1<=a; j++)
// 			m[j][i]=min(m[j][i-1],m[j+(1<<(i-1))][i-1]);//ST表维护 
// 	if(query(1,a)>=0)//特判k是否合法 
// 	som++;
// 	for(int i=2; i<=a; i++) {
// 		if(query(i,a)-s[i-1]>=0)//判断k是否合法 
// 			if(query(1,i-1)+s[a]-s[i-1]>=0)//判断k是否合法 
// 				som++;
// 	}
// 	cout<<som;
// 	return 0;
// }