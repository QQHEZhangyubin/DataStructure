#include<stdio.h>
void Reserve(int A[],int left,int right,int size){
	int mid = (left + right)/2;
	for(int i=0;i<=mid-left;i++){
		int temp = A[left+i];
		A[left+i] = A[right-i];
		A[right-i] = temp;
	}
	
};
void Exchange(int A[],int m,int n,int size){
	Reserve(A,0,m+n-1,size);
	Reserve(A,0,n-1,size);
	Reserve(A,n,m+n-1,size);	
	
};
int main(){
	int A[10] = {1,2,3,4,5,6,7,8,9,10};
	printf("生成前顺序表:");
	for(int i=0;i<10;i++){
		printf("%5d",A[i]);
	}
	printf("\n");
	Exchange(A,5,5,10);
	printf("生成后顺序表：");
	for(int i=0;i<10;i++){
		printf("%5d",A[i]);
	}
	return 0;
}
 
