#include<stdio.h>
#include<stdlib.h>
#define M 100
typedef struct node{
	int data;
	int cishu;//后序遍历要用到，后续遍历中，第一次出现栈顶的时候并不弹出，第二次出现在栈顶再弹出 
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
*前序遍历的非递归算法 
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
*中序遍历的非递归算法 
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
*后序遍历的非递归算法 
*/ 
void laorder(bitree *root,SeqStack &S){
	bitree* temp = root;
	while(temp != NULL || S.top != -1){
		while(temp != NULL){
			temp->cishu = 1;//当前节点首次被访问
			push(S,temp);
			temp = temp->lchild;
			 
		}
		if(S.top != -1){
			temp = pop(S);
			if(temp->cishu == 1){
				//第一次出现在栈顶
				temp->cishu++;
				push(S,temp);
				temp = temp->rchild; 
			} else{
				//第二次出现在栈顶 
				if(temp->cishu==2){
					//第二次输出，并制空，防止陷入死循环
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
	printf("前序遍历： \n");
	preorder(root,S);
	printf("中序遍历：\n");
	inorder(root,S);
	printf("后序遍历: \n");
	laorder(root,S);
	return 0;
} 
