#include<stdio.h>
typedef char Datatype;
#define initSize 8
typedef struct{
	Datatype *elem;
	int top;
	int maxSize;
}Stack;
void InitStack(Stack &S){
	S.top = -1;
	S.elem = new Datatype[initSize];
	S.maxSize = initSize;
}; 
void OverFlowProcess(Stack &S){
	Datatype *newarray = new Datatype[S.maxSize * 2];
	for(int i=0;i<=S.top;i++){
		newarray[i] = S.elem[i];
	}	
	S.maxSize = 2*S.maxSize;
	delete []S.elem;
	S.elem = newarray;
	
}; 
int StackFull(Stack &S){
	if(S.top +1 == S.maxSize){
		return 1;
	}
	return 0;
}
void Push(Stack &S,Datatype &x){
	if(StackFull(S)){
		OverFlowProcess(S);
	}	
	S.elem[++S.top]= x;
};
int Pop(Stack &S,Datatype &x){
	if(S.top == -1){
		return 0;
	}
	x= S.elem[S.top--];
	return 1;
};
typedef struct{
	Datatype data[initSize];
	int front;
	int rear;
}CircleQueue;
void InitQueue(CircleQueue &Q){
	Q.front = Q.rear = 0;	
};
int EnQueue(CircleQueue &Q,Datatype &x){
	if((Q.rear+1)%initSize == Q.front){
		return 0;
	}
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear +1)%initSize;
	return 1;	
};
int DeQueue(CircleQueue &Q,Datatype &x){
	if(Q.front == Q.rear){
		return 0;
	}
	x = Q.data[Q.front];
	Q.front = (Q.front+1)%initSize;
	return 1;
};
int QueueEmpty(CircleQueue &Q){
	if(Q.rear == Q.front){
		return 0;
	}	
	return 1;
};
int QueueSize(CircleQueue &Q){
	return (Q.rear-Q.front +initSize )% initSize;
}
int main(){
	printf("�޶������ַ�%dλ \n",initSize);
	Stack S;
	CircleQueue Q;
	InitStack(S);
	InitQueue(Q);
	Datatype x;
	scanf("%c",&x);
	while(x!='#'){
		Push(S,x);
		EnQueue(Q,x);
		scanf("%c",&x);
	}
	int size = QueueSize(Q);
	printf("�����ַ����� ��%d \n",size) ;
	char c,h;
	while(QueueEmpty(Q)){
		DeQueue(Q,c);
		Pop(S,h);
		if(c!=h){
			printf("���ǻ����ַ�����\n");
			return 0;
		}
	}
			printf("�����ַ�����\n");
	return 0;	
	
	
}
