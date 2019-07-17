#include<stdio.h>
#include<stdlib.h>
typedef int DataType ;
typedef struct node{
	DataType data;
	struct node* link;
}LinkNode,*LinkList;
/**
*û��ͷ��� 
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
	*Լɪ�򻷽���취��ª�棬���������룬�������ݽṹѭ������ӡ�� 
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
	scanf("%d",&n);//����� 
	initList(L,n);
	scanf("%d",&k);//�Ӽ��ſ�ʼ���� 
	scanf("%d",&m);//��������̭ 
	Josephus(L,k,m);
	return 0;
} 
