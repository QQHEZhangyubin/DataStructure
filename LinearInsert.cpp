#include<stdio.h>
typedef int Datatype;
typedef struct node{
	Datatype data;
	struct node* link;
}LinkNode , *LinkList;

void initList(LinkList &first){
	first = new LinkNode;
	if(!first){
		printf("创建结点失败!\n");
	}	
	first->link = NULL;
};
void Display(LinkList &first){
	LinkNode *p = first->link;
	while(p!=NULL){
		printf("%d ===》 ",p->data);
		p = p->link;
	}
};
/**
*尾插法建立单链表（带头结点）
*递归法 
* 
**/ 
void InsertNear(LinkList &first ,LinkNode* &last,Datatype endTag){
	Datatype x;
	printf("%p",last);
	//note:为了打印下last的地址 
	scanf("%d",&x);
	if(x==endTag){
		last = NULL;
	}else{
		last = new LinkNode;	
		last->data =  x;
		//printf("%p",last);
		InsertNear(first,last->link,endTag);
		//note:此时的last->link 并不是NULL(0000000000000000) ,因为并没有指明 last->link = NULL , Last->link的地址可能是系统随机分配的 
	}	

};
int main(){
	LinkList L;
	initList(L);
	L->data = -1 ;
	//把结束输入的标识放在头结点的数据域中 
	InsertNear(L,L->link,L->data);
	Display(L);
	return 0;
 } 
