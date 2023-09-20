#include<iostream>
#include<malloc.h>
#include<stdlib.h>

using namespace std;


#define OVERFLOW -2
#define ERROR -1
#define OK 1
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int Status;

//结构体定义
typedef struct LNode{
    	int data;
    	struct LNode *next;
	}LNode, *LinkList;

//删除
	Status ListDelete_L(LinkList &L, int i, int &e)
	{
		LinkList q;
	    q=L->next;
	    L->next=q->next;
	    e=q->data;
	    free(q);
	    return OK;
	}
//初始化
	void CreateList_L(LinkList &L,int n)
	{
		LinkList p;
		LinkList q;//用于标记最初结点以后连接最末节点
		L=(LinkList)malloc(sizeof(LNode));
		L->next=NULL;
		
		p=(LinkList)malloc(sizeof(LNode));
		p->data=n;
		q=p;       //q是n节点
		p->next=L->next;
		L->next=p;
		for(int i=n-1;i>0;--i) //从后向前插
		{
			p=(LinkList)malloc(sizeof(LNode));
			p->data=i;
			p->next=L->next;
			L->next=p;
		}
		q->next=p;
	}

int main( )
{	
	//创建基指针
	LinkList L;
	int m;
	cin>>m;             // 最大长度
	CreateList_L(L,m);

	int s,n;
	cin>>s;                         //起始位置
	for(int i=1;i<s;i++){     //初始移动
		L=L->next;
	}                             

	cin>>n;                        //间隔数
	for(int i=1;i<m;i++){
		int e;
		for(int i=1;i<n;i++)  
			L=L->next;
		ListDelete_L(L,n,e);
		printf("%d,",e);
	}
	printf("%d.",L->data);
	//system("pause");
	return 0;
}