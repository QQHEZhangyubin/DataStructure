#include<stdio.h>
typedef int Datatype;
typedef struct node{
	Datatype data;
	struct node* link;
}LinkNode ,*LinkList; 

void initList(LinkList &first){
	first = new LinkNode;
	if(!first){
		printf("创建头结点失败!\n");
	}
	printf("单链表的头地址：%x\n",first);
	first->link = NULL;
};
LinkNode * Locate(LinkList &first,int i){
	// i>=0 返回第 i 个结点的地址 
	if(i<0) {
		return NULL;
	}
	LinkNode *p = first;
	int k=0;
	while(p != NULL && k<i){
		p = p->link;
		k++;
	}
	return p;
}
int Insert(LinkList &first,int i,Datatype x){
	    // i>=1 
		LinkNode *p = Locate(first,i-1);
		if(p==NULL){
			return 0;
		}
		LinkNode *s = new LinkNode;
		if(!s){
			printf("创建结点失败！\n");
		}
		s->data = x;
		s->link = p->link;
		p->link = s;
		return 1;
};
int Length(LinkList &first){
	LinkList p = first->link;
	int k=0;
	while(p!=NULL){
		k++;
		p = p->link;
	}
	return k;
};
void Display(LinkList &first){
	LinkList first2 = first->link;
	while(first2!= NULL){
		printf("结点地址(不包含头地址)= %x\n",first2);
		printf("%d\n",first2->data);
		first2 = first2->link;
	}
}
void ClearList(LinkList &first){
	LinkNode *q;
	while(first->link != NULL){
		q = first->link;
		first->link = q->link;
		delete q;
	}	
};
void Isimpty(LinkList &first){
	if(first->link == NULL){
		printf("表空\n"); 
	}else{
		printf("表非空\n"); 
	}
};
int Remove(LinkList &first ,int i,Datatype &x){
	if(i<1){
		return 0;
	}
	LinkNode *p = Locate(first,i-1);
	LinkNode* q = p->link;
	x = q->data;
	p->link = q->link;	
	delete q;
	return 1;
};
int  main()
{
	LinkList L;
	initList(L);
	Insert(L,1,1);
	Insert(L,2,2);
	Insert(L,3,3);
	Insert(L,4,4);
	Display(L);
	int length = Length(L);
	printf("链表长度是 %d \n",length);
	ClearList(L);
	Isimpty(L);
	Insert(L,1,10);
	Insert(L,2,11);
	Insert(L,3,12);
	Insert(L,4,13);
	Insert(L,5,14);
	Display(L);
	int length2 = Length(L);
	printf("链表长度是 %d \n",length2);
	int b;
	Remove(L,3,b);
	Remove(L,4,b);
	Display(L);
	return 0;
	
 } 
