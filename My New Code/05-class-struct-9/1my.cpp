#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef struct LNode{
    int data;
    struct LNode *next;
}LNode, *LinkList;

void crea(LinkList &l,int n){
    LinkList p;
    LinkList q;
    l=(LinkList)malloc(sizeof(LNode));
    l->next=NULL;
    p=(LinkList)malloc(sizeof(LNode));
    p->data=n;
    q=p;
    p->next=l->next;
    l->next=p;
    if(n==1){
        p->next=p;
        return;
    }
    for(int i=n-1;i>0;i--){
        p=(LinkList)malloc(sizeof(LNode));
        p->data=i;
        p->next=l->next;
        l->next=p;
    }
    q->next=p;
}

void dele(LinkList &l,int &e){
    LinkList q;
    q=l->next;
    l->next=q->next;
    e=q->data;
    free(q);
}


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

int n,st,cha;

int main(){
    n=read();
    if(n<1){
        printf("n,m,k must bigger than 0.\n");
        return 0;
    }
    LinkList l;
    crea(l,n);
    if(n==1)l=l->next;
    st=read()-1;
    if(st>n){
        printf("k should not bigger than n.\n");
        return 0;
    }
    if(st<0){
        printf("n,m,k must bigger than 0.\n");
        return 0;
    }
    while(st--)l=l->next;
    cha=read();
    if(cha<1){
        printf("n,m,k must bigger than 0.\n");
        return 0;
    };
    for(int i=1,count=0;i<n;i++){
        int e;
        for(int i=1;i<cha;i++)l=l->next;
        dele(l,e);
        count++;
        if(count%10==0)printf("%d\n",e);
        else printf("%d ",e);
    }
    printf("%d\n",l->data);
    system("pause");
}