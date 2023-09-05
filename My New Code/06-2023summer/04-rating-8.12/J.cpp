#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e5 + 5;

int siz[N*2];
map <int,int> m[N*2];

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

struct NODE{
    int len=0,fa=0;
}dian[N<<1];

int las=1,tot=1;
ll ans=0;


void add(int c){
    
    int p=las;
    int np=las=++tot;
    dian[np].len=dian[p].len+1;
    for(;p&&m[p].find(c)==m[p].end();p=dian[p].fa){
        m[p].insert(make_pair(c,np));
        siz[np]+=siz[p];
    }
    //向上层层连
    //发现都没出现过这个
    if(!p){
        dian[np].fa=1;//以上为case 1
        ans+=siz[np];
    }
    else{
        //停在某一个祖先上
        int q= m[p].find(c)->second;
        //记下q 长度符合SAM定义 len==len+1
        if(dian[q].len==dian[p].len+1){
            dian[np].fa=q;//以上为case 2
            siz[np]++;
            ans+=siz[np];
        }
        else{
            //不符合则插出一个新节点nq来，从q中弄出来的
            int nq=++tot;dian[nq]=dian[q];
            dian[nq].len=dian[p].len+1;
            dian[q].fa=dian[np].fa=nq; 
            for(;p&&m[p].find(c)->second==q;p=dian[p].fa){
                m[p].insert(make_pair(c,np));//以上为case 3
                siz[np]++;
            }
            ans+=siz[np]+siz[nq];
        }
    }
    printf("%lld\n",ans);
}
char s[N];int len;

int t[N*2],A[N*2];
int n;
int a;
int main(){
    n=read();
    siz[1]=1;
    for(int i=0;i<n;i++){
        a=read();
        add(a);
    }
    system("pause");
}
