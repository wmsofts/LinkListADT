#include "..\head\LinkedList.h"
#include "..\linkList\linkedList.c"
#include "stdlib.h"
#include "stdio.h" 

int main(){
    LinkedList CreateList(LinkedList L);  //�������� 
    void PrintList(LinkedList L);  //�������� 
	LinkedList L; 
	InitList(&L);
	printf("����������ֵ���������Կո�ָ�������9999������:\n");
	L=CreateList(L);
	PrintList(L);
	int choice;
	printf("\n****���������Ŀ****\n");
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
	printf("ѡ�������Ŀ��������ŵ����֣�:");
	scanf("%d",&choice); 
	switch(choice){
		case 1:{DestroyList(&L);
				PrintList(L);
			break;
		}
		case 2:{LNode *p,*q;
				int m,n,sign;
				p = &m;q = &n; 
				printf("���ĸ�����֮�����:");
				scanf("%d",&m);
				printf("����������ǣ�");
				scanf("%d",&n);
				sign = InsertList(p,q); 
				printf("%d",sign);
				break;
		} 
		case 3:{LNode *p;
				int m,sign;
				p = &m;
				ElemType e;
				printf("����Ҫɾ����λ�ã�");
       			scanf("%d", &m);
	    		sign = DeleteList(p,&e);
	  			printf("%d",sign);
				printf("ɾ����ֵΪ��%d", e);
			break;
		}
		case 4:{
				TraverseList(L,visit);
			break;} 
		case 5:{int target,result;
				printf("��������ҵ�����"); 
				scanf("%d",&target);
				result = SearchList(L,target);
				printf("����ֵ˵����1��ʾ���ڣ�0��ʾ�����ڡ�\n"); 
				printf("%d",result);
			break;
		}
		case 6:{ReverseList(&L);
				PrintList(L);
			break;} 
		case 7:{int result;
				result = IsLoopList(L);
				printf("����ֵ˵����1��ʾ�ǣ�0��ʾ�ǡ�\n"); 
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
		default:printf("ѡ�����"); 
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
		s=(LNode*)malloc(sizeof(LNode));     //�����µĽ�� 
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
    printf("���ڵ�����Ԫ�����£�\n");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
