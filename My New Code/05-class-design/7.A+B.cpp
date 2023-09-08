#include<iostream>
#include<string.h>
using namespace std;
typedef long long ll;
const int N = 3e4 + 5;

char a1[N],b1[N],a[N],b[N];
int c[N];
int diana=-1,dianb=-1;

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
    cin>>a1>>b1;
    //scanf("%s%s",a1,b1);
    int la=strlen(a1),lb=strlen(b1),anslen=0,lq=0,k=0,maxlen=0;
    int cha=0;
    int lmax=max(la,lb);
    for(int i=0;i<la;i++){
        a[i]=a1[la-i-1];
        if(a[i]=='.')diana=i;
    }
    for(int i=0;i<lb;i++){
        b[i]=b1[lb-i-1];
        if(b[i]=='.')dianb=i;
    }
    if(diana>dianb){
        if(dianb!=-1){
            cha=diana-dianb;
            lmax=max(la,lb+diana-dianb);
            for(int i=0;i<cha;i++){
                c[i]=a[i]-'0';
            }
            for(int i=cha;i<diana;i++){
                c[i]+=b[i-cha]-'0'+a[i]-'0';
                while(c[i]>=10){
                    c[i]-=10;
                    c[i+1]++;
                }
            }
            c[diana+1]=c[diana];
            for(int i=diana+1;i<lmax;i++){
                c[i]+=a[i]+b[i-cha]-'0'-'0';
                if(b[i-cha]==0||a[i]==0)c[i]+=48;
                while(c[i]>=10){
                    c[i]-=10;
                    c[i+1]++;
                }
            }
            if(c[lmax]>0)anslen=lmax;
            else for(int i=lmax;i>=diana+1;i--){
                if(c[i]!=0){
                    anslen=i;
                    break;
                }
                if(i==diana+1){
                    anslen=i;
                }
            }
            maxlen=max(anslen,lmax-1);
        }
        else {
            for(int i=0;i<diana;i++){
                c[i]=a[i]-'0';
            }
            lq=max(la,lb+diana+1);
            for(int i=diana+1;i<lq;i++){
                c[i]+=a[i]-'0'+b[i-diana-1]-'0';
                if(a[i]==0||b[i-diana-1]==0)c[i]+=48;
                while(c[i]>=10){
                    c[i]-=10;
                    c[i+1]++;
                }
            }
            if(c[lq]>0)anslen=lq;
            else for(int i=lq;i>=diana+1;i--){
                if(c[i]!=0){
                    anslen=i;
                    break;
                }
                if(i==diana+1){
                    anslen=i;
                }
            }
            maxlen=max(anslen,lq-1);
        }
        for(int i=0;i<=maxlen+3-la;i++)printf(" ");
        for(int i=0;i<la;i++)printf("%c",a1[i]);
        printf("\n");printf("+");
        for(int i=1;i<=maxlen+3-lb+dianb-diana;i++)printf(" ");
        for(int i=0;i<lb;i++)printf("%c",b1[i]);
        for(int i=0;i<diana-dianb;i++)printf(" ");
        printf("\n");
        for(int i=0;i<=maxlen+3;i++)printf("-");
        printf("\n");
        for(int i=0;i<maxlen+3-anslen;i++)printf(" ");
        for(int i=anslen;i>diana;i--)printf("%d",c[i]);
        if(diana!=-1||diana!=-1)printf(".");
        for(int i=diana-1;i>=0;i--)printf("%d",c[i]);
        printf("\n");
    }


    else {
        if(diana!=-1){
            cha=dianb-diana;
            lmax=max(lb,la+dianb-diana);
            for(int i=0;i<cha;i++){
                c[i]=b[i]-'0';
            }
            for(int i=cha;i<dianb;i++){
                c[i]+=a[i-cha]-'0'+b[i]-'0';
                while(c[i]>=10){
                    c[i]-=10;
                    c[i+1]++;
                }
            }
            c[dianb+1]=c[dianb];
            for(int i=dianb+1;i<lmax;i++){
                c[i]+=a[i-cha]-'0'+b[i]-'0';
                if(b[i]==0||a[i-cha]==0)c[i]+=48;
                while(c[i]>=10){
                    c[i]-=10;
                    c[i+1]++;
                }
            }
            if(c[lmax]>0)anslen=lmax;
            else for(int i=lmax;i>=dianb+1;i--){
                if(c[i]!=0){
                    anslen=i;
                    break;
                }
                if(i==dianb+1){
                    anslen=i;
                }
            }
            maxlen=max(anslen,lmax-1);
        }
        else {
            for(int i=0;i<dianb;i++){
                c[i]=b[i]-'0';
            }
            lq=max(lb,la+dianb+1);
            for(int i=dianb+1;i<lq;i++){
                c[i]+=b[i]-'0'+a[i-dianb-1]-'0';
                if(b[i]==0||a[i-dianb-1]==0)c[i]+=48;
                while(c[i]>=10){
                    c[i]-=10;
                    c[i+1]++;
                }
            }
            if(c[lq]>0)anslen=lq;
            else for(int i=lq;i>=dianb+1;i--){
                if(c[i]!=0){
                    anslen=i;
                    break;
                }
                if(i==dianb+1){
                    anslen=i;
                }
            }
            maxlen=max(anslen,lq-1);
        }
        for(int i=0;i<=maxlen+3-la+diana-dianb;i++)printf(" ");
        for(int i=0;i<la;i++)printf("%c",a1[i]);
        for(int i=0;i<dianb-diana;i++)printf(" ");
        printf("\n");printf("+");
        for(int i=1;i<=maxlen+3-lb;i++)printf(" ");
        for(int i=0;i<lb;i++)printf("%c",b1[i]);
        printf("\n");
        for(int i=0;i<=maxlen+3;i++)printf("-");
        printf("\n");
        for(int i=0;i<maxlen+3-anslen;i++)printf(" ");
        for(int i=anslen;i>dianb;i--)printf("%d",c[i]);
        if(diana!=-1||dianb!=-1)printf(".");
        for(int i=dianb-1;i>=0;i--)printf("%d",c[i]);
        printf("\n");
    }
    system("pause");
}