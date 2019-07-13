#include<stdio.h>
typedef int Datatype;
typedef struct node{
	Datatype data;
	struct node* link;
}LinkNode , *LinkList;

void initList(LinkList &first){
	first = new LinkNode;
	if(!first){
		printf("�������ʧ��!\n");
	}	
	first->link = NULL;
};
void Display(LinkList &first){
	LinkNode *p = first->link;
	while(p!=NULL){
		printf("%d ===�� ",p->data);
		p = p->link;
	}
};
/**
*β�巨������������ͷ��㣩
*�ݹ鷨 
* 
**/ 
void InsertNear(LinkList &first ,LinkNode* &last,Datatype endTag){
	Datatype x;
	printf("%p",last);
	//note:Ϊ�˴�ӡ��last�ĵ�ַ 
	scanf("%d",&x);
	if(x==endTag){
		last = NULL;
	}else{
		last = new LinkNode;	
		last->data =  x;
		//printf("%p",last);
		InsertNear(first,last->link,endTag);
		//note:��ʱ��last->link ������NULL(0000000000000000) ,��Ϊ��û��ָ�� last->link = NULL , Last->link�ĵ�ַ������ϵͳ�������� 
	}	

};
int main(){
	LinkList L;
	initList(L);
	L->data = -1 ;
	//�ѽ�������ı�ʶ����ͷ������������ 
	InsertNear(L,L->link,L->data);
	Display(L);
	return 0;
 } 
