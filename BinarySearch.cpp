#include<stdio.h>
int main(){
	int a[10] = {4,6,8,15,19,22,25,26,30,56};
	int low,high,mid;
	low=0;
	high = 9;
	int m;
	scanf("%d",&m);
	while(low <= high ){
		mid= (low + high)/2;
		if(m>a[mid]){
			low = mid + 1;
		}
		else if(m < a[mid]){
			high = mid -1;
		}
		else{
			printf("%d",a[mid]);
			return 0;
		}
	}
	
	return 0;
} 
