#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int n,blc;
int a[N],bl[N],tag[N];
 
inline void Init(int pos)
{
    if(tag[pos]==-1) return;
    for(int i=(pos-1)*blc+1;i<=pos*blc;i++)
        a[i]=tag[pos];
    tag[pos]=-1;
    return;
}
 
inline int getans(int l,int r,int x)
{
    Init(bl[l]);
    int res=0;
    for(int i=l;i<=min(r,bl[l]*blc);i++)
        res+=(a[i]==x),a[i]=x;
    for(int i=bl[l]+1;i<bl[r];i++)
        if(tag[i]!=-1) 
        {
            if(tag[i]==x) res+=blc;
            tag[i]=x;
        }
        else
        {
            for(int j=(i-1)*blc+1;j<=i*blc;j++)
                res+=(a[j]==x),a[j]=x;
            tag[i]=x;
        }
    if(bl[l]!=bl[r])
    {
        Init(bl[r]);
        for(int i=(bl[r]-1)*blc+1;i<=r;i++)
            res+=(a[i]==x),a[i]=x;
    }
    return res;
}
 
int main()
{
    scanf("%d",&n);
    blc=ceil(sqrt(n));
    memset(tag,-1,sizeof tag);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        bl[i]=(i-1)/blc+1;
    for(int i=1;i<=n;i++)
    {
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        printf("%d\n",getans(l,r,x));
    }
    return 0;
}