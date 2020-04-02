#include "..\head\LinkedList.h"
#include "..\linkList\linkedList.c"
#include "stdlib.h"
#include "stdio.h" 

int main(){
    LinkedList CreateList(LinkedList L);  //函数声明 
    void PrintList(LinkedList L);  //函数声明 
	LinkedList L; 
	InitList(&L);
	printf("请输入数字值建立链表（以空格分隔，输入9999结束）:\n");
	L=CreateList(L);
	PrintList(L);
	int choice;
	printf("\n****程序测试项目****\n");
	printf("1.DestroyList\n");
	printf("2.InsertList\n");
	printf("3.DeleteList\n");
	printf("4.TraverseList\n");
	printf("5.SearchList\n");
	printf("6.ReverseList\n");
	printf("7.IsLoopList\n");
	printf("8.ReverseEvenList\n");
	printf("9.FindMidNode\n");
	printf("\n**************\n");
	printf("选择测试项目（输入序号的数字）:");
	scanf("%d",&choice); 
	switch(choice){
		case 1:{DestroyList(&L);
				PrintList(L);
			break;
		}
		case 2:{LNode *p,*q;
				int m,n,sign;
				p = &m;q = &n; 
				printf("在哪个数据之后插入:");
				scanf("%d",&m);
				printf("插入的数据是：");
				scanf("%d",&n);
				sign = InsertList(p,q); 
				printf("%d",sign);
				break;
		} 
		case 3:{LNode *p;
				int m,sign;
				p = &m;
				ElemType e;
				printf("输入要删除的位置：");
       			scanf("%d", &m);
	    		sign = DeleteList(p,&e);
	  			printf("%d",sign);
				printf("删除的值为：%d", e);
			break;
		}
		case 4:{
				TraverseList(L,visit);
			break;} 
		case 5:{int target,result;
				printf("输入待查找的数："); 
				scanf("%d",&target);
				result = SearchList(L,target);
				printf("返回值说明：1表示存在，0表示不存在。\n"); 
				printf("%d",result);
			break;
		}
		case 6:{ReverseList(&L);
				PrintList(L);
			break;} 
		case 7:{int result;
				result = IsLoopList(L);
				printf("返回值说明：1表示是，0表示非。\n"); 
				printf("%d",result);
			break;
		}			
		case 8:{ReverseEvenList(&L);
				PrintList(L);
			break;
		}
		case 9:{int *len;
		        len = FindMidNode(&L);
				printf("%d",*len);
			break;
		}
		default:printf("选择错误！"); 
		}
	getch();
	getch();
	return 0;
	
}

LinkedList CreateList(LinkedList L){
	int x;
	L = (LNode*)malloc(sizeof(LNode));
	LNode *s,*r=L;
	scanf("%d",&x);
	while(x!=9999){                             
		s=(LNode*)malloc(sizeof(LNode));     //创建新的结点 
		s->data=x;                           
		r->next=s;                      
		r=s;
		scanf("%d",&x);
	}
	r->next=NULL;
	return L;
 } 
 
void PrintList(LinkedList L){
    LinkedList p;
    p=L->next; 
    printf("现在的链表元素如下：\n");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
