/**
*建立一个二叉树，打印它的前序，中序，后续，以及判断此树是否为平衡二叉树 
*/
#include<stdio.h>
#include<cmath>
typedef int TelemType;
typedef struct BinaryTreeNode{
	TelemType data;
	struct BinaryTreeNode *Left;
	struct BinaryTreeNode *Right; 
}Node;
int is_blance = 1;
//核心代码 
Node* CreateBinaryTree(){
		Node *p;
		TelemType ch;
		scanf("%d",&ch);
		if(ch == 0){
			p  =  NULL;
		}else{
			p = new Node;
			p->data = ch;
			p->Left = CreateBinaryTree();
			p->Right = CreateBinaryTree(); 
		}
		return p;
};
void preOrderTraverse(Node *root){
	if(root){
		printf("%d ",root->data);
		preOrderTraverse(root->Left);
		preOrderTraverse(root->Right);
	}	
};

void inOrderTraverse(Node *root){
	if(root){
		inOrderTraverse(root->Left);
		printf("%d ",root->data);
		inOrderTraverse(root->Right);
	}
};
void lastOrderTraverse(Node *root){
	if(root){
		lastOrderTraverse(root->Left);
		lastOrderTraverse(root->Right);
		printf("%d ",root->data);
	}
};
int DepthTree(Node *root){
	if(root == NULL){
		return 0;
	}else{
		int lh=DepthTree(root->Left) ,rh = DepthTree(root->Right);
		if(abs(lh - rh) >1){
			is_blance = 0;
		}
		return (lh>rh?lh:rh)+1;
	}
}
int main(){
	Node *root = NULL;
	root = CreateBinaryTree();
	printf("前序遍历："); 
	preOrderTraverse(root);
	printf("\n中序遍历：");
	inOrderTraverse(root);
	printf("\n后序遍历：");
	lastOrderTraverse(root);
	int depth = DepthTree(root);
	printf("树的高度是：%d \n",depth); 
	if(is_blance){
		printf("此树是平衡二叉树");	
	}else{
		printf("此树不是平衡二叉树");	
	}	
	return 0;
}
