/**https://blog.csdn.net/ac_blood/article/details/77047877*/ 
#include<stdio.h>
typedef  int TelemType;
typedef struct BinaryTreeNode{
	TelemType data;
	struct BinaryTreeNode *Left;
	struct BinaryTreeNode *Right;
} Node;
/*
*先序建立二叉树 
*/
Node* CreateBinaryTree(){
	Node *p;
	TelemType ch;
	scanf("%d",&ch);
	if(ch == 0){
		//如果到了叶子节点，接下来的左，右子树分别赋值为0 
		p = NULL;
	}else{
		p = new Node;
		p->data = ch;
		p->Left = CreateBinaryTree();//递归创建左子树 
		p->Right =  CreateBinaryTree();//递归创建右子树 
	} 
	return p;
} 
/**
*先序遍历 
*/
void preOrderTraverse(Node* root){
	if(root){

		printf("%d ",root->data);
		preOrderTraverse(root->Left);
		preOrderTraverse(root->Right);
	}
}
/*
*中序遍历 
*/
void inOrderTraverse(Node* root){
	if(root){
		inOrderTraverse(root->Left);
		printf("%d ",root->data);
		inOrderTraverse(root->Right);
	}
}
/**
*后序遍历 
*/
void lastOrderTraverse(Node* root){
	if(root){
		lastOrderTraverse(root->Left);
		lastOrderTraverse(root->Right);
		printf("%d ",root->data);
	}
}
/**
*二叉树节点总数目 
*/
int Nodenum(Node* root){
	if(root == NULL){
		return 0;
	}else{
		return 1+ Nodenum(root->Left) + Nodenum(root->Right);
	}
} 
/**
*二叉树深度 
*/
int DepthTree(Node* root){
	if(root){
		return DepthTree(root->Left) > DepthTree(root->Right) ? DepthTree(root->Left)+1 : DepthTree(root->Right)+1;
	}
	if(root == NULL){
		return 0;
	}
}
/**
*二叉树叶子节点数 
*/ 
int Leafnum(Node* root){
	if(!root){
		return 0;
	}
	else if((root->Left == NULL) && (root->Right == NULL)){
		return 1;
	}
	else{
		return (Leafnum(root->Left) + Leafnum(root->Right));
	}
	
} 
int main(){
	Node *root = NULL;
	root = CreateBinaryTree();
	printf("二叉树建立成功 \n");
	printf("二叉树总节点数为：%d \n",Nodenum(root));
	printf("二叉树深度为: %d \n",DepthTree(root));
	printf("二叉树叶子节点数为： %d \n",Leafnum(root));
	
	printf("前序遍历结果： \n");
	preOrderTraverse(root);
	printf("\n");
	printf("中序遍历结果： \n");
	inOrderTraverse(root);
	printf("\n");
	printf("后续遍历结果： \n");
	lastOrderTraverse(root);
	printf("\n");
		
	return 0;
} 
