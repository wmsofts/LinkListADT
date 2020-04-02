#include "..\head\duLinkedList.h"
#include "..\dulinkList\duLinkedList.c"
#include "stdlib.h"
#include "stdio.h" 

int main(){
    DuLinkedList CreateList_DuL(DuLinkedList L);  //函数声明 
    void PrintList_DuL(DuLinkedList L);  //函数声明 
	DuLinkedList L; 
	InitList_DuL(&L);
	printf("请输入数字值建立链表（以空格分隔，输入9999结束）:\n");
	L=CreateList_DuL(L);
	PrintList_DuL(L);
	int choice;
	printf("\n****程序测试项目****\n");
	printf("1.DestroyList_DuL\n");
	printf("2.InsertBeforeList_DuL\n");
	printf("3.InsertAfterList_DuL\n");
	printf("4.DeleteList_DuL\n");
	printf("5.TraverseList_DuL\n");
	printf("\n**************\n");
	printf("选择测试项目（输入序号的数字）:");
	scanf("%d",&choice); 
	switch(choice){
		case 1:{DestroyList_DuL(&L);
				PrintList_DuL(L);
			break;
		}
		case 2:{DuLNode *p,*q;
				int m,n,sign;
				p = &m;q = &n; 
				printf("在哪个数据之前插入:");
				scanf("%d",&m);
				printf("插入的数据是：");
				scanf("%d",&n);
				sign = InsertBeforeList_DuL(p,q); 
				printf("%d",sign);
				break;
		} 
		case 3:{DuLNode *p,*q;
				int m,n,sign;
				p = &m;q = &n; 
				printf("在哪个数据之后插入:");
				scanf("%d",&m);
				printf("插入的数据是：");
				scanf("%d",&n);
				sign = InsertAfterList_DuL(p,q); 
				printf("%d",sign);
				break;
		}
		case 4:{DuLNode *p;
				int m,sign;
				p = &m;
				ElemType e;
				printf("输入要删除的位置：");
       			scanf("%d", &m);
	    		sign = DeleteList_DuL(p,&e);
	  			printf("%d",sign);
				printf("删除的值为：%d", e);
			break;
				} 
		case 5:{
				TraverseList_DuL(L,visit);
				printf("测试不可用！");
				break;
		}
		default:printf("选择错误！"); 
		}
	getch();
	getch();
	return 0;
	
}

DuLinkedList CreateList_DuL(DuLinkedList L){
	int x;
	L = (DuLNode*)malloc(sizeof(DuLNode));
	DuLNode *s,*r=L;
	scanf("%d",&x);
	while(x!=9999){                             
		s=(DuLNode*)malloc(sizeof(DuLNode));     //创建新的结点 
		s->data=x;                           
		r->next=s;                      
		r=s;
		scanf("%d",&x);
	}
	r->next=NULL;
	return L;
 } 
 
void PrintList_DuL(DuLinkedList L){
    DuLinkedList p;
    p=L->next; 
    printf("现在的链表元素如下：\n");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
