#include<iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5 + 5;

int n;
int xian,hou,sk[N],top;
char s[N];

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
    cin>>s;
    while(1){
        xian=hou=0;
        top=1;
        sk[1]=s[0]-'A';
        for(int i=1;i<n;i++){
            if(s[i]-'A'==sk[top]){
                xian++;
            }
            else top--;
        }
    }
    system("pause");
}