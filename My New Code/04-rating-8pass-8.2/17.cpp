#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N= 1e6+5;
const int INF=0x3f3f3f3f;

int n,m,t,gc[N],a,d;

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

int main(){
	t=read();
	while(t--){
		int ans=0;
		memset(gc,0,sizeof(gc));
		a=read();d=read();n=read();
		for(int i=1;i<=n;i++){
			gc[__gcd(a,i)]++;
		}
		for(int i=1;i<=n;i++){
			int lc=i*d/__gcd(i,d);
			ans+=gc[lc];
		}
		printf("%d\n",ans);
	}
	return 0;
}

