#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k,m,siz;

typedef struct node{
    int data;
    struct node *next;
}NODE;

void create(int n,NODE * head){
    NODE *p;
    p=(NODE*)malloc(sizeof(NODE));
    p=head;
    for(int i=1;i<=n;i++){
        NODE *k;
        k=(NODE*)malloc(sizeof(NODE));
        k->data=i;
        p->next=k;
        p=k;
    }
    p->next=head->next;
}

inline ll read(){
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
    n=read(),k=read(),m=read();
    siz=n;
    if(!n||!k||!m){
        printf("n,m,k must bigger than 0.\n");
        return 0;
    }
    if(k>n){
        printf("k should not bigger than n.\n");
        return 0;
    }
    NODE *head;
    head=(NODE*)malloc(sizeof(NODE));
    create(n,head);
    for(int i=1;i<=k;i++){
        head=head->next;
    }
    NODE *p;
    p=(NODE*)malloc(sizeof(NODE));
    p=head;
    while(1){
        int x,y;
        int sh=0;
        for(int i=1;i<m-1;i++)head=head->next;
        x=head->next->data;
        if(m==1){
            x=head->data;
            for(int i=1;i<siz;i++)head=head->next;
        }
        int ci=siz-m%siz;
        for(int i=1;i<=ci;i++)p=p->next;
        printf("%d",x);
        y=p->next->data;
        if(x!=y){
            sh=1;
            printf("-%d,",y);
            siz-=2;
            if(siz==0){
                printf("\n");
                system("pause");
                return 0;
            }
        }
        else {
            siz--;
            printf(",");
            if(siz==0){
                printf("\n");
                system("pause");
                return 0;
            }
        }
        if(head->next==p){
            p->next=p->next->next;
            p=head;
            head->next=head->next->next;
        }
        else {
            head->next=head->next->next;
            head=head->next;
            if(sh)p->next=p->next->next;
        }
    }
}