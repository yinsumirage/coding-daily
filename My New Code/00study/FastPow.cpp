#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int mod = (int)1e9+7;
const int MAX_N = 1e3;
int A[MAX_N][MAX_N],res[MAX_N][MAX_N],B[MAX_N][MAX_N],C[MAX_N][MAX_N];
int temp[MAX_N][MAX_N];

// a的b次方 对mod取余数
ll Powermod(ll a,ll b,int mod)
{
	ll ans=1;
	a=a%mod;
	while(b>0)
	{
		if(b%2==1)ans=(ans*a)%mod;
		b=b/2;
		a=(a*a)%mod;
	}
	return ans;
}

 //一般的正常矩阵乘法
void MXMP(int m,int n,int p)//Matrix multiplication
{
    for(int i = 1;i<=m;i++)
        for(int j = 1;j<=p;j++)
            for(int k = 1;k<=m;k++)
                C[i][j] = (C[i][j] + (A[i][k]*B[k][j])%mod)%mod;//防止超界
}


//A = A*B
//新的矩阵乘法
void MXMP(int a[][MAX_N],int b[][MAX_N],int n)
{
    //重置临时矩阵temp
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
            temp[i][j] = 0;
 
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
            for(int k = 1;k<=n;k++)
                temp[i][j] = (temp[i][j] + (a[i][k]*b[k][j])%mod)%mod;//防止超界
    
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
            a[i][j] = temp[i][j];
}
 

//A = A**x
void PowerMod(int A[][MAX_N],int n,int x)//x为次幂，n为矩阵行/列
{
    memset(res,0,sizeof(res));
    for(int i = 1;i<=n;i++)  res[i][i] = 1;//初始化为单位矩阵
    while(x){
        if(x&1)  MXMP(res,A,n);
        MXMP(A,A,n);
        x >>= 1;
    }
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
            A[i][j] = res[i][j];
}
 
 
int main()
{
    //读入A矩阵
    int n,x;
    cin>>n>>x;//n行n列，x为次幂
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
            cin>>A[i][j];
    //_______________________________
    PowerMod(A,n,x);
    //检查A矩阵
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
    //________________________________
    return 0;
}
