#include "../head/LinkedList.h"
#include "stdlib.h"
#include "stdio.h" 
#define ERROR 0
#define SUCCESS 1

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	*L = (LinkedList)malloc(sizeof(LinkedList));  
	if((*L) == NULL){				//if initialize failure			
		return ERROR;
	}
	(*L)->next = NULL;
	return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LinkedList p;
	while(*L){
		p = (*L)->next;
		free(*L);
		*L = p;
	}
/*	LNode *p;
	p = *L;
	while(p){
		p = p->next;
		free(*L);
		*L = p;
	} */
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	if(!p){						//if P node does not exist 
		return ERROR;
	}
		q->next = p->next;		//q after node p
		p->next = q;
		return SUCCESS;
}

/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	if(p == NULL||p->next == NULL){
		return ERROR;
	}
	LNode *q;
	q = p->next;
	*e = q->data ;
	p->next = q->next ;
	free(q) ;
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	LNode *p;
	p = L;
	while(p){
		visit(p->data );
		p = p->next;
	}
}

void visit(ElemType e){
	printf("%d",e);
} 

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	LNode *p;
	p = L;
	while(p){
		if(p->data == e)
			return SUCCESS;
		else 
			p = p->next;
	}
	return ERROR;
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	
	if((*L)== NULL||(*L)->next == NULL){
		return ERROR;
	}
	LNode *p, *q, *r;		
	p = (*L)->next;
	(*L)->next = NULL;
	q = r = NULL;
	while(p){
		q = p->next;
		p->next = r;
		r = p;
		p = q;
	}
	(*L)->next = r; 
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	if(L == NULL||L->next == NULL){
		return ERROR;
	}
	LNode *fast, *slow;
	fast = slow = L;				
	while(fast && fast->next){
			slow = slow->next;		
			fast = fast->next->next;
			if(slow == fast){
				return SUCCESS;
			}			
	}
	return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
	LNode *p, *q, *r;
	p = *L;
	*L = p->next;
	while(p && p->next){
		q = p->next;
		r = q->next;
		if(q->next && q->next->next){			//如果q->next不存在，结点个数为偶数
			p->next = q->next->next;			//如果q->next->next不存在，结点个数为奇数
		}else{									//如果都存在，遍历未结束
			p->next = q->next;
		}
		q->next = p;							//将偶数结点反转
		p = r;
	}
	return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	LNode *middle = *L;
	int cnt;
	for(cnt=0; middle; cnt++)
		middle = middle->next;
	middle = *L;
	for(int i=0; i<cnt/2; i++)
		middle = middle->next;
	return middle;
}

