#include "../head/duLinkedList.h"
#include "stdlib.h"
#include "stdio.h" 
#define ERROR 0
#define SUCCESS 1

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	*L = (DuLinkedList)malloc(sizeof(DuLinkedList));  
	if((*L) == NULL){				//if initialize failure			
		return ERROR;
	}
	(*L)->next = NULL;
	(*L)->prior = NULL;
	return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLNode *p;
	p = *L;
	while(p){
		p = p->next;
		free(*L);
		*L = p;
	} 
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	if(p == NULL||q == NULL||p->prior == NULL)
		return ERROR;
	q->next = p;
	q->prior = p->prior;
	p->prior->next = q;
	p->prior = q;
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	if(p == NULL||q == NULL||p->prior == NULL)
		return ERROR;
	q->next = p->next;
	q->prior=p;
	p->next->prior = q;
	p->next=q; 	
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	if(p == NULL|| p->next == NULL) 
		return ERROR;
	*e = p->next->data;
	DuLNode *q ;
	q = p->next;
	p->next = p->next->next;
	q->next->prior = p;
	free(q);
	return SUCCESS;	
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	DuLNode *p ;
	p = L;
	while(p){
		visit(p->data);
		p = p->next;
	}
}

void visit(ElemType e){
	printf("%d ",e);
}

