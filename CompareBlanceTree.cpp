/**
*����һ������������ӡ����ǰ�����򣬺������Լ��жϴ����Ƿ�Ϊƽ������� 
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
//���Ĵ��� 
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
	printf("ǰ�������"); 
	preOrderTraverse(root);
	printf("\n���������");
	inOrderTraverse(root);
	printf("\n���������");
	lastOrderTraverse(root);
	int depth = DepthTree(root);
	printf("���ĸ߶��ǣ�%d \n",depth); 
	if(is_blance){
		printf("������ƽ�������");	
	}else{
		printf("��������ƽ�������");	
	}	
	return 0;
}
