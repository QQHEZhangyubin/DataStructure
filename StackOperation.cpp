#include<stdio.h>
#define initSize 5
typedef int SelemType;
typedef struct{
	SelemType *elem;
	int maxSize,top;
}SeqStack;
/**
 . ���ڽṹ��
 -> ���ڽṹ��ָ����� 
*/
void InitStack(SeqStack &S){
	S.elem = new SelemType[initSize];
	if(!S.elem){
		printf("�洢����ʧ��!");
	}
	S.maxSize = initSize;
	S.top = -1;
}; 
void OverflowProcess(SeqStack &S){
	printf("��ʼ������!\n");
	SelemType *newArray = new SelemType[S.maxSize * 2];
	if(!newArray){
		printf("�洢����ʧ�ܣ�");
	}
	for(int i=0;i <= S.top;i++){
		newArray[i] = S.elem[i];
	}  
	S.maxSize = 2 * S.maxSize;
	delete []S.elem;
	S.elem = newArray;
};
int StackFull(SeqStack &S){
	if(S.top +1 == S.maxSize){
		printf("ջ���ˣ�%d \n",S.top);
		return -1;
	}
	return 0;
};
void Push(SeqStack &S,SelemType x){
	if(StackFull(S)){
		OverflowProcess(S);
	}
	S.elem[++S.top] = x ;
};

int Pop(SeqStack &S,SelemType &x){
	if(S.top == -1){
		return 0;
	}
	x = S.elem[S.top--];
	printf("%d ��������\n",x);
	return 1;
};
int Gettop(SeqStack &S,SelemType &x){
	if(S.top == -1){
		return 0;
	}
	x = S.elem[S.top];
	return 1;
};
int StackEmpty(SeqStack &S){
	if(S.top == -1){
		return -1;
	}
	return 0;
};

int StackSize(SeqStack &S){
	return S.top +1 ;
}
int main(){
	SeqStack S;
	InitStack(S);
	Push(S,1);
	Push(S,2);
	Push(S,3);
	Push(S,4);
	Push(S,5);
	Push(S,6);	
	int stacksize = StackSize(S);
	printf("ջ�������� �� %d \n",stacksize);
	int k;
	Pop(S,k);
	Pop(S,k);
	Pop(S,k);
	int stacksize2 = StackSize(S);
	printf("ջ�������� �� %d \n",stacksize2);
	Pop(S,k);
	Pop(S,k);
	//Pop(S,k);
		int stacksize3 = StackSize(S);
	printf("ջ�������� �� %d \n",stacksize3);
	int flag  = StackEmpty(S);
	if(flag == -1){
		printf("ջ�գ�\n");
	}else{
		printf("ջ�ǿ� ��\n"); 
	} 

	return 0;
}
