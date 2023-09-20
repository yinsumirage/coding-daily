#include"stdio.h"  
#include"stdlib.h"  
  
struct man{  
    int id;  
    struct man *nextx;  
    struct man *nexty;  
};  
typedef struct man ysf;  
  
int main(){  
    int n,k,m;  
    scanf("%d,%d,%d",&n,&k,&m);  
      
    if(n<1||k<1||m<1){    
        printf("n,m,k must bigger than 0.\n");    
    }    
        
    else if(k>n){    
        printf("k should not bigger than n.\n");      
    }   
      
    else{  
    ysf *head,*p0;  
    p0=(ysf*)malloc(sizeof(ysf));  
    head=p0;  
    p0->id=1;  
      
    ysf *p,*p1,*p2;  
    int i;  
    for(i=2;i<=n;i++){  
        p=(ysf*)malloc(sizeof(ysf));  
        p->id=i;  
        p0->nextx=p;  
        p0=p0->nextx;  
        p->nextx=head;  
    }  
      
    p=head;  
    p0=p->nextx;  
      
    for(i=0;i<n;i++){  
        p0->nexty=p;  
        p0=p0->nextx;  
        p=p->nextx;  
    }  
      
    int total=n;  
    p=head;  
  
    for(i=1;i<k;i++){  
        p=p->nextx;  
    }  
      
    p1=p;  
    p2=p;  
      
    while(total>0){  
        for(i=1;i<m;i++){  
            p1=p1->nextx;  
            p2=p2->nexty;  
        }  
          
        if(p1->id==p2->id){  
            total--;  
            printf("%d,",p1->id);  
              
            ysf *p10,*p20;  
            p10=p1->nexty;  
            p20=p2->nextx;  
              
            p10->nextx=p20;  
            p20->nexty=p10;  
              
            p2=p10;  
            p1=p20;  
        }  
          
        else{  
            total-=2;  
            printf("%d-%d,",p1->id,p2->id);  
              
            ysf *p10,*p20;  
            p10=p1->nexty;  
            p10->nextx=p1->nextx;  
            p10->nextx->nexty=p10;  
            p1=p10->nextx;  
              
            p20=p2->nextx;  
            p20->nexty=p2->nexty;  
            p20->nexty->nextx=p20;  
            p2=p20->nexty;  
              
        }  
    }  
    printf("\n");         
    }  
    system("pause");
}