/**
*两个集合的合并 
*/
 
#include<stdio.h>
#include<stdlib.h> 
typedef int Datatype;
typedef struct node{
	
	Datatype data;
	struct node* link;
}LinkNode , *LinkList;
 void InitList(LinkList &first){
 	first = new LinkNode;
	first->link = NULL;	
 };
 void InsertRear(LinkList &first,LinkNode* &last,Datatype endTag){
 	Datatype val;
	scanf("%d",&val);
	if(val == endTag){
		last = NULL;
	}else{
		last = new LinkNode;
		last->data = val;
		InsertRear(first,last->link,endTag);	
	}
 };
 void InsertFont(LinkList &first,Datatype endTag){
 	Datatype val;
	scanf("%d",&val);
	if(val == endTag){
			
	}else{
		LinkNode *s = new LinkNode;
		s->data = val;
		s->link = first->link;
		first->link = s; 
		InsertFont(first,endTag);
	}
 };
 void Display(LinkList &first){
 	LinkNode *first2 = first->link;
	 while(first2 != NULL){
	 	printf("%d,",first2->data);
		first2 = first2->link; 
	 }
	 printf("\n");	
 };
 /**
 *合并两个有序链表
 *两个链表本身也是递增 
 **/
 void MergeList(LinkList &l1,LinkList &l2,LinkList &l3){
 	LinkNode *p1,*p2,*p3;
	 p1 = l1->link;
	 p2 = l2->link;
	 p3 = l3 = l1;
	 while(p1 != NULL && p2 != NULL){
	 	if(p1->data <= p2->data){
	 		p3->link = p1;
	 		p3 = p1;
	 		p1 = p1->link;
		 }else{
		 	p3->link = p2;
		 	p3 = p2;
		 	p2 = p2->link;
		 }
	 }
	 p3->link = p1==NULL ? p2:p1;
	 free(l2);	
 };
int main(){
	LinkList L1,L2,L3;
	InitList(L1);
	InitList(L2);
	L1->data = -1;
	L2->data = -1;
	printf("头插法建立5个元素的单链表，以-1结束\n");
	InsertFont(L1,L1->data);
	Display(L1);
	printf("尾插法建立5个元素的单链表，以-1结束\n");
	InsertRear(L2,L2->link,L2->data);
	Display(L2);
	MergeList(L1,L2,L3);
	Display(L3);
	return 0;
}
