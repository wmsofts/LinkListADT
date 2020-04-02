#include "..\head\duLinkedList.h"
#include "..\dulinkList\duLinkedList.c"
#include "stdlib.h"
#include "stdio.h" 

int main(){
    DuLinkedList CreateList_DuL(DuLinkedList L);  //�������� 
    void PrintList_DuL(DuLinkedList L);  //�������� 
	DuLinkedList L; 
	InitList_DuL(&L);
	printf("����������ֵ���������Կո�ָ�������9999������:\n");
	L=CreateList_DuL(L);
	PrintList_DuL(L);
	int choice;
	printf("\n****���������Ŀ****\n");
	printf("1.DestroyList_DuL\n");
	printf("2.InsertBeforeList_DuL\n");
	printf("3.InsertAfterList_DuL\n");
	printf("4.DeleteList_DuL\n");
	printf("5.TraverseList_DuL\n");
	printf("\n**************\n");
	printf("ѡ�������Ŀ��������ŵ����֣�:");
	scanf("%d",&choice); 
	switch(choice){
		case 1:{DestroyList_DuL(&L);
				PrintList_DuL(L);
			break;
		}
		case 2:{DuLNode *p,*q;
				int m,n,sign;
				p = &m;q = &n; 
				printf("���ĸ�����֮ǰ����:");
				scanf("%d",&m);
				printf("����������ǣ�");
				scanf("%d",&n);
				sign = InsertBeforeList_DuL(p,q); 
				printf("%d",sign);
				break;
		} 
		case 3:{DuLNode *p,*q;
				int m,n,sign;
				p = &m;q = &n; 
				printf("���ĸ�����֮�����:");
				scanf("%d",&m);
				printf("����������ǣ�");
				scanf("%d",&n);
				sign = InsertAfterList_DuL(p,q); 
				printf("%d",sign);
				break;
		}
		case 4:{DuLNode *p;
				int m,sign;
				p = &m;
				ElemType e;
				printf("����Ҫɾ����λ�ã�");
       			scanf("%d", &m);
	    		sign = DeleteList_DuL(p,&e);
	  			printf("%d",sign);
				printf("ɾ����ֵΪ��%d", e);
			break;
				} 
		case 5:{
				TraverseList_DuL(L,visit);
				printf("���Բ����ã�");
				break;
		}
		default:printf("ѡ�����"); 
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
		s=(DuLNode*)malloc(sizeof(DuLNode));     //�����µĽ�� 
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
    printf("���ڵ�����Ԫ�����£�\n");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
