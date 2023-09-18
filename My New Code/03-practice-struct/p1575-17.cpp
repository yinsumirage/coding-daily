#include <bits/stdc++.h>
#include<ext/rope>
using namespace __gnu_cxx;
using namespace std;
//#define fastio ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=0x3f3f3f3f;
const int N = 1e6 + 5;

char c[300];
int sk[200],top=0;
int no=0,flag=0;

signed main() {
    cin.getline(c,255);
    int l=strlen(c);
    if(c[0]=='a'||c[0]=='o'||c[l-1]=='d'||c[l-1]=='r'||c[l-1]=='t'){
        printf("error\n");return 0;
    }
    for(int i=0;i<l;i++){
        if(c[i]=='t'){
            while(sk[top]==4){
                no++;
                top--;
            }
            if(no%2)sk[++top]=-1;
            else sk[++top]=1;
            no=0;
            if(sk[top-1]==2){
                top-=2;
                if(sk[top]==1&&sk[top+2]==1){
                    sk[top]=1;
                }
                else sk[top]=-1;
            }
            i+=4;continue;
        }
        else if(c[i]=='f'){
            while(sk[top]==4){
                no++;
                top--;
            }
            if(no%2)sk[++top]=1;
            else sk[++top]=-1;
            no=0;
            if(sk[top-1]==2){
                top-=2;
                if(sk[top]==1&&sk[top+2]==1){
                    sk[top]=1;
                }
                else sk[top]=-1;
            }
            i+=5;continue;
        }
        else if(c[i]=='o'){
            if(sk[top]==4||sk[top]==3||sk[top]==2){
                printf("error\n");
                return 0;
            }
            sk[++top]=3;
            i+=2;continue;
        }
        else if(c[i]=='a'){
            if(sk[top]==4||sk[top]==3||sk[top]==2){
                printf("error\n");
                return 0;
            }
            sk[++top]=2;
            i+=3;continue;
        }
        else if(c[i]=='n'){
            sk[++top]=4;
            i+=3;continue;
        }
    }
    if(top%2==0){
        printf("error\n");
        return 0;
    }
    for(int i=1;i<=top;i++){
        if(sk[i]==1)flag=1;
        if((i+1<top)&&(i+1)%2&&sk[i]!=3){
            printf("error\n");
            return 0;
        }
    }
    if(flag==1){
        printf("true\n");
        return 0;
    }
    printf("false\n");
    system("pause");
}