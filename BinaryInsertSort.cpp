#include<stdio.h>
int main(){
	int a[15] = {4,8,2,9,3,89,45,87,98,65,23,4644,44946,646446,5646486};
	int i,j,temp,mid,low,high;
	for(i = 1;i<15;i++){
		if(a[i]<a[i-1]){
			temp = a[i];
			low =0;
			 high = i-1;
			while(low<=high){
				mid= (low+high)/2;
				if(temp>a[mid]){
					low = mid +1;	
				}
				else if(temp<a[mid]){
					high = mid -1;
					
				}
			}
			printf("low = %d \n",low);
			for(j = i-1;j>=low;j--){
				a[j+1]=a[j];
			}
			a[low]=temp;
		}
	}
	for(int k=0;k<15;k++) {
		printf("%d ",a[k]);
	}
	return 0;
} 
