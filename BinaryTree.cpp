/**https://blog.csdn.net/ac_blood/article/details/77047877*/ 
#include<stdio.h>
typedef  int TelemType;
typedef struct BinaryTreeNode{
	TelemType data;
	struct BinaryTreeNode *Left;
	struct BinaryTreeNode *Right;
} Node;
/*
*������������ 
*/
Node* CreateBinaryTree(){
	Node *p;
	TelemType ch;
	scanf("%d",&ch);
	if(ch == 0){
		//�������Ҷ�ӽڵ㣬�����������������ֱ�ֵΪ0 
		p = NULL;
	}else{
		p = new Node;
		p->data = ch;
		p->Left = CreateBinaryTree();//�ݹ鴴�������� 
		p->Right =  CreateBinaryTree();//�ݹ鴴�������� 
	} 
	return p;
} 
/**
*������� 
*/
void preOrderTraverse(Node* root){
	if(root){

		printf("%d ",root->data);
		preOrderTraverse(root->Left);
		preOrderTraverse(root->Right);
	}
}
/*
*������� 
*/
void inOrderTraverse(Node* root){
	if(root){
		inOrderTraverse(root->Left);
		printf("%d ",root->data);
		inOrderTraverse(root->Right);
	}
}
/**
*������� 
*/
void lastOrderTraverse(Node* root){
	if(root){
		lastOrderTraverse(root->Left);
		lastOrderTraverse(root->Right);
		printf("%d ",root->data);
	}
}
/**
*�������ڵ�����Ŀ 
*/
int Nodenum(Node* root){
	if(root == NULL){
		return 0;
	}else{
		return 1+ Nodenum(root->Left) + Nodenum(root->Right);
	}
} 
/**
*��������� 
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
*������Ҷ�ӽڵ��� 
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
	printf("�����������ɹ� \n");
	printf("�������ܽڵ���Ϊ��%d \n",Nodenum(root));
	printf("���������Ϊ: %d \n",DepthTree(root));
	printf("������Ҷ�ӽڵ���Ϊ�� %d \n",Leafnum(root));
	
	printf("ǰ���������� \n");
	preOrderTraverse(root);
	printf("\n");
	printf("������������ \n");
	inOrderTraverse(root);
	printf("\n");
	printf("������������� \n");
	lastOrderTraverse(root);
	printf("\n");
		
	return 0;
} 
