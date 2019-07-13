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
*头插法
*递归实现 
*
**/
void InsertFont(LinkList &first,Datatype endTag){
	Datatype val;
	scanf("%d",&val);
	if(val == endTag){
		return;
	}
	LinkNode *s = new LinkNode;
	s->data = val;
	s->link = first->link;
	first->link = s;
	InsertFont(first,endTag); 
} 
int main(){
	LinkList L;
	initList(L);
	L->data = -1 ;
	//把结束输入的标识放在头结点的数据域中 
	InsertFont(L,L->data);
	Display(L);
	return 0;
 } 
