#include <stdio.h>  
#include <stdlib.h>  

typedef struct node  
{   int         data;  
    struct node * next;  
} NODE;  
  

void change( int n, int m, NODE * head ){
    int cot=50,chu;
    NODE *k;k=(NODE*)malloc(sizeof(NODE));
    k=head;
    while(cot--){        
        NODE *p;p=(NODE*)malloc(sizeof(NODE));
        n*=10;chu=n/m;
        n%=m;
        p->data=chu;k->next=p;
        k=p;
        if(n==0)break;
    }
    k->next=NULL;
}
  
void output( NODE * head )  
{   int k=0;  
  
    printf("0.");  
    while ( head->next != NULL && k<50 )  
    {   printf("%d", head->next->data );  
        head = head->next;  
        k ++;  
    }  
    printf("\n");  
}  
  
int main()  
{   int n, m;  
    NODE * head;  
    scanf("%d%d", &n, &m);  
    head = (NODE *)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
    change( n, m, head );  
    output( head );  
    //system("pause");
    return 0;  
}