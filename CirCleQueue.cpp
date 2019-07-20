#include<stdio.h>
#define maxSize 4
typedef int Datatype;
typedef struct{
	Datatype elem[maxSize];
	int front,rear;
}CirCleQueue;
void InitQueue(CirCleQueue &Q){
	Q.front = Q.rear=0;	
};
int EnQueue(CirCleQueue &Q,Datatype x){
	if((Q.rear+1)%maxSize == Q.front){
		printf("����������\n");
		return 0;
	}  	
	Q.elem[Q.rear] = x;
	Q.rear = (Q.rear+1)%maxSize;
	return 1;
};
int DeQueue(CirCleQueue &Q,Datatype &x){
	if(Q.rear == Q.front){
		return 0;
	}
	x= Q.elem[Q.front];

	Q.front = (Q.front + 1)%maxSize;
	return 1;
};
int GetFront(CirCleQueue &Q,Datatype &x){
	if(Q.front == Q.rear){
		return 0;
	}	
	x= Q.elem[Q.front];
	return 1;
};
int QueueEmpty(CirCleQueue &Q){
	if(Q.front == Q.rear){
		return 0;
	}
	return 1;
};
int QueueFull(CirCleQueue &Q){
	if((Q.rear+1)%maxSize == Q.front){
		return 0;
	}	
	return 1;
};
int QueueSize(CirCleQueue &Q){
	return (Q.rear - Q.front + maxSize)%maxSize;
};
void Display(CirCleQueue &Q){
	printf("�Ŷ������");
	
	while(QueueEmpty(Q)){
		Datatype x;
		DeQueue(Q,x);
		printf("%5d",x);
	
	}
};
int main(){
	CirCleQueue Q;
	InitQueue(Q);
	int initqueuesize = QueueSize(Q);
	printf("��ʼ�����г��ȣ�%d \n",initqueuesize);

	EnQueue(Q,1);
	EnQueue(Q,2);
	EnQueue(Q,3);
	int queuesize = QueueSize(Q);
	printf("Ŀǰ���г��ȣ�%d \n",queuesize);
	int k;
	GetFront(Q,k);
	printf("Ŀǰ���ڶ���ǰ����ǣ�%d  \n",k);
	int m;
	DeQueue(Q,m);
	printf("��ͷ���е��ǣ�%d   \n",m);
		GetFront(Q,k);
	printf("Ŀǰ���ڶ���ǰ����ǣ�%d  \n",k);
	
	EnQueue(Q,4);
	EnQueue(Q,5);
	EnQueue(Q,6);
	int queuesize2 = QueueSize(Q);
	printf("Ŀǰ���г��ȣ�%d \n",queuesize2);
	Display(Q);
	return 0;
}
