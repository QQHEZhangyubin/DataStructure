#include<stdio.h>
#include<stdlib.h>
typedef int DataType ;
typedef struct node{
	DataType data;
	struct node* link;
}LinkNode,*LinkList;
/**
*没有头结点 
*/
void initList(LinkList &first,int n){
	first = new LinkNode;
	LinkNode *p = first;
	p->data = 1;
	for(int i=2;i <= n ;i++){
		LinkNode *s = new LinkNode;
		s->data = i;
		p->link = s;
		p = s;
	}
	p->link = first;
};

void Josephus(LinkList &first,int k,int m){
	/**
	*约瑟夫环解决办法简陋版，容易理解代码，加深数据结构循环链表印象 
	*/
	LinkNode *p,*s,*q;
	p = first;
	for(int i=1;i<k;i++){
		q = p;
		p = p->link;
	}
	while(p->link != p){
		
		for(int j=1;j<m;j++){
			q = p;
			p = p->link;
		}
		printf("%5d",p->data);
		s = p;
		q->link = p->link;
		p = p->link;
		free(s) ;
	}
	printf("\n");	
	printf("%5d",p->data);
};
int main(){
	LinkList L;
	int n,k,m;
	scanf("%d",&n);//结点数 
	initList(L,n);
	scanf("%d",&k);//从几号开始报数 
	scanf("%d",&m);//数到几淘汰 
	Josephus(L,k,m);
	return 0;
} 
