#include<stdio.h>
typedef int DataType;
typedef struct node{
	DataType data;
	struct node* link;
}LinkNode,*LinkList;
void initList(LinkList &first){
	first = new LinkNode;
	first->link = NULL; 
};
int main(){
	LinkList L,L1;
	initList(L);
	L1 = L;
	for(int i=0;i<3;i++){
		int k;
		scanf("%d",&k);
		LinkNode *temp = new LinkNode;
		temp->data = k;
		temp->link = NULL;
		L->link = temp;
		L= temp;
	}
	L1 = L1->link;
	//while(L1){
	//	printf("%d ",L1->data);
	//	L1 = L1->link;
	//}
	LinkNode *first2 = NULL,*second2;
	while(L1){
		second2 = L1->link;
		L1->link = first2;
		first2 = L1;
		L1 = second2;
	
	}
	/*
	while(first2){
		printf("%d ",first2->data);
		first2 = first2->link;
	}
	*/
	printf("\n");
	LinkList Lb,L1b;
	initList(Lb);
	L1b = Lb;
	for(int i=0;i<3;i++){
		int k;
		scanf("%d",&k);
		LinkNode *temp = new LinkNode;
		temp->data = k;
		temp->link = NULL;
		Lb->link = temp;
		Lb= temp;
	}
	L1b = L1b->link;
/*	while(L1b){
		printf("%d ",L1b->data);
		L1b = L1b->link;
	}
	*/
	LinkNode *first = NULL,*second;
	while(L1b){
		second = L1b->link;
		L1b->link = first;
		first = L1b;
		L1b = second;
	}
	/*while(first){
		printf("%d ",first->data);
		first = first->link;
	}*/
	LinkNode *end,*end2;
	initList(end);
	end2 = end;
	while(first && first2){
		int k = first->data + first2->data;
		printf("%d,",k); 
			LinkNode *temp = new LinkNode;
			temp->data = k;
			temp->link = NULL;
			end->link = temp;
			end = temp;
			first = first->link;
			first2 = first2->link;
	}
	printf("\n");
	end2 = end2->link; 
	while(end2){
		printf("%d",end2->data);
		end2 = end2->link;
	}
	
	return 0;
} 
