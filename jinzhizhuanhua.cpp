#include<stdio.h>
typedef unsigned int Datatype;
#define initSize 5
typedef struct{
	Datatype *elem;
	int top,maxSize; 
}SeqStack;

void InitSeqStack(SeqStack &S){
	S.elem = new Datatype[initSize];
	S.top = -1;
	S.maxSize = initSize;
};
void OverFlowProcess(SeqStack &S){
	printf("扩容了！\n");
	Datatype *newArray = new Datatype[S.maxSize*2];
	for(int i=0;i<=S.top;i++){
		newArray[i] = S.elem[i];
	}	
	S.maxSize = S.maxSize*2;
	delete []S.elem;
	S.elem = newArray;
};
int StackFull(SeqStack &S){
	if(S.top+1 == S.maxSize){
		return -1;
	}
	return 0;	
};
void Push(SeqStack &S,Datatype x){
	if(StackFull(S)){
		OverFlowProcess(S);
	}
	S.elem[++S.top] = x;
};
int StackEmpty(SeqStack &S){
	if(S.top == -1){
		return -1;
	}
	return 0;
};
int Pop(SeqStack &S,Datatype & g){
	if(S.top == -1){
		return 0;
	}	
	g = S.elem[S.top--];
};
int main(){
	/**
	*当数据足够大，发现结果出错
	例子：4845456121 
	*/
	unsigned int N,k,d;
	printf("输入十进制整数：");
	scanf("%d",&N);
	printf("要转化为多少进制整数？");
	scanf("%d",&k);
	SeqStack S;
	InitSeqStack(S);
	while(N>0){
		Push(S,N%k);
		N=N/k;
	}
	while(!StackEmpty(S)){
		Pop(S,d);
		printf("%d",d);
	}
	return 0;
}
