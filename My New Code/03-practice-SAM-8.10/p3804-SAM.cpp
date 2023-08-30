#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 1e6 + 5;

int siz[N<<1];

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
    int ch[26];
    int len,fa;
    NODE(){memset(ch,0,sizeof(ch));len=0;}
}dian[N<<1];

int las=1,tot=1;

void add(int c){
    int p=las;
    int np=las=++tot;
    dian[np].len=dian[p].len+1;
    for(;p&&!dian[p].ch[c];p=dian[p].fa)dian[p].ch[c]=np;
    //向上层层连
    //发现都没出现过这个
    if(!p)dian[np].fa=1;//以上为case 1
    else{
        //停在某一个祖先上
        int q=dian[p].ch[c];
        //记下q 长度符合SAM定义 len==len+1
        if(dian[q].len==dian[p].len+1)dian[np].fa=q;//以上为case 2
        else{
            //不符合则插出一个新节点nq来，从q中弄出来的
            int nq=++tot;dian[nq]=dian[q];
            dian[nq].len=dian[p].len+1;
            dian[q].fa=dian[np].fa=nq; 
            for(;p&&dian[p].ch[c]==q;p=dian[p].fa)dian[p].ch[c]=nq;//以上为case 3
        }
    }
    siz[np]=1;
}
char s[N];int len;

int t[N<<1],A[N<<1];
ll ans=0;

int main(){
    // 扫和建树
    scanf("%s",s);
    len=strlen(s);
    for(int i=0;i<len;i++){
        add(s[i]-'a');
    }

    for(int i=1;i<=tot;i++)t[dian[i].len]++; //桶装下了每个长度出现次数
    for(int i=1;i<=tot;i++)t[i]+=t[i-1];  //长的肯定包含了所有短的，是父节点
    for(int i=1;i<=tot;i++)A[t[dian[i].len]--]=i; //反过来标记节点，从最下的开标
    for(int i=tot;i>=1;i--){
        int no=A[i]; // 从下向上遍历，从最长的开始遍历
        siz[dian[no].fa]+=siz[no];//更新出现次数
        if(siz[no]>1)ans=max(ans,1ll*siz[no]*dian[no].len);
    }
    printf("%lld\n",ans);
    //system("pause");
}

