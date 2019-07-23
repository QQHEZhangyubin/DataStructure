#include<stdio.h>
#include<stdlib.h>
#define M 100
typedef struct node{
	int data;
	int cishu;//�������Ҫ�õ������������У���һ�γ���ջ����ʱ�򲢲��������ڶ��γ�����ջ���ٵ��� 
	struct node *lchild;
	struct node *rchild;
}bitree,*Bit;

typedef struct stack{
	Bit  *elem;
	int top;
	int maxSize; 
}SeqStack;
void InitStack(SeqStack &S){
		S.top = -1;
		S.elem = new Bit[M];
		S.maxSize = M;
};
bitree* create(){
	bitree *t;
	int x;
	scanf("%d",&x);
	if(x == 0){
		t = NULL;
	}else{
		t = (bitree*)malloc(sizeof(bitree));
		t->data = x;
		t->lchild = create();
		t->rchild = create();
	}
	return t;
};
void push(SeqStack &S,bitree *temp){
	S.elem[++S.top] = temp;
};
bitree* pop(SeqStack &S){
	return S.elem[S.top--];
}
/**
*ǰ������ķǵݹ��㷨 
*/ 
void preorder(bitree *t,SeqStack &S){
	bitree *temp = t;
	while( temp != NULL || S.top != -1)	{
		while(temp != NULL){
			printf("%4d",temp->data);
			push(S,temp);
			temp = temp->lchild;
		}
		if(S.top != -1){
			temp = pop(S);	
			temp = temp->rchild;
		}
	}
	printf("\n");
};
/**
*��������ķǵݹ��㷨 
*/ 
void inorder(bitree *t,SeqStack &S){
	bitree *temp = t;
	while(temp != NULL || S.top !=-1){
		while(temp != NULL){
			push(S,temp);
			temp =temp->lchild;
		}
		if(S.top != -1){
			temp = pop(S);
			printf("%4d ",temp->data);
			temp = temp->rchild;
		}
	}
	printf("\n");	
	
};
/**
*��������ķǵݹ��㷨 
*/ 
void laorder(bitree *root,SeqStack &S){
	bitree* temp = root;
	while(temp != NULL || S.top != -1){
		while(temp != NULL){
			temp->cishu = 1;//��ǰ�ڵ��״α�����
			push(S,temp);
			temp = temp->lchild;
			 
		}
		if(S.top != -1){
			temp = pop(S);
			if(temp->cishu == 1){
				//��һ�γ�����ջ��
				temp->cishu++;
				push(S,temp);
				temp = temp->rchild; 
			} else{
				//�ڶ��γ�����ջ�� 
				if(temp->cishu==2){
					//�ڶ�����������ƿգ���ֹ������ѭ��
					printf("%4d",temp->data);
					temp = NULL; 
				}
			}
		}
	}
		printf("\n");
}
int main(){
	bitree *root;
	SeqStack S;
	InitStack(S);
	root = create();
	printf("ǰ������� \n");
	preorder(root,S);
	printf("���������\n");
	inorder(root,S);
	printf("�������: \n");
	laorder(root,S);
	return 0;
} 
