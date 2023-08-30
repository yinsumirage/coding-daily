#include<iostream>
#include<string.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e3 + 5;

int n,l,ji,jiji,endd;
char s[N],need;
char tru[11]={"fattyhappy"};

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

void find(char need,int pos,int ji){
    for(int i=0;i<l;i++){
        if(i==pos){
            i+=9;
        }
        else {
            if(s[i]==need){
                printf("%d %d\n",i+1,ji+1);
                endd=1;
                break;
            }
        }
    }
}

int main(){
    n=read();
    while(n--){
        scanf("%s",s);
        l=strlen(s);
        for(int i=0,differ=0;i+9<l;i++){
            endd=0;
            differ=0;
            for(int j=0;j<10;j++){
                if(tru[j]!=s[i+j]){
                    if(!differ){
                        ji=i+j;
                    }
                    else if(differ==1){
                        jiji=i+j;
                    }
                    if(differ>2)break;
                    differ++;
                }
            }
            switch (differ){
            case 0:{
                printf("%d %d\n",i+4,i+3);
                endd=1;
            }
            break;
            case 1:{
                find(tru[ji-i],i,ji);
            }
            break;
            case 2:{
                if(tru[ji-i]==s[jiji]&&tru[jiji-i]==s[ji]){
                    endd=1;
                    printf("%d %d\n",ji+1,jiji+1);
                }
                break;
            }
            }
            if(endd==1)break;
        }
        if(endd==0)printf("-1\n");
    }
    system("pause");
}