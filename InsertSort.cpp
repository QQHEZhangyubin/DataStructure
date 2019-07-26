#include<stdio.h>
int main(){
	int a[15] = {4,8,2,9,3,89,45,87,98,65,23,4644,44946,646446,5646486};
	int temp;
	int i,j;
	for(i=1;i<15;i++){
		if(a[i]<a[i-1]){
			temp = a[i];
			for(j = i-1;j>=0 && temp<a[j];j--){
				a[j+1]=a[j];
			}
			printf("j == %d \n",j); 
			a[j+1]=temp;
		}
	}
	for(int k =0;k<15;k++){
		printf("%d ",a[k]);
	}	
	
} 
