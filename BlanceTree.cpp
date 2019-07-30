/**
*建立一个AVL树，顺便打印它的前序，中序，后续遍历 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cmath>
typedef struct node{
	int data;
	int high;
	struct node *lt,*rt;
}Node;
int is_blance = 1;
int max(int h,int k){
	return h>k?h:k;
}
int deep(Node *root){
	if(!root){
		return 0;
	}else{
		int lh=deep(root->lt),rh = deep(root->rt);
		if(abs(lh-rh) >1 ){
			is_blance = 0;
		}
		return (lh>rh?lh:rh)+1;	
	}
	return 0;
};
Node *RR(Node *root){
	
	Node *p = root->rt;
	root->rt = p->lt;
	p->lt = root;
	root->high = max(deep(root->lt),deep(root->rt))+1;
	return p;
};
Node *LL(Node *root){
	Node *p = root->lt;
	root->lt =  p->rt;
	p->rt = root;
	root->high = max(deep(root->lt),deep(root->rt))+1;
	return p;	
};
Node *LR(Node *root){
	root->lt = RR(root->lt);
	root = LL(root);
	return root;
};
Node *RL(Node *root){
	root->rt = LL(root->rt);
	root = RR(root);
	return root;
}
Node  *Insert(Node *root ,int num){
	if(!root){
		root = new Node;
		root->data = num;
		root->high = 0;
		root->lt = NULL;
		root->rt = NULL;
	}else{
		if(num  < root->data){
			root->lt = Insert(root->lt,num);
			if(abs(deep(root->lt)-deep(root->rt)) >1 ){
				if(num >= root->lt->data){
					root = LR(root);
				}else{
					root = LL(root);
				}
			}
		}else{
			root->rt = Insert(root->rt,num)	;
			if(abs(deep(root->lt)-deep(root->rt)) > 1){
				if(num >= root->rt->data){
					root = RR(root);
				}else{
					root = RL(root); 
				}
			}
			
		}
	}
	root->high = max(deep(root->lt),deep(root->rt))+1;
	return root;
};
void preOrderTree(Node *root){
	if(root){
		printf("%d ",root->data);
		preOrderTree(root->lt);
		preOrderTree(root->rt); 
	}
};
void inOrderTree(Node *root){
	if(root){
		inOrderTree(root->lt);
		printf("%d ",root->data);
		inOrderTree(root->rt);
	}
};
void postOrderTree(Node *root){
	if(root){
		postOrderTree(root->lt);
		postOrderTree(root->rt);
		printf("%d " ,root->data);
	}
} 
int main(){
	struct node *root = NULL;
	int n,num;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&num);
		root = Insert(root,num);
	}
	printf("%d\n",root->data);	
	printf("前序遍历：");
	preOrderTree(root);
	printf("\n中序遍历:");
	inOrderTree(root);
	printf("\n后序遍历：");
	postOrderTree(root);
	if(is_blance){
		printf("\n此树是平衡二叉树！");
	}else{
			printf("\n此树不是平衡二叉树！");
	} 
	return 0;
}
