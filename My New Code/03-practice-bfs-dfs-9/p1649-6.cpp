#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 1e2 + 5;

int n,st,sd;
int sh,sl,eh,el;
char a[N][N];

struct node{
    int h,l,f;
};

int dh[4]={0,0,1,-1};
int dl[4]={1,-1,0,0};
int turn[N][N];
queue<node>q;

int main() {
    cin>>n;
    getchar();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            turn[i][j]=INF;
            if(a[i][j]=='A')sh=i,sl=j;
            else if(a[i][j]=='B')eh=i,el=j;
        }
        getchar();
    }
    turn[sh][sl]=-1;
    q.push(node{sh,sl,-1});
    while(!q.empty()){
        node u=q.front();q.pop();
        if(u.f==-1)st=0,sd=3;
        else if(u.f>=2)st=0,sd=1;
        else st=2,sd=3;
        for(int i=st;i<=sd;i++){
            int hh=u.h,ll=u.l;
            while(1){
                hh+=dh[i];ll+=dl[i];
                if(hh<1||hh>n||ll<1||ll>n||a[hh][ll]=='x')break;
                if(turn[hh][ll]>turn[u.h][u.l]+1){
                    turn[hh][ll]=turn[u.h][u.l]+1;
                    if(hh==eh&&ll==el){
                        printf("%d\n",turn[hh][ll]);
                        system("pause");
                        return 0;
                    }
                    q.push(node{hh,ll,i});
                }
            }
        }
    }
    printf("-1\n");
    system("pause");
}