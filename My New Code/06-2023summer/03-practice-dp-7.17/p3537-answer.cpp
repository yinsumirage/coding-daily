#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c,ok;
	bool operator<(const node& x){
		return a<x.a;
	}
}a[1005],b[1000005];
int bm[100010];
bool ans[1000005];
int n,m;
int main(){
	ios::sync_with_stdio(false);cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].c>>a[i].a>>a[i].b;
	}
	cin>>m;
	for(int i=1;i<=m;++i){
		cin>>b[i].a>>b[i].b>>b[i].c;
		b[i].ok=i;
	}
	sort(a+1,a+n+1);  //用离线的方法处理了a这一维度的dp
	sort(b+1,b+m+1);
	int j=1;bm[0]=1e9;
	for(int i=1;i<=m;++i){  //将c作为dp的下标
		while(j<=n&&a[j].a<=b[i].a){
			for(int k=100000;k>=a[j].c;--k)bm[k]=max(bm[k],min(bm[k-a[j].c],a[j].b));
			j++;//将j定义一次，需要时再进入循环j++，这样省时间
		}
		if(bm[b[i].b]>b[i].a+b[i].c) ans[b[i].ok]=1;// b则直接作为函数的数值
	}
	for(int i=1;i<=m;i++) puts(ans[i]?"TAK":"NIE");
	return 0;
}