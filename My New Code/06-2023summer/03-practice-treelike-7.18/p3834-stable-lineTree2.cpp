#include <bits/stdc++.h>
#define MAX 200010

using namespace std;

int nodeNum;
//所有节点的数量                                           
int L[MAX<<5],R[MAX<<5],sum[MAX<<5];                     
//L[i]表示编号为i的节点的左儿子的编号
//sum[i]表示编号为i的节点所代表的区间内数字出现的次数 
int a[MAX],Hash[MAX];
//a[i]为原数组 Hash[i]为排序后数组  
int T[MAX];            
//T[i]为插入i个点后的树的根节点编号   

int read()                                               
{                                                         
    int ans=0,flag=1;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') flag=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') {ans=(ans<<3)+(ans<<1)+ch-'0';ch=getchar();}
    return ans*flag;
}

int build(int l,int r) //建一个空树(所有sum[i]都为0) 
{
    int num=++nodeNum; //num为当前节点编号 
    if(l!=r)
    {
        int m=(l+r)>>1;
        L[num]=build(l,m);
        R[num]=build(m+1,r);
    }
    return num; //返回当前节点的编号 
}

int update(int pre,int l,int r,int x) //pre为旧树该位置节点的编号
{
    int num=++nodeNum; //新建节点的编号 
    L[num]=L[pre];R[num]=R[pre];sum[num]=sum[pre]+1;
    //该节点左右儿子初始化为旧树该位置节点的左右儿子
    //因为插入的a[i](或Hash[x])在该节点所代表的区间中 所以sum++ 
    if(l!=r)
    {
        int m=(l+r)>>1;
        if(x<=m) L[num]=update(L[pre],l,m,x);
        //x出现在左子树 因此右子树保持与旧树相同 修改左子树 
        else R[num]=update(R[pre],m+1,r,x);
    }
    return num;
}

int query(int u,int v,int l,int r,int k) //第k小 
{
    if(l==r) return Hash[l]; //找到第k小 l是节点编号 所以答案是Hash[l] 
    int m=(l+r)>>1;
    int num=sum[L[v]]-sum[L[u]];
    //用第一次模拟 这样比较容易看得懂 此时u=l-1 v=r 
    //则num= (1~r)树的左节点数字出现的次数 - (1~(l-1))树的左节点数字出现的次数 
    //即num等于([l,r])树左儿子数字出现的次数 
    if(num>=k) return query(L[u],L[v],l,m,k);
    //当 左儿子数字出现的次数大于等于k 时 意味着 第k小的数字在左子树处 
    else return query(R[u],R[v],m+1,r,k-num);
    //否则去右子树处找第k-num小的数字 
}

int main()
{
    int n=read(),m=read();
    for(int i=1;i<=n;i++) {a[i]=read();Hash[i]=a[i];}
    sort(Hash+1,Hash+1+n); 
    int size=unique(Hash+1,Hash+1+n)-Hash-1; 
    //size为线段树维护的数组的大小==Hash数组中不重复的数字的个数
    T[0]=build(1,size); //初始化 建立一颗空树 并把该树的根节点的编号赋值给T[0]
    for(int i=1;i<=n;i++)
    {
        int x=lower_bound(Hash+1,Hash+1+size,a[i])-Hash;
        //在Hash的 [1,size+1)--->[1,size] 中二分查找第一个
        // 大于等于(在这里可以看成等于) a[i]的Hash[x]
        T[i]=update(T[i-1],1,size,x);
        //更新a[i]带来的影响 
        //并将新树的根节点的编号赋值给T[i] 
    }
    while(m--)
    {
        int l=read(),r=read(),k=read();
        printf("%d\n",query(T[l-1],T[r],1,size,k)); //因为a[l]有影响 所以是T[l-1] 
    }
    return 0;
}